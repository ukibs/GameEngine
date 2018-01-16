#pragma once
#include "Object.h"
#include "SoundManager.h"

#include "EnemyShip.h"

class Proyectile : Object
{
public:
public:
	Proyectile(string name, int x, int y, int w, int h, Image* sprite = NULL, int depth = 0);
	~Proyectile();

	void Activate(int, int);
	void Kill();
	bool isAlive() { return alive; };

	float speed;
	//Image * image;

	int CheckCollisionsWithEnemies(vector<EnemyShip*>);

	int getDepth() { return depth; }

private:
	void update();
	bool alive;

	int maxHeight;
	int maxWidth;

	float floatDepth;
};

