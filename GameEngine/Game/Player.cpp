#include "Player.h"



Player::Player(string name, int x, int y, int depth, float w, float h): Object(name, x, y, depth, w, h)
{
}


Player::~Player()
{
}

void Player::update()
{
	if (InputManager::GetInstance().checkKey("d")) {
		x += 1;
	}
	if (InputManager::GetInstance().checkKey("a"))
	{
		x -= 1;
	}
	if (InputManager::GetInstance().checkKey("w"))
	{
		y -= 1;
	}
	if (InputManager::GetInstance().checkKey("s"))
	{
		y += 1;
	}
}