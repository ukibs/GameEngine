#pragma once
#include "Object.h"
#include "SoundManager.h"
#include "Timer.h"
class Item: public Object
{
public:
	Item();
	Item(string name, int x, int y, int depth, float w, float h,int time=10000);
	~Item();
	virtual void collect();
	void kill();
	void restart(int newX,int newY);
	void update();
private:
	Timer timer;
	int time;
};

