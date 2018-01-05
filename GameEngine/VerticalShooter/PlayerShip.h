#pragma once
#include "Object.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "ActionManager.h"
#include <vector>

class PlayerShip : public Object
{
public:
	PlayerShip();
	PlayerShip(string name, int x, int y, int w, int h, Image* sprite = NULL, int depth = 0, int speed = 10);
	~PlayerShip();

	int speed = 10;

	Image * image;

	void update();

private:

};

