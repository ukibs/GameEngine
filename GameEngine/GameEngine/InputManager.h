#pragma once

#include <string>
#include <SDL.h>
#include <vector>
#include <stdio.h>

//#include <list>

//#include <cstdio>
#include "key.h"
#include "Input.h"

class InputManager 
{
public:
	InputManager();
	void keyboardCheck(SDL_Event& e);


private:
	vector <key*> keys;
	vector <key*>::iterator keysIt;
	//vector <bool> keysToCheck;
	bool* keysToCheck;
};