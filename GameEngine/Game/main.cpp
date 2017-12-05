//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <stdio.h>
//#include <cstdio>
#include <string>

#include "InputManager.h"
#include "ActionManager.h"
#include "RenderManager.h"
#include "ObjectManager.h"
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
		objManager.addObject("obj_e", 100, 100, 0);
		renderManager.addImage("images/dot1.bmp", "img_e");
		Image* img_DotE = renderManager.getImageByName("img_e");
		objManager.getObjectByName("obj_e")->setImage(img_DotE);
		//create an object
		objManager.addObject("obj_dot",0,0, 0);
		renderManager.addImage("images/dot.bmp", "img_dot");
		Image* img_Dot = renderManager.getImageByName("img_dot");
		objManager.getObjectByName("obj_dot")->setImage(img_Dot);

		

		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		//While application is running
		while (!quit)
		{
			//SDL_PumpEvents();
			//Handle events on queue
			renderManager.preUpdate();
			if (objManager.getObjectByName("obj_dot") != nullptr) {
				if (inputManager.checkKey("d")) {
					objManager.getObjectByName("obj_dot")->x += 1;
				}
				if (inputManager.checkKey("a"))
				{
					objManager.getObjectByName("obj_dot")->x -= 1;
				}
				if (inputManager.checkKey("w"))
				{
					objManager.getObjectByName("obj_dot")->y -= 1;
				}
				if (inputManager.checkKey("s"))
				{
					objManager.getObjectByName("obj_dot")->y += 1;
				}

				if (objManager.getObjectByName("obj_dot")->x > 200 || objManager.getObjectByName("obj_dot")->y > 200)
				{
					objManager.getObjectByName("obj_dot")->x = 0;
					objManager.getObjectByName("obj_dot")->y = 0;
				}
			}
			objManager.update();
			renderManager.postUpdate();
			while (SDL_PollEvent(&e) != 0)
			{
				//Update the inputs
				
				inputManager.keyboardCheck(e);
			}
			
		}
	}

	return 0;

}