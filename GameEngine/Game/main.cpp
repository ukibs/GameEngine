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
		ObjectManager::GetInstance().addObject("obj_e", 200, 100, 0, 10, 10);
		RenderManager::GetInstance().addImage("images/dot1.bmp", "img_e");
		Image* img_DotE = RenderManager::GetInstance().getImageByName("img_e");
		ObjectManager::GetInstance().getObjectByName("obj_e")->setImage(img_DotE);
		Object * enemy = ObjectManager::GetInstance().getObjectByName("obj_e");
		
		//create the player
		ObjectManager::GetInstance().addObject("obj_dot",0,0, 0, 10, 10);
		RenderManager::GetInstance().addImage("images/dot.bmp", "img_dot");
		Image* img_Dot = RenderManager::GetInstance().getImageByName("img_dot");
		ObjectManager::GetInstance().getObjectByName("obj_dot")->setImage(img_Dot);
		Object * dot = ObjectManager::GetInstance().getObjectByName("obj_dot");

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
			if (ObjectManager::GetInstance().getObjectByName("obj_dot") != nullptr) {
				if (InputManager::GetInstance().checkKey("d")) {
					ObjectManager::GetInstance().getObjectByName("obj_dot")->x += 1;
				}
				if (InputManager::GetInstance().checkKey("a"))
				{
					ObjectManager::GetInstance().getObjectByName("obj_dot")->x -= 1;
				}
				if (InputManager::GetInstance().checkKey("w"))
				{
					ObjectManager::GetInstance().getObjectByName("obj_dot")->y -= 1;
				}
				if (InputManager::GetInstance().checkKey("s"))
				{
					ObjectManager::GetInstance().getObjectByName("obj_dot")->y += 1;
				}
				if (InputManager::GetInstance().checkKey("space")) {
					SoundManager::GetInstance().toggleMusic();
				}

				if (ObjectManager::GetInstance().getObjectByName("obj_dot")->checkCollision(ObjectManager::GetInstance().getObjectByName("obj_e")))
				{
					ObjectManager::GetInstance().getObjectByName("obj_dot")->x = 0;
					ObjectManager::GetInstance().getObjectByName("obj_dot")->y = 0;
					ObjectManager::GetInstance().getObjectByName("obj_e")->x = rand() % 630;
					ObjectManager::GetInstance().getObjectByName("obj_e")->y = rand() % 470;
					SoundManager::GetInstance().play("sound_1");
				}
			}
			ObjectManager::GetInstance().update();
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