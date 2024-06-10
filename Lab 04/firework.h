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

struct Vec2d
{
	float x;
	float y;
};

struct GameObject
{
	enum AliveOrDead alive;

	struct Vec2d Pos;

	struct Vec2d Velocity;

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
};

void GameObject_InitializeRandom(struct GameObject* obj, enum AliveOrDead a);
void GameObject_Initialize(struct GameObject* obj, enum AliveOrDead a,
	float  X, float Y,
	CP_Color color);
void GameObject_Draw(const struct GameObject* obj);
void GameObject_Update(struct GameObject* obj);

void GameObject_Movement_Gravity(struct GameObject* obj);


void GameObject_KillObject(struct GameObject* obj);

void GameObject_AddVelocity(struct GameObject* obj, float x, float y);
void GameObject_AddAcceleration(struct GameObject* obj, float x, float y);

enum Emmiter
{
	NotActive = 0,
	Active = 1
};
struct MemoryPool
{
	int TotalSize;

	struct GameObject* AllObjects;

	enum Emmiter active;
};

void MemPool_AllocateMemory(struct MemoryPool* pMemPool, int size);
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
extern struct MemoryPool* gMemoryPool2;