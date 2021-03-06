//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <stdio.h>
#include <cstdlib>
#include <string>

#include "EngineManager.h"
#include "SoundManager.h"

#include "JumpMan.h"
#include "Item.h"
#include "GameManager.h"
using namespace Platform;
#undef main
int main(int argc, char* args[])
{
	//Create the managers
	ObjectManager::CreateSingleton();
	RenderManager::CreateSingleton();
	InputManager::CreateSingleton();
	ActionManager::CreateSingleton();
	ColliderManager::CreateSingleton();
	TimerManager::CreateSingleton();
	SoundManager::CreateSingleton();

	//Initialize SDL
	if (!RenderManager::GetInstance().init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		if (!SoundManager::GetInstance().init())
		{
			printf("Failed to initialize!\n");
		}
		
		//create the fpsCounter
		float fps = 0.0;

		//create some actions
		ActionManager::GetInstance().addAction("up", "w");
		ActionManager::GetInstance().getActionByName("up")->addKey("up");
		ActionManager::GetInstance().addAction("down", "s");
		ActionManager::GetInstance().getActionByName("down")->addKey("down");
		ActionManager::GetInstance().addAction("left", "a");
		ActionManager::GetInstance().getActionByName("left")->addKey("left");
		ActionManager::GetInstance().addAction("right", "d");
		ActionManager::GetInstance().getActionByName("right")->addKey("right");

		SoundManager::GetInstance().loadEffect("sound/high.wav", "sound_1");

		//Main loop flag
		bool quit = false;

		//While application is running
		while (!quit)
		{
			//Handle events on queue
			RenderManager::GetInstance().preUpdate();
			ActionManager::GetInstance().update();
			ObjectManager::GetInstance().update();
			RenderManager::GetInstance().postUpdate();

			TimerManager::GetInstance().update();
			fps = TimerManager::GetInstance().getFPS();
			quit = InputManager::GetInstance().checkQuit();
		}
	}
	return 0;
}