#include "main.h"
#include <memory>

float	 g_dt;
double	 g_appTime;

int WINAPI WinMain(HINSTANCE instanceH, HINSTANCE prevInstanceH, LPSTR command_line, int show)
{
	UNREFERENCED_PARAMETER(prevInstanceH);
	UNREFERENCED_PARAMETER(command_line);

	//// Enable run-time memory check for debug builds.
	//#if defined(DEBUG) | defined(_DEBUG)
	//	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	//#endif

	//int * pi = new int;
	////delete pi;


	// Initialize the system
	AESysInit (instanceH, show, 800, 600, 1, 60, false, NULL);

	// Changing the window title
	AESysSetWindowTitle("GSM_Demo");

	//set background color
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);



	//Initialize GSM;	//TODO

	//while(Current Game state != GS_QUIT)	//TODO
	{
		// reset the system modules
		AESysReset();

		// If not restarting, load the gamestate	//TODO
		//if(Current Game state != GS_RESTART)
		{
			//Update Game State
			//Load
		}
		//else
			//Change states to the new state;	//TODO

		// Initialize the gamestate		//TODO Init
		// Initialize state;

		//while(We dont need to change)		//Update and draw /Update until I need to change states
		{
			AESysFrameStart();

			//Update;

			//Draw;
			
			AESysFrameEnd();

			// check if forcing the application to quit
			//if ((AESysDoesWindowExist() == false) || AEInputCheckTriggered(AEVK_ESCAPE))
				//Next state is quit;

			//Increase timers
			g_dt = (f32)AEFrameRateControllerGetFrameTime();
			g_appTime += g_dt;
		}
		
		//Free State;

		//if(If we are not restarting)
			//Unload state;

		//Change state
	}

	// free the system
	AESysExit();
}