
#include <list>
#include <SDL.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "InputManager.h"
#include "key.h"

InputManager::InputManager() 
{
	string file = "keys.txt";
	ifstream keysTxt(file);
	string as, name;
	SDL_Keycode sdl;
	for (int i = 0; i < 27; i++)
	{
		keysTxt >> sdl;
		keysTxt >> as;
		getline(keysTxt, name);
		keys.push_back(new key(name, sdl, as));
	}
	for (int i = 0; i < 27; i++)
	{
		keysToCheck[i] = false;
	}
}

vector <key> InputManager::keyboardCheck(SDL_Event& e)
{
	int i = 0;
	//for (int i = 0; i < keysToCheck.size; i++)
	for (keysIt = keys.begin; keysIt != keys.end; keysIt++)
	{
		if (keysToCheck[i])
		{
			(*keysIt)->updateData(e);
		}
		i++;
	}
}
