#include "Player.h"



Player::Player(string name, int x, int y, int depth, float w, float h): Object(name, x, y, depth, w, h)
{
	speed = 1;
}


Player::~Player()
{
}

void Player::update()
{
	int newX = x;
	int newY = y;
	if (InputManager::GetInstance().checkKey("d")) 
	{
		newX = x + speed;
	}
	else if (InputManager::GetInstance().checkKey("a"))
	{
		newX = x - speed;
	}
	else if (ActionManager::GetInstance().getDown("up"))
	{
		newY = y - speed;
	}
	else if (ActionManager::GetInstance().getDown("down"))
	{
		newY = y + speed;
	}

	if (newY < 440 && newY > 20 && newX < 600 && newX > 20)
	{
		x = newX;
		y = newY;
	}
}
