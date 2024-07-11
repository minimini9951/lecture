#pragma once

class GSMSTATE
{
public:
	void init();
	void cleanup();

	void pause();
	void resume();

	void handle_events();
	void update();
	void draw();
};

class GSMENGINE
{
	//Have function Pointers to
	//Init
	void init();
	//Load
	//Update
	//Draw
	//Free
	//Unload
	void cleanup();

	//prev state
	//current state
	//next state
	void change_state(GSMSTATE* state);
	void push_state(GSMSTATE* state);
	void pop_state();

	//Function to "ChangeState"
	//Quit
	//Restart
	//Change to a different level

	void handle_state();
	void update();
	void draw();
};
