//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <stdio.h>
#include <cstdlib>
//#include <cstdio>
#include <string>

#include "InputManager.h"
#include "ActionManager.h"
#include "RenderManager.h"
#include "ObjectManager.h"
#include "SoundManager.h"
#include "Image.h"
#include "Object.h"
#undef main

//

//
bool loadMedia() {
	bool success = true;


	return success;
}

//
void close() {

}


#undef main
int main(int argc, char* args[])
{
	//Create the managers
	ObjectManager::CreateSingleton();
	RenderManager::CreateSingleton();
	InputManager::CreateSingleton();
	ActionManager::CreateSingleton();
	ColliderManager::CreateSingleton();
	//SoundManager::CreateSingleton();
	ObjectManager objManager = ObjectManager::GetInstance();
	RenderManager renderManager = RenderManager::GetInstance();
	InputManager inputManager = InputManager::GetInstance();
	ActionManager actionManager = ActionManager::GetInstance();
	//Initialize SDL
	if (!RenderManager::GetInstance().init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
	
		//And lets put some inputs
		ObjectManager::GetInstance().addObject("obj_e", 200, 100, 0, 10, 10);
		RenderManager::GetInstance().addImage("images/dot1.bmp", "img_e");
		Image* img_DotE = RenderManager::GetInstance().getImageByName("img_e");
		ObjectManager::GetInstance().getObjectByName("obj_e")->setImage(img_DotE);
		Object * enemy = ObjectManager::GetInstance().getObjectByName("obj_e");
		
		//create an object
		ObjectManager::GetInstance().addObject("obj_dot",0,0, 0, 10, 10);
		RenderManager::GetInstance().addImage("images/dot.bmp", "img_dot");
		Image* img_Dot = RenderManager::GetInstance().getImageByName("img_dot");
		ObjectManager::GetInstance().getObjectByName("obj_dot")->setImage(img_Dot);
		Object * dot = ObjectManager::GetInstance().getObjectByName("obj_dot");

		

		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		//While application is running
		while (!quit)
		{
			//SDL_PumpEvents();
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

				if (ObjectManager::GetInstance().getObjectByName("obj_dot")->checkCollision(ObjectManager::GetInstance().getObjectByName("obj_e")))
				{
					ObjectManager::GetInstance().getObjectByName("obj_dot")->x = 0;
					ObjectManager::GetInstance().getObjectByName("obj_dot")->y = 0;
					ObjectManager::GetInstance().getObjectByName("obj_e")->x = rand() % 630;
					ObjectManager::GetInstance().getObjectByName("obj_e")->y = rand() % 470;
					//SoundManager::GetInstance().play();
				}
			}
			ObjectManager::GetInstance().update();
			RenderManager::GetInstance().postUpdate();
			while (SDL_PollEvent(&e) != 0)
			{
				//Update the inputs
				
				InputManager::GetInstance().keyboardCheck(e);
			}
			
		}
	}

	return 0;

}