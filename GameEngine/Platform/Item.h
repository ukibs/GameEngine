#pragma once
#include "Object.h"
#include "SoundManager.h"
#include "Timer.h"
class Item: public Object
{
public:
	Item();
	Item(string name, int x, int y, int depth, float w, float h,Uint8 time=30);
	~Item();
	virtual void collect();
	void update();
private:
	//Uint8 time;
	//Timer timer;
};

