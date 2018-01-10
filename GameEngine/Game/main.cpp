//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <stdio.h>
#include <cstdlib>
#include <string>

#include "InputManager.h"
#include "ActionManager.h"
#include "RenderManager.h"
#include "ObjectManager.h"
#include "TimerManager.h"
#include "SoundManager.h"
#include "Image.h"
#include "Text.h"
#include "Object.h"
#include "Player.h"
#include "Enemy.h"


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
	Object * walls[4];


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
		//load Music and sound effects
		SoundManager::GetInstance().loadEffect("sound/high.wav","sound_1");
		SoundManager::GetInstance().loadMusic("sound/beat.wav", "music_1");
		SoundManager::GetInstance().play("music_1");
		//create the enemy
		Enemy enemy("obj_enemy", 200, 100, 0, 20, 20);
		RenderManager::GetInstance().addImage("images/manzana.jpg", "img_enemy");
		Image* img_DotE = RenderManager::GetInstance().getImageByName("img_enemy");
		enemy.setImage(img_DotE);
		
		
		//create the player
		Player player("obj_dot", 25, 25, 0, 20, 20);
		

		//create the walls
		walls[0] = new Object("obj_wall1", 0, 0, 0, 640, 20);
		walls[2] = new Object("obj_wall3", 0, 20, 0, 20, 480);
		walls[3] = new Object("obj_wall4", 620, 0, 0, 20, 480);
		walls[1] = new Object("obj_wall2", 0, 460, 0, 640, 20);
		RenderManager::GetInstance().addImage("images/horWall.jpg", "img_horWall");
		Image * img_horWall = RenderManager::GetInstance().getImageByName("img_horWall");
		walls[0]->setImage(img_horWall);
		walls[1]->setImage(img_horWall);
		RenderManager::GetInstance().addImage("images/verWall.jpg", "img_verWall");
		Image * img_verWall = RenderManager::GetInstance().getImageByName("img_verWall");
		walls[2]->setImage(img_verWall);
		walls[3]->setImage(img_verWall);

		//create the fpsCounter
		Text prueba("fjksd", "0", 10, 10, 10, 10, 0, true);
		Text prueba2("prueba2", "1", 100, 100, 0, 0, 0, true);
		float fps = 0.0;

		//create some actions
		ActionManager::GetInstance().addAction("up",0, "w");
		ActionManager::GetInstance().getActionByName("up")->addKey("up");
		ActionManager::GetInstance().addAction("down",0, "s");
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
					
			if (InputManager::GetInstance().checkKey("space")) 
			{
				SoundManager::GetInstance().toggleMusic();
			}

			ActionManager::GetInstance().update();
			ObjectManager::GetInstance().update();
			

			if (player.checkCollision(&enemy,player.x,player.y))
			{
				player.addBody();
				enemy.caught();
				//SoundManager::GetInstance().play("sound_1");
			}
			RenderManager::GetInstance().postUpdate();

			TimerManager::GetInstance().update();
			fps = TimerManager::GetInstance().getFPS();
			prueba.setText(to_string(fps));
			quit = InputManager::GetInstance().checkQuit();
		}
	}
	return 0;
}