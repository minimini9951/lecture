#include "cprocessing.h"
#include "firework.h"

int main(void)
{
	CP_System_SetWindowSize(window_width, window_height);
	CP_Engine_SetNextGameState(MemPool_State_init, MemPool_State_update, MemPool_State_exit);
	CP_Engine_Run();
	return 0;
}
