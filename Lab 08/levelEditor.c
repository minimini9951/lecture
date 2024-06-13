#include "levelEditor.h"
#include "MemPool.h"
#include <stdlib.h>
#include <math.h>

#define MYLEVEL "myLevel.lvl"

const int window_width = 750;
const int window_height = 750;

void SaveVec2dToFile(struct Vec2d vec, FILE* outFile)
{
	fprintf(outFile, "%f %f \n", vec.x, vec.y);
}
void SaveColorToFile(CP_Color col, FILE* outFile)
{
	fprintf(outFile, "%d %d %d %d \n", col.r, col.g, col.b, col.a);
}

enum BufferSize
{
	BUFFERSIZE = 512
};

void LoadIntegerFromFile(int* pi, FILE* inFile)
{
	char str[BUFFERSIZE] = { '\0' };
	fgets(str, BUFFERSIZE, inFile);
	sscanf_s(str, "%d", pi);
}

void LoadFloatFromFile(float* pf, FILE* inFile)
{
	char str[BUFFERSIZE] = { '\0' };
	fgets(str, BUFFERSIZE, inFile);
	sscanf_s(str, "%f", pf);
}

void LoadVec2dFromFile(struct Vec2d* pvec, FILE* inFile)
{
	char str[BUFFERSIZE] = { '\0' };
	fgets(str, BUFFERSIZE, inFile);
	sscanf_s(str, "%f %f", &pvec->x, &pvec->y);
}

void LoadColorFromFile(CP_Color* col, FILE* inFile)
{
	char str[BUFFERSIZE] = { '\0' };
	fgets(str, BUFFERSIZE, inFile);

	int color[4] = { 0 };

	sscanf_s(str, "%d %d %d %d", &color[0], &color[1],
		&color[2], &color[3]);

	for (int i = 0; i < 4; i++)
		col->rgba[i] = (char)color[i];
}

void LoadPlayer(struct GameObject* obj, FILE* inFile)
{
	obj->player = Player;
	//Pos
	LoadVec2dFromFile(&obj->Pos, inFile);
	//Velocity
	LoadVec2dFromFile(&obj->Velocity, inFile);
	//Acceleration
	LoadVec2dFromFile(&obj->Acceleration, inFile);
	//Width
	LoadFloatFromFile(&obj->w, inFile);
	//hight
	LoadFloatFromFile(&obj->h, inFile);

	//Color
	LoadColorFromFile(&obj->color, inFile);
}

void LoadFloor(struct GameObject* obj, FILE* inFile)
{
	obj->player = Floor;
	//Pos
	LoadVec2dFromFile(&obj->Pos, inFile);

	//Width
	LoadFloatFromFile(&obj->w, inFile);
	//hight
	LoadFloatFromFile(&obj->h, inFile);

	//Color
	LoadColorFromFile(&obj->color, inFile);
}

void LoadObject(struct GameObject* obj, FILE* inFile)
{
	obj->player = CPU;
	//Pos
	LoadVec2dFromFile(&obj->Pos, inFile);
	//Velocity
	LoadVec2dFromFile(&obj->Velocity, inFile);
	//Acceleration
	LoadVec2dFromFile(&obj->Acceleration, inFile);
	//Start 
	LoadVec2dFromFile(&obj->Start, inFile);
	//Target
	LoadVec2dFromFile(&obj->Target, inFile);
	//accumulatedTime
	LoadFloatFromFile(&obj->accumulatedTime, inFile);
	//maxTime
	LoadFloatFromFile(&obj->maxTime, inFile);
	//AccumulatedLifeSpanTime
	LoadFloatFromFile(&obj->accumulatedLifeSpanTime, inFile);
	//MaxLifeSpanTime
	LoadFloatFromFile(&obj->maxLifeSpanTime, inFile);
	//Width
	LoadFloatFromFile(&obj->w, inFile);
	//hight
	LoadFloatFromFile(&obj->h, inFile);

	//Color
	LoadColorFromFile(&obj->color, inFile);
}

void SavePlayer(struct GameObject* obj, FILE* outFile)
{
	fprintf(outFile, "- Player \n");

	//Save Pos
	SaveVec2dToFile(obj->Pos, outFile);

	//Save Velocity
	SaveVec2dToFile(obj->Velocity, outFile);
	//Acceleration
	SaveVec2dToFile(obj->Acceleration, outFile);

	//Width
	fprintf(outFile, "%f \n", obj->w);
	//hight
	fprintf(outFile, "%f \n", obj->h);
	//Color
	SaveColorToFile(obj->color, outFile);
}

void SaveFloor(struct GameObject* obj, FILE* outFile)
{
	fprintf(outFile, "- Floor \n");
	//Save Pos
	SaveVec2dToFile(obj->Pos, outFile);

	//Width
	fprintf(outFile, "%f \n", obj->w);
	//hight
	fprintf(outFile, "%f \n", obj->h);
	//Color
	SaveColorToFile(obj->color, outFile);
}

void SaveObject(struct GameObject* obj, FILE* outFile)
{
	fprintf(outFile, "- \n");
	//Save Pos
	SaveVec2dToFile(obj->Pos, outFile);

	//Save Velocity
	SaveVec2dToFile(obj->Velocity, outFile);
	//Acceleration
	SaveVec2dToFile(obj->Acceleration, outFile);
	//Start 
	SaveVec2dToFile(obj->Start, outFile);
	//Target
	SaveVec2dToFile(obj->Target, outFile);

	//accumulatedTime
	fprintf(outFile, "%f \n", obj->accumulatedTime);
	//maxTime
	fprintf(outFile, "%f \n", obj->maxTime);
	//AccumulatedLifeSpanTime
	fprintf(outFile, "%f \n", obj->accumulatedLifeSpanTime);
	//MaxLifeSpanTime
	fprintf(outFile, "%f \n", obj->maxLifeSpanTime);
	//Width
	fprintf(outFile, "%f \n", obj->w);
	//hight
	fprintf(outFile, "%f \n", obj->h);
	//Color
	SaveColorToFile(obj->color, outFile);
}

void CreateLongObject()
{
	static struct GameObject* obj = NULL;
	//Detect if i Press click
	if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT))
	{
		//Create a new object floor
		obj = MemPool_GetFirstDeadObj(gMemoryPool);
		MemPool_InitializeObjectRandom(gMemoryPool, obj, Alive);

		obj->player = Floor;
		obj->color = CP_Color_Create(0, 0, 0, 255);

		obj->Pos.x = CP_Input_GetMouseWorldX();
		obj->Pos.y = CP_Input_GetMouseWorldY();

		obj->w = 0;
		obj->h = 0;

		obj->Start = obj->Pos;
	}

	if (obj == NULL)
		return;

	//While i am holding the click
	if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
	{
		//update the object to be from original click to current
		//Current "target" is the mouse pos
		float currentX = CP_Input_GetMouseWorldX();
		float currentY = CP_Input_GetMouseWorldY();
		CP_Settings_RectMode(CP_POSITION_CENTER);
		//Calculate new center
		//C = (Final - Start) / 2 + Start
		obj->Pos.x = (currentX - obj->Start.x) / 2.0f + obj->Start.x;
		obj->Pos.y = (currentY - obj->Start.y) / 2.0f + obj->Start.y;


		//Calculate new w / h
		obj->w = (currentX - obj->Start.x);
		obj->h = (currentY - obj->Start.y);
	}
	//When I stop holding, dont do anything
	if (CP_Input_MouseReleased(MOUSE_BUTTON_LEFT))
	{
		obj = NULL;
	}
}

void EditGrid()
{
	DeleteFloorTile();

	AddFloorTile();
}

void DeleteFloorTile()
{
	//on right click
	if (CP_Input_MouseDown(MOUSE_BUTTON_RIGHT))
	{
		struct GameObject* collided = MemPool_FloorMouseCollision(gMemoryPool);

		//find collided obj
		if (collided != NULL)
		{
			//kill it
			GameObject_KillObject(collided);
		}
	}
}

void AddFloorTile()
{
	//Depending on which key I press, change the color (object)
	static CP_KEY Lastkey = KEY_1;

	//N1 = black
	if (CP_Input_KeyTriggered(KEY_1))
		Lastkey = KEY_1;
	//N2 = red
	if (CP_Input_KeyTriggered(KEY_2))
		Lastkey = KEY_2;
	//N3 = green
	if (CP_Input_KeyTriggered(KEY_3))
		Lastkey = KEY_3;
	//N4 = blue
	if (CP_Input_KeyTriggered(KEY_4))
		Lastkey = KEY_4;
	//N5 = player
	if (CP_Input_KeyTriggered(KEY_5))
		Lastkey = KEY_5;

	//Define our grid
	//Each tile will be W = WindowWidth/NumberOfTiles
	//Each tile will be H = WindowHigth/NumberOfTiles
	const int NumberOfTiles = 10;

	int TileW = window_width / NumberOfTiles;
	int TileH = window_height / NumberOfTiles;

	//Get mouse pos
	int MouseX = (int)floorf(CP_Input_GetMouseWorldX());
	int MouseY = (int)floorf(CP_Input_GetMouseWorldY());

	//Transform this to a tile coordinate
	int GridCoordX = MouseX / TileW;
	int GridCoordY = MouseY / TileH;

	if (Lastkey == KEY_5 && CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT))
	{
		//Create a player

		struct GameObject* obj = MemPool_GetFirstDeadObj(gMemoryPool);

		if (obj == NULL)
			return;

		MemPool_InitializeObjectRandom(gMemoryPool, obj, Alive);



		obj->player = Player;

		obj->Pos.x = (float)(GridCoordX * TileW + TileW / 2);
		obj->Pos.y = (float)(GridCoordY * TileH + TileH / 2);

		obj->w = (float)TileW;
		obj->h = (float)TileH;
	}

	//When the mouse clicks, create an object on this grid
	if (CP_Input_MouseDown(MOUSE_BUTTON_LEFT))
	{
		if (MemPool_FloorMouseCollision(gMemoryPool) != NULL)
			return;




		CP_Color color;

		switch (Lastkey)
		{
		case KEY_1:
			color = CP_Color_Create(0, 0, 0, 255);
			break;

		case KEY_2:
			color = CP_Color_Create(255, 0, 0, 255);
			break;

		case KEY_3:
			color = CP_Color_Create(0, 255, 0, 255);
			break;

		case KEY_4:
			color = CP_Color_Create(0, 0, 255, 255);
			break;
		default:
			return;
			break;
		}

		struct GameObject* obj = MemPool_GetFirstDeadObj(gMemoryPool);

		if (obj == NULL)
			return;

		MemPool_InitializeObjectRandom(gMemoryPool, obj, Alive);



		obj->player = Floor;
		obj->color = color;

		obj->Pos.x = (float)(GridCoordX * TileW + TileW / 2);
		obj->Pos.y = (float)(GridCoordY * TileH + TileH / 2);

		obj->w = (float)TileW;
		obj->h = (float)TileH;
	}
}

int LoadLevelFromFile(struct MemoryPool* memPool, char* fileName)
{
	//Open the file in read mode
	FILE* inFile = fopen(fileName, "r");
	//Check if the file opened correctly
	if (inFile == NULL)
		return 0;

	char str[BUFFERSIZE] = { '\0' };

	MemPool_DeallocateMemory(memPool);

	//Load the alive objects number = N
	int n = 0;
	LoadIntegerFromFile(&n, inFile);
	//Load the total objects number
	LoadIntegerFromFile(&memPool->TotalSize, inFile);

	//Ensure that the mempool can fit all objects
	MemPool_AllocateMemory(memPool, memPool->TotalSize);
	MemPool_InitializeMemory(memPool);

	//Iterate reading the file, until we read N objects
	int i = 0;
	for (i = 0; i < n; i++)
	{
		// Each object starts with a "-" or "- Player"
		fgets(str, BUFFERSIZE, inFile);

		if (str[0] != '-')
		{
			i--;
			continue;
		}
		//I am a valid object

		struct GameObject* obj = MemPool_GetFirstDeadObj(memPool);
		memPool->AliveObjects++;
		obj->alive = Alive;

		if (strstr(str, "Player") != NULL)
		{
			//Set the player tag
			LoadPlayer(obj, inFile);
		}
		else if (strstr(str, "Floor") != NULL)
		{
			LoadFloor(obj, inFile);
		}
		else
		{
			LoadObject(obj, inFile);
		}

	}

	//Close the file
	fclose(inFile);

	return 1;
}

int SaveLevelToFile(struct MemoryPool* memPool, char* fileName)
{
	//Open file in write mode
	FILE* outFile = fopen(fileName, "w");

	//Check the file was opened correctly
	if (outFile == NULL)
		return 0;

	//Save the total number alive of objects
	fprintf(outFile, "%d \n", memPool->AliveObjects);
	//Save the total number of objects
	fprintf(outFile, "%d \n", memPool->TotalSize);

	//Iterate on the MemoryPool
	for (int i = 0; i < memPool->TotalSize; i++)
	{
		struct GameObject* obj = &memPool->AllObjects[i];

		//Only save alive obj
		if (obj->alive == Dead)
			continue;

		switch (obj->player)
		{
		case Player:
			SavePlayer(obj, outFile);
			break;
		case Floor:
			SaveFloor(obj, outFile);
			break;
		default:
			SaveObject(obj, outFile);
			break;
		}
	}

	//close file
	fclose(outFile);
	return 1;
}
void level_editor_state_init(void)
{
	if (gMemoryPool != NULL)
	{
		MemPool_DeallocateMemory(gMemoryPool);
		free(gMemoryPool);
	}

	gMemoryPool = malloc(sizeof(struct MemoryPool));
	gMemoryPool->AllObjects = NULL;

	//Open a file
	LoadLevelFromFile(gMemoryPool, MYLEVEL);
}

void level_editor_state_update(void)
{
	CP_Color color_white = CP_Color_Create(255, 255, 255, 255);

	CP_Graphics_ClearBackground(color_white);

	if (CP_Input_KeyTriggered(KEY_SPACE))
	{
		struct GameObject* obj = MemPool_GetFirstDeadObj(gMemoryPool);
		if (obj != NULL)
		{
			MemPool_InitializeObjectRandom(gMemoryPool, obj, Alive);
		}
	}

	//CreateLongObject();

	EditGrid();

	MemPool_UpdateAllObjects(gMemoryPool);

	MemPool_DrawAllObjects(gMemoryPool);
}

void level_editor_state_exit(void)
{
	//Save the objects to a file
	SaveLevelToFile(gMemoryPool, MYLEVEL);

	MemPool_DeallocateMemory(gMemoryPool);
	free(gMemoryPool);
	gMemoryPool = NULL;
}
