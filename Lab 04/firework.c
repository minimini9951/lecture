#include "cprocessing.h"
#include "firework.h"
#include "stdlib.h"

struct MemoryPool* gMemoryPool = NULL;
struct MemoryPool* gMemoryPool2 = NULL;
const int window_width = 750;
const int window_height = 750;

void GameObject_InitializeRandom(struct GameObject* obj, enum AliveOrDead a)

{
	if (obj == NULL)
		return;

	float x = (float)window_width / 2;
	float y = (float)window_height;

	CP_Color color = CP_Color_Create(CP_Random_RangeInt(0, 255),
		CP_Random_RangeInt(0, 255),
		CP_Random_RangeInt(0, 255),
		255);

	GameObject_Initialize(obj, a, x, y, color);
}

void GameObject_Initialize(struct GameObject* obj, enum AliveOrDead a, float X, float Y, CP_Color color)
{
	if (obj == NULL)
		return;
	obj->accumulatedLifeSpanTime = 0;
	obj->maxLifeSpanTime = CP_Random_RangeFloat(1.0f, 5.0f);

	obj->alive = a;
	obj->color = color;

	obj->Pos.x = X;
	obj->Pos.y = Y;

	obj->Velocity.x = 0;
	obj->Velocity.y = 0;

	obj->Acceleration.x = 0;
	obj->Acceleration.y = -100;
}

void GameObject_Draw(const struct GameObject* obj)
{
	if (obj == NULL)
		return;

	CP_Settings_Fill(obj->color);
	CP_Graphics_DrawCircle(obj->Pos.x, obj->Pos.y, 10);
}

void GameObject_Update(struct GameObject* obj)
{
	if (obj == NULL)
		return;

	GameObject_Movement_Gravity(obj);

	obj->accumulatedLifeSpanTime += CP_System_GetDt();

	if (obj->accumulatedLifeSpanTime > obj->maxLifeSpanTime)
	{
		GameObject_KillObject(obj);
	}

	//GameObject_Movement_Linear(obj);
}

void GameObject_Movement_Gravity(struct GameObject* obj)
{
	float t = CP_System_GetDt();

	//Update my velocity, depending on the acceleration
	obj->Velocity.x = obj->Velocity.x + obj->Acceleration.x * t;

	if (obj->Acceleration.y > 0)
	{
		obj->Velocity.y = obj->Velocity.y - obj->Acceleration.y * t;
	}
	else
	{
		obj->Velocity.y = obj->Velocity.y - obj->Acceleration.y * t;

	}

	//Update my position, depending on the velocity
	obj->Pos.x = obj->Pos.x + obj->Velocity.x * t;
	obj->Pos.y = obj->Pos.y + obj->Velocity.y * t;
}

void GameObject_KillObject(struct GameObject* obj)
{
	if (obj == NULL)
		return;

	obj->alive = Dead;
}

void GameObject_AddVelocity(struct GameObject* obj, float x, float y)
{
	if (obj == NULL)
		return;

	obj->Velocity.x += x;
	obj->Velocity.y += y;
}

void GameObject_AddAcceleration(struct GameObject* obj, float x, float y)
{
	if (obj == NULL)
		return;

	obj->Acceleration.x += x;
	obj->Acceleration.y += y;
}
void MemPool_AllocateMemory(struct MemoryPool* pMemPool, int size)
{
	if (pMemPool == NULL)
		return;

	MemPool_DeallocateMemory(pMemPool);

	pMemPool->TotalSize = size;
	pMemPool->AllObjects = malloc(size * sizeof(struct GameObject));
}

void MemPool_DeallocateMemory(struct MemoryPool* pMemPool)
{
	if (pMemPool == NULL)
		return;

	pMemPool->TotalSize = 0;

	if (pMemPool->AllObjects != NULL)
		free(pMemPool->AllObjects);

	pMemPool->AllObjects = NULL;
}

void MemPool_InitializeMemory(struct MemoryPool* pMemPool)
{
	if (pMemPool == NULL)
		return;

	int i = 0;
	for (i = 0; i < pMemPool->TotalSize; i++)
	{
		GameObject_InitializeRandom(&pMemPool->AllObjects[i], Dead);
	}
}

void MemPool_DrawAllObjects(const struct MemoryPool* pMemPool)
{
	if (pMemPool == NULL)
		return;

	int i = 0;
	for (i = 0; i < pMemPool->TotalSize; i++)
	{
		if (pMemPool->AllObjects[i].alive == Alive)
			GameObject_Draw(&pMemPool->AllObjects[i]);
	}
}

void MemPool_UpdateAllObjects(const struct MemoryPool* pMemPool)
{
	if (pMemPool == NULL)
		return;

	int i = 0;
	for (i = 0; i < pMemPool->TotalSize; i++)
	{
		if (pMemPool->AllObjects[i].alive == Alive)
		{
			GameObject_Update(&pMemPool->AllObjects[i]);
		}
	}
}

void MemPool_DeleteAll(struct MemoryPool* pMemPool)
{
	if (pMemPool == NULL)
		return;
	int i = 0;
	for (i = 0; i < pMemPool->TotalSize; i++)
		GameObject_KillObject(&pMemPool->AllObjects[i]);
}

struct GameObject* MemPool_GetFirstDeadObj(struct MemoryPool* pMemPool)
{
	if (pMemPool == NULL)
		return NULL;

	if (pMemPool->active == NotActive)
	{
		return NULL;
	}

	int i = 0;
	for (i = 0; i < pMemPool->TotalSize; i++)
	{
		if (pMemPool->AllObjects[i].alive == Dead)
		{
			return &pMemPool->AllObjects[i];
		}
	}

	return NULL;
}

void MemPool_State_init(void)
{
	if (gMemoryPool != NULL)
	{
		MemPool_DeallocateMemory(gMemoryPool);
		free(gMemoryPool);
	}

	if (gMemoryPool2 != NULL)
	{
		MemPool_DeallocateMemory(gMemoryPool2);
		free(gMemoryPool2);
	}

	gMemoryPool = malloc(sizeof(struct MemoryPool));
	gMemoryPool->AllObjects = NULL;

	gMemoryPool2 = malloc(sizeof(struct MemoryPool));
	gMemoryPool2->AllObjects = NULL;

	MemPool_AllocateMemory(gMemoryPool, 100);
	MemPool_InitializeMemory(gMemoryPool);

	MemPool_AllocateMemory(gMemoryPool2, 100);
	MemPool_InitializeMemory(gMemoryPool2);

	gMemoryPool->active = Active;
	gMemoryPool2->active = NotActive;
}

void MemPool_State_update(void)
{
	CP_Color color_white = CP_Color_Create(255, 255, 255, 255);

	CP_Graphics_ClearBackground(color_white);

	struct GameObject* obj = MemPool_GetFirstDeadObj(gMemoryPool);
	struct GameObject* obj2 = MemPool_GetFirstDeadObj(gMemoryPool2);

	if (obj != NULL)
	{
		GameObject_InitializeRandom(obj, Alive);
		GameObject_AddVelocity(obj, 0, -300);
	}

	//Iterate and find if any particle 1 has velocity.y > 0
	for(int i = 0; i < gMemoryPool->TotalSize; i++)
	{
		//Activate the other particles 2
		//Do not summon more particles 1
		if (gMemoryPool->AllObjects[i].alive == Alive && gMemoryPool->AllObjects[i].Velocity.y > 0 && gMemoryPool->active == Active)
		{
			gMemoryPool->active = NotActive;
			gMemoryPool2->active = Active;
			for (int j = 0; j < gMemoryPool2->TotalSize; j++)
			{
				obj2 = MemPool_GetFirstDeadObj(gMemoryPool2);
				GameObject_InitializeRandom(obj2, Alive);
				float x_num = CP_Random_RangeFloat(-1, 1);
				float y_num = CP_Random_RangeFloat(-1, 1);
				float length = CP_Random_RangeFloat(0, 200);
				obj2->Pos.x = gMemoryPool->AllObjects[i].Pos.x;
				obj2->Pos.y = gMemoryPool->AllObjects[i].Pos.y;
				GameObject_AddVelocity(obj2, x_num * length, y_num * length);
			}
		}
	}

	MemPool_UpdateAllObjects(gMemoryPool);
	MemPool_DrawAllObjects(gMemoryPool);

	MemPool_UpdateAllObjects(gMemoryPool2);
	MemPool_DrawAllObjects(gMemoryPool2);
}

void MemPool_State_exit(void)
{
	MemPool_DeallocateMemory(gMemoryPool);
	free(gMemoryPool);
	gMemoryPool = NULL;
}
