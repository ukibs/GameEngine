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
		// the image for the player
		//RenderManager::GetInstance().addImage("images/PlayerShip.png", "PlayerShip");
		//Image* img_player = RenderManager::GetInstance().getImageByName("PlayerShip");
		
		// create the player
		PlayerShip playerShip("PlayerShip", 200, 200, 45, 37);
		ObjectManager::GetInstance().getObjectByName("PlayerShip")->addImage("images/PlayerShip.png", "PlayerShip");


		//create the walls
		RenderManager::GetInstance().addImage("images/plt_40_20.png", "img_plt");
		
		//create the fpsCounter
		ObjectManager::GetInstance().addObject("fpsCounter", 0, 0, 0, 0, 0);
		RenderManager::GetInstance().addText("0", "fps");
		Text* fpsText = RenderManager::GetInstance().getTextByName("fps");
		ObjectManager::GetInstance().getObjectByName("fpsCounter")->setText(fpsText);
		Object * fpsCounter = ObjectManager::GetInstance().getObjectByName("fpsCounter");
		float fps = 0.0;

		//create some actions
		ActionManager::GetInstance().addAction("up", 0, "w");
		ActionManager::GetInstance().getActionByName("up")->addKey("up");
		ActionManager::GetInstance().addAction("down", 0, "s");
		ActionManager::GetInstance().getActionByName("down")->addKey("down");
		ActionManager::GetInstance().addAction("left", 0, "a");
		ActionManager::GetInstance().getActionByName("left")->addKey("left");
		ActionManager::GetInstance().addAction("right", 0, "d");
		ActionManager::GetInstance().getActionByName("right")->addKey("right");

		//Main loop flag
		bool quit = false;

		//While application is running
		while (!quit)
		{
			//Handle events on queue
			RenderManager::GetInstance().preUpdate();

			ActionManager::GetInstance().update();
			ObjectManager::GetInstance().update();

			//playerShip.update();
			RenderManager::GetInstance().postUpdate();

			TimerManager::GetInstance().update();
			fps = TimerManager::GetInstance().getFPS();
			fpsCounter->text.setText(to_string(fps));
		}
	}
	return 0;
}