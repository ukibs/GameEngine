//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <stdio.h>
//#include <cstdio>
#include <string>

#include "InputManager.h"
#include "ActionManager.h"

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

#undef main

//
bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			//gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

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
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Create the managers
		InputManager::CreateSingleton();
		ActionManager::CreateSingleton();
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
			while (SDL_PollEvent(&e) != 0)
			{
				//Update the inputs
				InputManager::GetInstance().keyboardCheck(e);
			}/*
			//Up test
			if (inputManager.GetKeyPressed("Up")) {
				printf("Key up pressed\n");
			}
			if (inputManager.GetKeyDown("Up")) {
				printf("Key up down\n");
			}
			if (inputManager.GetKeyReleased("Up")) {
				printf("Key up released\n");
			}
			//Down test
			if (inputManager.GetKeyPressed("Down")) {
				printf("Key down pressed\n");
			}
			if (inputManager.GetKeyDown("Down")) {
				printf("Key down down\n");
			}
			if (inputManager.GetKeyReleased("Down")) {
				printf("Key down released\n");
			}*/
		}
	}

	return 0;

}