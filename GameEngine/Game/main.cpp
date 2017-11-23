//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <stdio.h>
//#include <cstdio>
#include <string>

#include "InputManager.h"
#include "ActionManager.h"
#include "RenderManager.h"

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
	//Initialize SDL
	RenderManager::CreateSingleton();
	InputManager::CreateSingleton();
	ActionManager::CreateSingleton();
	if (!RenderManager::GetInstance().init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Create the managers
		
		//And lets put some inputs

		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		//While application is running
		while (!quit)
		{
			//SDL_PumpEvents();
			//Handle events on queue
			RenderManager::GetInstance().addImage("images/dot.bmp");
			while (SDL_PollEvent(&e) != 0)
			{
				//Update the inputs
				RenderManager::GetInstance().update();
				InputManager::GetInstance().keyboardCheck(e);
			}
		}
	}

	return 0;

}