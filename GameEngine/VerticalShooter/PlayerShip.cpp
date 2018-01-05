#include "PlayerShip.h"

PlayerShip::PlayerShip()
{
}

PlayerShip::PlayerShip(string name, int x, int y, int w, int h, Image* sprite, int depth, int speed) : Object(name, x, y, depth, w, h)
{
	this->image = sprite;
	setImage(this->image);
	this->speed = speed;
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
	cout << "Updating";
	x = newX;
	y = newY;
}