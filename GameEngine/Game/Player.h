#pragma once
#include "Object.h"
#include "ObjectManager.h"
#include "InputManager.h"
class Player: public Object
{
public:
	Player(string name,int x, int y,int depth, float w, float h);
	~Player();
	void update();
};

