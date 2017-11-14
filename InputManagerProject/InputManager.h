#pragma once

#include <string>
#include <SDL.h>
#include <vector>

//#include <list>

#include <stdio.h>
#include "key.h"
#include "Input.h"

class InputManager 
{
public:
	InputManager();
	vector <key> keyboardCheck(SDL_Event& e);


private:
	vector <key> keys;
	vector <bool> keysToCheck;
};