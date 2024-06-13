#include "cprocessing.h"
#include "levelEditor.h"

int main(void)
{
	CP_Engine_SetNextGameState(level_editor_state_init, level_editor_state_update, level_editor_state_exit);
	CP_Engine_Run();
	return 0;
}
