//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <stdio.h>
#include <cstdlib>
#include <string>

// Engine ones
#include "InputManager.h"
#include "ActionManager.h"
#include "RenderManager.h"
#include "ObjectManager.h"
#include "TimerManager.h"
#include "SoundManager.h"
#include "Image.h"
#include "Text.h"
#include "Object.h"

//Game ones
#include "PlayerShip.h"
#include "EnemyShip.h"
#include "GameManager.h"
using namespace VerticalShooter;

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

	//variables


	//Initialize SDL
	if (!RenderManager::GetInstance().init() || !SoundManager::GetInstance().init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		
		GameManager gameManager("GameManager", 0, 0, 0, 0);

		//create some actions
		ActionManager::GetInstance().addAction("up", "w");
		ActionManager::GetInstance().getActionByName("up")->addKey("up");
		ActionManager::GetInstance().addAction("down", "s");
		ActionManager::GetInstance().getActionByName("down")->addKey("down");
		ActionManager::GetInstance().addAction("left", "a");
		ActionManager::GetInstance().getActionByName("left")->addKey("left");
		ActionManager::GetInstance().addAction("right", "d");
		ActionManager::GetInstance().getActionByName("right")->addKey("right");
		ActionManager::GetInstance().addAction("shoot", "space");

		//Main loop flag
		bool quit = false;

		//While application is running
		while (!quit)
		{
			//Handle events on queue
			RenderManager::GetInstance().preUpdate();

			ActionManager::GetInstance().update();
			quit = InputManager::GetInstance().checkQuit();
			ObjectManager::GetInstance().update();

			//playerShip.update();
			RenderManager::GetInstance().postUpdate();

			TimerManager::GetInstance().update();
		}
	}
	return 0;
}