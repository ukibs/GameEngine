//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <stdio.h>
#include <cstdlib>
#include <string>

// Engine ones
#include "EngineManager.h"
#include "SoundManager.h"

//Game ones
#include "GameManager.h"

using namespace VerticalShooter;

#undef main
int main(int argc, char* args[])
{
	// Create the managers
	EngineManager::CreateSingleton();
	SoundManager::CreateSingleton();
	
	// Initialize SDL
	if (!EngineManager::GetInstance().start() || !SoundManager::GetInstance().init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		
		
		//create some actions
			// Movement ones
		ActionManager::GetInstance().addAction("up", "w");
		ActionManager::GetInstance().getActionByName("up")->addKey("up");
		ActionManager::GetInstance().addAction("down", "s");
		ActionManager::GetInstance().getActionByName("down")->addKey("down");
		ActionManager::GetInstance().addAction("left", "a");
		ActionManager::GetInstance().getActionByName("left")->addKey("left");
		ActionManager::GetInstance().addAction("right", "d");
		ActionManager::GetInstance().getActionByName("right")->addKey("right");
			// Action ones
		ActionManager::GetInstance().addAction("shoot", "space");
		ActionManager::GetInstance().addAction("accept", "return");
		ActionManager::GetInstance().addAction("quit", "escape");

		//Main loop flag
		bool quit = false;

		//While application is running
		while (!quit)
		{
			quit = EngineManager::GetInstance().update();
		}

		//Close everything
		SoundManager::GetInstance().close();
		EngineManager::GetInstance().close();
	}
	return 0;
}