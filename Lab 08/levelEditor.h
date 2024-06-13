#pragma once

#include <stdio.h>
#include "MemPool.h"

struct MemoryPool;

void CreateLongObject();

void EditGrid();

void DeleteFloorTile();
void AddFloorTile();

//Load function
int LoadLevelFromFile(struct MemoryPool* memPool, char* fileName);
//Save function
int SaveLevelToFile(struct MemoryPool* memPool, char* fileName);

void SaveVec2dToFile(struct Vec2d vec, FILE* outFile);
void SaveColorToFile(CP_Color col, FILE* outFile);

void LoadIntegerFromFile(int* pi, FILE* inFile);
void LoadFloatFromFile(float* pf, FILE* inFile);
void LoadVec2dFromFile(struct Vec2d* pvec, FILE* inFile);
void LoadColorFromFile(CP_Color* col, FILE* inFile);

void LoadPlayer(struct GameObject* obj, FILE* inFile);
void LoadFloor(struct GameObject* obj, FILE* inFile);
void LoadObject(struct GameObject* obj, FILE* inFile);

void SavePlayer(struct GameObject* obj, FILE* outFile);
void SaveFloor(struct GameObject* obj, FILE* outFile);
void SaveObject(struct GameObject* obj, FILE* outFile);

void level_editor_state_init(void);
void level_editor_state_update(void);
void level_editor_state_exit(void);