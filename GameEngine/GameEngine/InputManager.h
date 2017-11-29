#pragma once

#include <string>
#include <vector>
#include <stdio.h>

//#include <list>

//#include <cstdio>
#include "Singleton.h"
#include "key.h"
#include "Input.h"

class InputManager : public Singleton<InputManager>
{
	friend class Singleton<InputManager>;
public:
	InputManager();
	void keyboardCheck(SDL_Event& e);
	bool checkKey(string name);


private:
	vector <key*> keys;
	vector <key*>::iterator keysIt;
	//vector <bool> keysToCheck;
	bool* keysToCheck;
};