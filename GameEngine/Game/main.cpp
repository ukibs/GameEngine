//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <stdio.h>
#include <cstdlib>
#include <string>

#include "EngineManager.h"
#include "SoundManager.h"
#include "GameManager.h"
using namespace Snake;

#undef main
int main(int argc, char* args[])
{
	//Create the managers
	EngineManager::CreateSingleton();
	SoundManager::CreateSingleton();

	//Initialize SDL
	if (!EngineManager::GetInstance().start())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		if (!SoundManager::GetInstance().init())
		{
			printf("Failed to initialize!\n");
		}
		//initialize de gameManager
		GameManager gameManager();	

		//Main loop flag
		bool quit = false;

		//While application is running
		while (!quit)
		{
			//Handle events on queue
			quit = EngineManager::GetInstance().update();
		}
		SoundManager::GetInstance().close();
		EngineManager::GetInstance().close();
	}
	return 0;
}