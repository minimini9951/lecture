#pragma once
#include "cprocessing.h"

extern const int window_width;
extern const int window_height;

enum AliveOrDead
{
	Dead = 0,
	Alive = 1
};

enum ObjectType
{
	CPU = 0,
	Player = 1,
	Floor = 2
};

enum GroundOrAir
{
	Air = 0,
	Ground = 1
};

struct Vec2d
{
	float x;
	float y;
};

struct GameObject
{
	enum AliveOrDead alive;
	enum ObjectType player;
	enum GroundOrAir grounded;

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
	struct MemoryPool* myPool;
};

void GameObject_Draw(const struct GameObject* obj);
void GameObject_Update(struct GameObject* obj);

void GameObject_Movement_Linear(struct GameObject* obj);
void GameObject_Movement_Gravity(struct GameObject* obj);

void GameObject_SetRandomGoal(struct GameObject* obj);

void GameObject_KillObject(struct GameObject* obj);

void GameObject_Jump(struct GameObject* obj, float InitialV);

int GameObject_MouseIn(struct GameObject* obj);

void GameObject_AddVelocity(struct GameObject* obj, float x, float y);
void GameObject_AddAcceleration(struct GameObject* obj, float x, float y);

struct MemoryPool
{
	int TotalSize;
	int AliveObjects;

	struct GameObject* AllObjects;

	//AllocateMemory		[x] 
	//DeallocateMemory x	[x] 
	//InitializeMemory		[x]
	//GetFirstDeadObj		[X]

	//DrawAllObjects		[X]
	//UpdateAllObjects		[X]
};

void MemPool_InitializeObjectRandom(struct MemoryPool* pmemPool, struct GameObject* obj, enum AliveOrDead a);
void MemPool_InitializeObject(struct MemoryPool* pMemPool, struct GameObject* obj, enum AliveOrDead a,
	float  X, float Y, float W, float H,
	CP_Color color);

void MemPool_AllocateMemory(struct MemoryPool* pMemPool, int size);
void MemPool_DeallocateMemory(struct MemoryPool* pMemPool);
void MemPool_InitializeMemory(struct MemoryPool* pMemPool);


void MemPool_DrawAllObjects(const struct MemoryPool* pMemPool);
void MemPool_UpdateAllObjects(const struct MemoryPool* pMemPool);

void MemPool_DeleteAll(struct MemoryPool* pMemPool);

struct GameObject* MemPool_FloorMouseCollision(struct MemoryPool* pMemPool);

struct GameObject* MemPool_GetFirstDeadObj(struct MemoryPool* pMemPool);

extern struct MemoryPool* gMemoryPool;
