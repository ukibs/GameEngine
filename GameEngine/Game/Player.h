#pragma once
#include "Object.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "ActionManager.h"
class Player: public Object
{
public:
	float speed;
	Object * body[10];
	Image * image[5];
	int countBody;
	int direction;
	int lastX;
	int lastY;
	Player(string name,int x, int y,int depth, float w, float h);
	~Player();
	void update();
	void addBody();
	void moveBody();
};

