#include "cprocessing.h"
#include "Collision.h"
#include "math.h"

struct AABB aabb1;
struct AABB aabb2;
CP_Color color1;
CP_Color color2;
CP_Color red;

// use CP_Engine_SetNextGameState to specify this function as the initialization function
// this function will be called once at the beginning of the program
void game_init(void)
{
	// initialize variables and CProcessing settings for this gamestate
	color1 = CP_Color_Create(CP_Random_RangeInt(0, 255), CP_Random_RangeInt(0, 255), CP_Random_RangeInt(0, 255), 255);
	color2 = CP_Color_Create(CP_Random_RangeInt(0, 255), CP_Random_RangeInt(0, 255), CP_Random_RangeInt(0, 255), 255);
	red = CP_Color_Create(255, 0, 0, 255);
}

// use CP_Engine_SetNextGameState to specify this function as the update function
// this function will be called repeatedly every frame
void game_update(void)
{
	CP_Color black = CP_Color_Create(0, 0, 0, 255);
	CP_Graphics_ClearBackground(black);

	if (CP_Input_MouseTriggered(MOUSE_BUTTON_LEFT))
	{
		aabb1.min.x = CP_Input_GetMouseX();
		aabb1.min.y = CP_Input_GetMouseY();
		aabb1.count = 0;
	}
	if (CP_Input_MouseReleased(MOUSE_BUTTON_LEFT))
	{
		aabb1.max.x = CP_Input_GetMouseX();
		aabb1.max.y = CP_Input_GetMouseY();
		aabb1.width = fabsf(aabb1.max.x - aabb1.min.x);
		aabb1.height = fabsf(aabb1.max.y - aabb1.min.y);
		aabb1.count = 1;
	}
	if (aabb1.count)
	{
		CP_Settings_Fill(color1);
		CP_Graphics_DrawRect(aabb1.min.x, aabb1.min.y, aabb1.width, aabb1.height);
	}
	if (CP_Input_MouseTriggered(MOUSE_BUTTON_RIGHT))
	{
		aabb2.min.x = CP_Input_GetMouseX();
		aabb2.min.y = CP_Input_GetMouseY();
		aabb2.count = 0;
	}
	if (CP_Input_MouseReleased(MOUSE_BUTTON_RIGHT))
	{
		aabb2.max.x = CP_Input_GetMouseX();
		aabb2.max.y = CP_Input_GetMouseY();
		aabb2.width = fabsf(aabb2.max.x - aabb2.min.x);
		aabb2.height = fabsf(aabb2.max.y - aabb2.min.y);
		aabb2.count = 1;
	}
	if (aabb2.count)
	{
		CP_Settings_Fill(color2);
		CP_Graphics_DrawRect(aabb2.min.x, aabb2.min.y, aabb2.width, aabb2.height);
	}
	if (aabb1.count && aabb2.count && CollisionIntersection_RectRect(&aabb1, &aabb2))
	{
		CP_Settings_Fill(red);
		struct AABB aabb3 = intersection(&aabb1, &aabb2);
		CP_Graphics_DrawRect(aabb3.min.x, aabb3.min.y, aabb3.width, aabb3.height);

	}
}

// use CP_Engine_SetNextGameState to specify this function as the exit function
// this function will be called once just before leaving the current gamestate
void game_exit(void)
{
	// shut down the gamestate and cleanup any dynamic memory
}

// main() the starting point for the program
// CP_Engine_SetNextGameState() tells CProcessing which functions to use for init, update and exit
// CP_Engine_Run() is the core function that starts the simulation
int main(void)
{
	CP_Engine_SetNextGameState(game_init, game_update, game_exit);
	CP_Engine_Run();
	return 0;
}
