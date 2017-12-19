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
	float newX = x;
	float newY = y;
	if (InputManager::GetInstance().checkKey("d")) 
	{
		newX = x + speed;
	}
	if (InputManager::GetInstance().checkKey("a"))
	{
		newX = x - speed;
	}
	if (InputManager::GetInstance().checkKey("w"))
	{
		newY = y - speed;
	}
	if (InputManager::GetInstance().checkKey("s"))
	{
		newY = y + speed;
	}

	if (newY < 460 && newY > 20 && newX < 460 && newX > 20)
	{
		x = newX;
		y = newY;
	}
}
