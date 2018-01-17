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
	int mouseX;
	int mouseY;
	bool rMousePressed;
	bool rMouseReleased;
	bool rMouseDown;
	bool lMousePressed;
	bool lMouseReleased;
	bool lMouseDown;
public:
	InputManager();
	~InputManager();
	void keyboardCheck();
	bool checkKey(string name);
	key* getKey(string name);
	void changeKeyStatus(string);
	bool checkQuit();
	int getMouseX() { return mouseX; };
	int getMouseY() { return mouseY; };
	bool getRightMousePressed() { return rMousePressed; };
	bool getRightMouseReleased() { return rMouseReleased; };
	bool getRightMouseDown() { return rMouseDown; };
	bool getLeftMousePressed() { return lMousePressed; };
	bool getLeftMouseReleased() { return lMouseReleased; };
	bool getLeftMouseDown() { return lMouseDown; };
	void close() { keys.clear(); };
};