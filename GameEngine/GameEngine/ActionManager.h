#pragma once

#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <stdarg.h>
#include "Singleton.h"
#include "Action.h"

using namespace std;

class ActionManager : public Singleton<ActionManager>
{
private:
	vector <Action> actions;
	vector <Action>::iterator actionIt;
public:
	ActionManager();
	~ActionManager();
	void addAction(Action action);
	void addAction(string name, string keyName);
	//void addAction(string name, string keyNames[]);
	void addAction(string name,int numKeys, string keyName, ...);
	//void addAction(string name, string keyName, ...);
	void removeAction(string name);
	void update();
	bool getDown(string name);
	bool getPressed(string name);
	bool getReleased(string name);
	Action* getActionByName(string name);
};

