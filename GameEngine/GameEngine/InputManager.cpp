
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
		getline(ss, name, ' ');
		SDL_Keycode sdl_key = SDL_GetKeyFromName(pointerSdl);
		if (sdl_key == 0) {
			cout << "no coge: ";
		}
		else {
			cout << "si coge: ";
		}
		cout << sdlString << " " << as << " " << name << " " << pointerSdl << "\n";
		keys.push_back(new key(name, sdl_key, as));
	}
	keysToCheck = new bool[keys.size()];
	for (int i = 0; i < keys.size(); i++)
	{
		keysToCheck[i] = false;
	}
}

void InputManager::keyboardCheck()
{
	while (SDL_PollEvent(&e) != 0)
	{
		int i = 0;
		for (keysIt = keys.begin(); keysIt != keys.end(); keysIt++)
		{
			if (keysToCheck[i])
			{
				(*keysIt)->updateData(e);
			}
			i++;
		}
	}
}

bool InputManager::checkKey(string name)
{
	for (keysIt = keys.begin(); keysIt != keys.end(); keysIt++) 
	{
		if ((*keysIt)->getName() == name) 
		{
			return (*keysIt)->getDown();
		}
	}
	return false;
}

key * InputManager::getKey(string name)
{
	for (keysIt = keys.begin(); keysIt != keys.end(); keysIt++)
	{
		if ((*keysIt)->getName() == name)
		{
			return *keysIt;
		}
	}
	return NULL;
}

void InputManager::changeKeyStatus(string name)
{
	int i = 0;
	for (keysIt = keys.begin(); keysIt != keys.end(); keysIt++)
	{
		if ((*keysIt)->getName() == name)
		{
			keysToCheck[i] = true;
		}
		i++;
	}
}


