#pragma once

#include "Object.h"

class EnemyShip : public Object
{
public:
	EnemyShip(string name, int x, int y, int w, int h, Image* sprite = NULL, int depth = 0);
	~EnemyShip();

	void Activate();
	void Kill();
	bool isAlive() { return alive; };

	int speed = 10;
	Image * image;

private:
	void update();

	bool alive;

};

