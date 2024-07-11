#include "BaseLevel.h"

void GSM::GSM::Init()
{
	if (currentLevel != nullptr)
	{
		currentLevel->Init();
	}
}

void GSM::GSM::Update()
{
	if (currentLevel != nullptr)
	{
		currentLevel->Update();
	}
}

void GSM::GSM::Exit()
{
	if (currentLevel != nullptr)
	{
		currentLevel->Exit();
	}
}
