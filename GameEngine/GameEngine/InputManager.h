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
	bool* keysToCheck;
	SDL_Event e;
	bool quit;
public:
	InputManager();
	~InputManager();
	void keyboardCheck();
	bool checkKey(string name);
	key* getKey(string name);
	void changeKeyStatus(string);
	bool checkQuit();


};