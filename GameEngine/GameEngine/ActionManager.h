#pragma once

#include <vector>

#include "Singleton.h"
#include "Action.h"

class ActionManager : public Singleton<ActionManager>
{
private:
	//vector <Action> actionArray;
public:
	ActionManager();
	~ActionManager();
};

