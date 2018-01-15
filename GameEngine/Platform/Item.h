#pragma once
#include "Object.h"
#include "SoundManager.h"
class Item: public Object
{
public:
	Item(string name, int x, int y, int depth, float w, float h);
	~Item();
	virtual void collect();
};

