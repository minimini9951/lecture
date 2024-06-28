#pragma once
#include "cprocessing.h"

extern const int window_width;
extern const int window_height;

enum AliveOrDead
{
	Dead = 0,
	Alive = 1
};

enum PlayerOrCPU
{
	CPU = 0,
	Player = 1
};

enum GroundOrAir
{
	Air = 0,
	Ground = 1
};

struct GameObject
{
	struct Vec2d
	{
		float x;
		float y;
	};

	enum AliveOrDead alive;
	enum PlayerOrCPU player;
	enum PlayerOrCPU grounded;

	struct Vec2d Pos;

	//Velocity X, Y
	struct Vec2d Velocity;

	//Acceleration X,Y
	struct Vec2d Acceleration;


	struct Vec2d Start;
	struct Vec2d Target;


	float accumulatedTime;
	float maxTime;

	float accumulatedLifeSpanTime;
	float maxLifeSpanTime;

	float w;
	float h;

	CP_Color color;

	//Initialize		[X]
	//Draw				[X]
	//Update			[X]
	//Set a random Goal	[X]
	//KillObject		[X]
};

void GameObject_InitializeRandom(struct GameObject* obj, enum AliveOrDead a);
void GameObject_Initialize(struct GameObject* obj,enum AliveOrDead a,
							float  X, float Y, float W, float H,
							CP_Color color);
void GameObject_Draw(const struct GameObject* obj);
void GameObject_Update(struct GameObject* obj);

void GameObject_Movement_Linear(struct GameObject* obj);
void GameObject_Movement_Gravity(struct GameObject* obj);

void GameObject_SetRandomGoal(struct GameObject* obj);

void GameObject_KillObject(struct GameObject* obj);
void GameObject_Jump(struct GameObject* obj, float InitialV);

void GameObject_AddVelocity(struct GameObject* obj, float x, float y);
void GameObject_AddAcceleration(struct GameObject* obj, float x, float y);

struct MemoryPool
{
	int TotalSize;

	struct GameObject* AllObjects;

	//AllocateMemory		[x] 
	//DeallocateMemory x	[x] 
	//InitializeMemory		[x]
	//GetFirstDeadObj		[X]

	//DrawAllObjects		[X]
	//UpdateAllObjects		[X]
};

void MemPool_AllocateMemory(struct MemoryPool* pMemPool,  int size);
void MemPool_DeallocateMemory(struct MemoryPool* pMemPool);
void MemPool_InitializeMemory(struct MemoryPool* pMemPool);

void MemPool_DrawAllObjects(const struct MemoryPool* pMemPool);
void MemPool_UpdateAllObjects(const struct MemoryPool* pMemPool);

void MemPool_DeleteAll(struct MemoryPool* pMemPool);

struct GameObject* MemPool_GetFirstDeadObj(struct MemoryPool* pMemPool);

void MemPool_State_init(void);
void MemPool_State_update(void);
void MemPool_State_exit(void);

extern struct MemoryPool* gMemoryPool;