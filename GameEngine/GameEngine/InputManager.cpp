
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "InputManager.h"
#include "key.h"

InputManager::InputManager() 
{
	init();
	string file = "./Config/keys.txt";
	ifstream keysTxt(file);
	string as, name;
	string sdlString;
	string  line;
	while(getline(keysTxt,line))
	{
		stringstream ss(line);
		getline(ss, sdlString, '\t');
		const char* pointerSdl = name.c_str();
		getline(ss, as, '\t');
		getline(ss, name, '\t');
		SDL_Keycode sdl_key = SDL_GetKeyFromName(pointerSdl); /*SDLK_BACKSPACE;*/
		const char* sdl_name = SDL_GetKeyName(SDLK_BACKSPACE);
		keys.push_back(new key(name, sdl_key, as));
	}
	keysToCheck = new bool[keys.size()];
	for (int i = 0; i < keys.size(); i++)
	{
		keysToCheck[i] = true;
	}
}

void InputManager::keyboardCheck(SDL_Event& e)
{
	int i = 0;
	//for (int i = 0; i < keysToCheck.size; i++)
	for (keysIt = keys.begin(); keysIt != keys.end(); keysIt++)
	{
		if (keysToCheck[i])
		{
			(*keysIt)->updateData(e);
		}
		i++;
	}
}

bool InputManager::init()
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
		//Create window/
		//The window we'll be rendering to
		SDL_Window* gWindow = NULL;

		//The window renderer
		SDL_Renderer* gRenderer = NULL;
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
