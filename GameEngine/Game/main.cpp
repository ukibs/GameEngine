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
		Enemy enemy("obj_enemy", 200, 100, 0, 10, 10);
		ObjectManager::GetInstance().addObject(&enemy);
		RenderManager::GetInstance().addImage("images/dot1.bmp", "img_enemy");
		Image* img_DotE = RenderManager::GetInstance().getImageByName("img_enemy");
		enemy.setImage(img_DotE);
		
		
		//create the player
		Player player("obj_dot", 0, 0, 0, 10, 10);
		ObjectManager::GetInstance().addObject(&player);
		RenderManager::GetInstance().addImage("images/dot.bmp", "img_dot");
		Image* img_Dot = RenderManager::GetInstance().getImageByName("img_dot");
		player.setImage(img_Dot);

		//create the fpsCounter
		ObjectManager::GetInstance().addObject("fpsCounter", 0, 0, 0, 0, 0);
		RenderManager::GetInstance().addText("0","fps");
		Text* fpsText = RenderManager::GetInstance().getTextByName("fps");
		ObjectManager::GetInstance().getObjectByName("fpsCounter")->setText(fpsText);
		Object * fpsCounter = ObjectManager::GetInstance().getObjectByName("fpsCounter");
		float fps = 0.0;

		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		//While application is running
		while (!quit)
		{
			//Handle events on queue
			RenderManager::GetInstance().preUpdate();
					
				if (InputManager::GetInstance().checkKey("space")) {
					SoundManager::GetInstance().toggleMusic();
				}
		
			ObjectManager::GetInstance().update();
			if (player.checkCollision(&enemy))
			{
				player.x = 0;
				player.y = 0;
				enemy.caught();
				SoundManager::GetInstance().play("sound_1");
			}
			RenderManager::GetInstance().postUpdate();
			while (SDL_PollEvent(&e) != 0)
			{
				//Update the inputs
				if (e.type == SDL_QUIT) {
					quit = true;
				}
				else if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
					InputManager::GetInstance().keyboardCheck(e);
				}
			}
			TimerManager::GetInstance().update();
			fps = TimerManager::GetInstance().getFPS();
			fpsCounter->text.setText(to_string(fps));
		}
	}

	return 0;

}