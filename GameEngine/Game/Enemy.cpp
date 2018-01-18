#include "Enemy.h"



Enemy::Enemy(string name, int x, int y, int depth, float w, float h) : Object(name, x, y, depth, w, h, "enemy")
{
}


Enemy::~Enemy()
{
}

bool Enemy::caught(Object * p)
{
	if (checkCollision(p, x, y))
	{
		x = rand() % 600;
		y = rand() % 400;
		return true;
	}
	return false;
}


