#pragma once

namespace GSM
{
	class BaseLevel
	{
		char* name;
	public:
		BaseLevel();
		BaseLevel(const char* name);
		~BaseLevel();

		virtual void Init();
		virtual void Update();
		virtual void Exit();
	};

	class GSM
	{
		BaseLevel* currentLevel = nullptr;
	public:
		//Init
		void Init();
		//Update
		void Update();
		//Exit
		void Exit();

	};

	class MainMenuLevel : public BaseLevel
	{
		//
	public:
		void Init() override;
		void Update() override;
		void Exit() override;
	};
}