#include "cprocessing.h"

void game_init(void)
{
	// initialize variables and CProcessing settings for this gamestate
}

void game_update(void)
{
	// check input, update simulation, render etc.
}

void game_exit(void)
{
	// shut down the gamestate and cleanup any dynamic memory
}

int main(void)
{
	CP_Engine_SetNextGameState(game_init, game_update, game_exit);
	CP_Engine_Run();
	return 0;
}
