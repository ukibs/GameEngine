#include "PlayerShip.h"

PlayerShip::PlayerShip()
{
}

PlayerShip::PlayerShip(string name, int x, int y, int w, int h, Image* sprite, int depth) : Object(name, x, y, depth, w, h)
{
	setImage(sprite);
}

PlayerShip::~PlayerShip()
{
}

void PlayerShip::update() 
{
	int newX = x;
	int newY = y;
	if (ActionManager::GetInstance().getDown("right"))
	{
		newX = x + speed;
	}
	if (ActionManager::GetInstance().getDown("left"))
	{
		newX = x - speed;
	}
	if (ActionManager::GetInstance().getDown("up"))
	{
		newY = y - speed;
	}
	if (ActionManager::GetInstance().getDown("down"))
	{
		newY = y + speed;
	}
	//cout << "Updating";
	x = newX;
	y = newY;
}

void PlayerShip::CheckCollisionsWithEnemies(vector<EnemyShip*> enemyShips)
{
	vector<EnemyShip*>::iterator esIT;
	for (esIT = enemyShips.begin(); esIT < enemyShips.end(); esIT++) {
		if (checkCollision(*esIT, x, y) && (*esIT)->getDepth() < 2){
			cout << "Collision with " << (*esIT)->getName() << endl;
			(*esIT)->Kill();
		}
	}
}
