#pragma once
#include "Object.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "ActionManager.h"
class Player: public Object
{
private:
	int time;
	Object * body[100];
	int position[32][24];
	int snakeDirection[32][24];
	Image * image[6];
	int countBody;
	int direction;
public:
	Player(string name,int x, int y,int depth, float w, float h);
	~Player();
	void update();
	void addBody();
	void moveBody();
	void changePosition(int, int);
	void updatePosition(int, int);
	void updateDirection(int, int, int);
};

