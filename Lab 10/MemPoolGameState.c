#include "MemPoolGameState.h"
#include "cprocessing.h"
#include "stdlib.h"

struct MemoryPool* gMemoryPool = NULL;

void GameObject_InitializeRandom(struct GameObject* obj, enum AliveOrDead a)
{
	if (obj == NULL)
		return;

	float x = CP_Random_RangeFloat(0, (float)window_width);
	float y = CP_Random_RangeFloat(0, (float)window_height);

	float w = CP_Random_RangeFloat(20, 100);
	float h = CP_Random_RangeFloat(20, 100);

	CP_Color color = CP_Color_Create(CP_Random_RangeInt(0, 255),
		CP_Random_RangeInt(0, 255),
		CP_Random_RangeInt(0, 255),
		255);

	GameObject_Initialize(obj, a, x, y, w, h, color);
}

void GameObject_Initialize(struct GameObject* obj, enum AliveOrDead a, float X, float Y, float  W, float H, CP_Color color)
{
	if (obj == NULL)
		return;
	obj->player = CPU;
	obj->player = Air;
	obj->accumulatedLifeSpanTime = 0;
	obj->maxLifeSpanTime = CP_Random_RangeFloat(1.0f, 3.0f);

	obj->alive = a;
	obj->color = color;

	obj->Pos.x = X;
	obj->Pos.y = Y;
	 
	obj->w = W;
	obj->h = H;

	obj->Velocity.x = 0;
	obj->Velocity.y = 0;

	obj->Acceleration.x = 0;
	obj->Acceleration.y = -100;

	GameObject_SetRandomGoal(obj);
}

void GameObject_Draw(const struct GameObject* obj)
{
	if (obj == NULL)
		return;

	CP_Settings_Fill(obj->color);
	CP_Graphics_DrawRect(obj->Pos.x, obj->Pos.y, obj->w, obj->h);
}

void GameObject_Movement_Linear(struct GameObject* obj)
{
	//Want them to move to another point
	obj->Pos.x = (obj->accumulatedTime / obj->maxTime) * (obj->Target.x - obj->Start.x) + obj->Start.x;
	obj->Pos.y = (obj->accumulatedTime / obj->maxTime) * (obj->Target.y - obj->Start.y) + obj->Start.y;

	obj->accumulatedTime += CP_System_GetDt();

	//If they arrive to the other point
	if (obj->accumulatedTime >= obj->maxTime)
	{
		//Set new goal
		GameObject_SetRandomGoal(obj);
	}
}

void GameObject_Update(struct GameObject* obj)
{
	if (obj == NULL)
		return;

	GameObject_Movement_Gravity(obj);

	obj->accumulatedLifeSpanTime += CP_System_GetDt();

	if (obj->accumulatedLifeSpanTime > obj->maxLifeSpanTime && obj->player == CPU)
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
	
	if (obj->Pos.y > 500)
	{
		if (obj->Acceleration.y > 0)
		{
			obj->Velocity.y = obj->Velocity.y - obj->Acceleration.y * t;
			obj->grounded = Air;
		}
		else
		{
			if (obj->grounded == Air)
			{
				obj->Velocity.y = 0;
				obj->grounded = Ground;
			}
		}
	}
	else
	{
		obj->Velocity.y = obj->Velocity.y - obj->Acceleration.y * t;
		obj->grounded = Air;
	}

	//Update my position, depending on the velocity
	obj->Pos.x = obj->Pos.x + obj->Velocity.x * t;
	obj->Pos.y = obj->Pos.y + obj->Velocity.y * t;

	if (obj->Acceleration.x > 0.05f)
		obj->Acceleration.x -= t;
	else if (obj->Acceleration.x < -0.05f)
		obj->Acceleration.x += t;
	else
		obj->Acceleration.x = 0;

	if (obj->Velocity.x > 0.05f)
		obj->Velocity.x -= t;
	else if (obj->Velocity.x < -0.05f)
		obj->Velocity.x += t;
	else
		obj->Velocity.x = 0;




}

void GameObject_SetRandomGoal(struct GameObject* obj)
{
	if (obj == NULL)
		return;

	//Create 2 random floats inside the window
	//Set the target to them
	obj->Target.x = CP_Random_RangeFloat(0.0f, (float)window_width);
	obj->Target.y = CP_Random_RangeFloat(0.0f, (float)window_height);
	
	obj->Start.x = obj->Pos.x;
	obj->Start.y = obj->Pos.y;

	//Set the timer to 0
	obj->accumulatedTime = 0;

	//Sets the max time to random
	obj->maxTime = CP_Random_RangeFloat(2.f, 5.f);
}

void GameObject_KillObject(struct GameObject* obj)
{
	if (obj == NULL)
		return;

	obj->alive = Dead;
}

void GameObject_Jump(struct GameObject* obj, float InitialV)
{
	if (obj->grounded)
	{
		obj->Velocity.y = -InitialV;
	}
}

void GameObject_AddVelocity(struct GameObject* obj, float x, float y)
{
	obj->Velocity.x += x;
	obj->Velocity.y += y;
}

void GameObject_AddAcceleration(struct GameObject* obj, float x, float y)
{
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

	if(pMemPool->AllObjects != NULL)
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
		if(pMemPool->AllObjects[i].alive == Alive)
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

	gMemoryPool = malloc(sizeof(struct MemoryPool));
	gMemoryPool->AllObjects = NULL;

	MemPool_AllocateMemory(gMemoryPool, 5);
	MemPool_InitializeMemory(gMemoryPool);

	//Create the player
	GameObject_InitializeRandom(MemPool_GetFirstDeadObj(gMemoryPool), Alive);
	gMemoryPool->AllObjects[0].player = Player;
}

void MemPool_State_update(void)
{
	CP_Color color_white = CP_Color_Create(255, 255, 255, 255);

	CP_Graphics_ClearBackground(color_white);

	if (CP_Input_KeyTriggered(KEY_R))
	{
		CP_Engine_SetNextGameStateForced(MemPool_State_init, MemPool_State_update, MemPool_State_exit);
	}
	if (CP_Input_KeyTriggered(KEY_SPACE))
	{
		struct GameObject* obj = MemPool_GetFirstDeadObj(gMemoryPool);
		if (obj != NULL)
		{
			GameObject_InitializeRandom(obj, Alive);
		}
	}
	if (CP_Input_KeyTriggered(KEY_DELETE))
	{
		MemPool_DeleteAll(gMemoryPool);
	}

	//Get Input W
	if (CP_Input_KeyTriggered(KEY_W))
	{
		float InitialV = 50;

		GameObject_Jump(&gMemoryPool->AllObjects[0], InitialV);
	}
	//Get Input A
	if (CP_Input_KeyDown(KEY_A))
	{
		//Move Left
		GameObject_AddVelocity(&gMemoryPool->AllObjects[0], -5, 0);
	}
	//Get Input D
	if (CP_Input_KeyDown(KEY_D))
	{
		//Move Right
		GameObject_AddVelocity(&gMemoryPool->AllObjects[0], 5, 0);
	}


	MemPool_UpdateAllObjects(gMemoryPool);

	MemPool_DrawAllObjects(gMemoryPool);
}

void MemPool_State_exit(void)
{
	MemPool_DeallocateMemory(gMemoryPool);
	free(gMemoryPool);
	gMemoryPool = NULL;
}
