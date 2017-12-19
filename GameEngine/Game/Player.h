#pragma once
#include "Object.h"
#include "ObjectManager.h"
#include "InputManager.h"
class Player: public Object
{
public:
	float speed;
	Object * array[4];
	Player(string name,int x, int y,int depth, float w, float h);
	~Player();
	void update();
	bool wallCollision();
};

