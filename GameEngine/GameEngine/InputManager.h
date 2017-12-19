#pragma once

#include <string>
#include <vector>
#include <stdio.h>
#include "Singleton.h"
#include "key.h"


class InputManager : public Singleton<InputManager>
{
	friend class Singleton<InputManager>;
private:
	vector <key*> keys;
	vector <key*>::iterator keysIt;
	bool* keysToCheck;

public:
	InputManager();
	~InputManager();

	void keyboardCheck(SDL_Event& e);
	bool checkKey(string name);
	key* getKey(string name);
};