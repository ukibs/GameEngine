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

	float speed;
	//Image * image;

	int getDepth() { return depth; }

private:
	void update();
	bool alive;

	int maxHeight;
	int maxWidth;

	float floatDepth;
	float floatY;
};

