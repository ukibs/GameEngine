
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


