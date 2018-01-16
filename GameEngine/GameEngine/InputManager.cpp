
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
		keys.push_back(new key(name, sdl_key, as));
	}
	keysToCheck = new bool[keys.size()];
	for (int i = 0; i < keys.size(); i++)
	{
		keysToCheck[i] = false;
	}
}

InputManager::~InputManager()
{
}

void InputManager::keyboardCheck()
{
	lMousePressed = false;
	lMouseReleased = false;
	rMousePressed = false;
	rMouseReleased = false;
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT) {
			quit = true;
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN) {
			SDL_GetMouseState(&mouseX, &mouseY);
			if (e.button.button == SDL_BUTTON_LEFT) {
				if (!lMouseDown) {
					lMousePressed = true;
				}
				lMouseDown = true;
			}
			if (e.button.button == SDL_BUTTON_RIGHT) {
				if (!rMouseDown) {
					rMousePressed = true;
				}
				rMouseDown = true;
			}
		}
		else if (e.type == SDL_MOUSEBUTTONUP) {
			if (e.button.button == SDL_BUTTON_LEFT) {
				lMouseReleased = true;
				lMouseDown = false;
			}
			if (e.button.button == SDL_BUTTON_RIGHT) {
				rMouseReleased = true;
				rMouseDown = false;
			}
		}
		else if (e.type == SDL_MOUSEMOTION) {
			SDL_GetMouseState(&mouseX, &mouseY);
		}
		else {
			int i = 0;
			for (vector <key*>::iterator keysIt = keys.begin(); keysIt != keys.end(); keysIt++)
			{
				if (keysToCheck[i])
				{
					(*keysIt)->updateData(e);
				}
				i++;
			}
		}
	}
}

bool InputManager::checkKey(string name)
{
	changeKeyStatus(name);
	for (vector <key*>::iterator keysIt = keys.begin(); keysIt != keys.end(); keysIt++)
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
	for (vector <key*>::iterator keysIt = keys.begin(); keysIt != keys.end(); keysIt++)
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
	for (vector <key*>::iterator keysIt = keys.begin(); keysIt != keys.end(); keysIt++)
	{
		if ((*keysIt)->getName() == name)
		{
			keysToCheck[i] = true;
		}
		i++;
	}
}

bool InputManager::checkQuit()
{
	return quit;
}


