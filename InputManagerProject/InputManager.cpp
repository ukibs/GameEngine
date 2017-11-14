
#include <list>
#include <SDL.h>
#include <vector>
#include <iostream>

#include "InputManager.h"
#include "key.h"

InputManager::InputManager() 
{
	/*for (int i = 0; i < 27; i++)
	{
		keys = new key();
	}*/
	for (int i = 0; i < 27; i++)
	{
		keysToCheck[i] = false;
	}
}

vector <key> InputManager::keyboardCheck(SDL_Event& e)
{
	for (int i = 0; i < keysToCheck.size; i++)
	{
		if (keysToCheck[i])
		{
			keys[i].updateData(e);
		}
	}
}
