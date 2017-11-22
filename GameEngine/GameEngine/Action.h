#pragma once
#include <vector>
#include "key.h"
class Action
{
private:
	vector <key> keys;
	string name;
public:
	Action();
	~Action();
	void addKey();
	string getAction();
};

