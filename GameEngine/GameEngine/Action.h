#pragma once
#include <vector>
#include <iostream>
#include "key.h"
#include "InputManager.h"
class Action
{
private:
	vector <key*> keys;
	vector <key*>::iterator keyIt;
	string name;
	bool pressed;
	bool down;
	bool released;
	bool prevDown;
public:
	Action(string name);
	Action(string name, key* keyToAdd, ...);
	~Action();
	void addKey(key* keyToAdd);
	void addKey(string name);
	string getAction();
	bool getPressed();
	bool getDown();
	bool getReleased();
	void update();
};

