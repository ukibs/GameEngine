#include "JumpMan.h"



JumpMan::JumpMan()
{
}

JumpMan::JumpMan(string name, int x, int y, int w, int h, Image* sprite, int depth, int xSpeed, int ySpeed, int jumpSpeed, int gravity) : Object(name, x, y, depth, w, h)
{
	this->xSpeed = xSpeed;
	this->ySpeed = ySpeed;
	this->jumpSpeed = jumpSpeed;
	this->gravity = gravity;
	this->sprite = sprite;
	setImage(sprite);
	this->xSpeed = 5;
	this->gravity = 1;
	this->jumpSpeed = 15;
}

void JumpMan::update()
{
	int newX = x;
	int newY = y;
	if (ActionManager::GetInstance().getDown("right"))
	{
		newX = x + xSpeed;
	}
	if (ActionManager::GetInstance().getDown("left"))
	{
		newX = x - xSpeed;
	}
	if (ActionManager::GetInstance().getDown("up")&&!jumping)
	{
		ySpeed = -jumpSpeed;
		jumping = true;
	}
	//apply gravity
	ySpeed += gravity;
	newY = y + ySpeed;
	//collision check
	if (!checkIfCollision(newX, newY)) {
		x = newX;
		y = newY;
	}
	else {
		if (!checkIfCollision(x, newY)) {
			y = newY;
		}
		else if (!checkIfCollision(newX, y)) {
			jumping = false;
			ySpeed = 0;
			x = newX;
		}
		else {
			jumping = false;
			ySpeed = 0;
		}
	}
}

int JumpMan::getSpeed()
{
	return xSpeed;
}

void JumpMan::setSpeed(int newSpeed)
{
	xSpeed = newSpeed;
}

int JumpMan::getJumpSpeed()
{
	return jumpSpeed;
}

void JumpMan::setJumpSpeed(int newJump)
{
	jumpSpeed = newJump;
}

int JumpMan::getGravity()
{
	return gravity;
}

void JumpMan::setGravity(int newG)
{
	gravity = newG;
}

void JumpMan::addImage(Image * newImage)
{
	sprite = newImage;
}

void JumpMan::setPlatforms(Object ** platforms, int numP)
{
	for (int i = 0; i < numP; i++) {
		this->platforms.push_back(platforms[i]);
	}
}

JumpMan::~JumpMan()
{
}

bool JumpMan::checkIfCollision(int x,int y)
{
	bool collision = false;
	/*if (y > 440 || y < 20 || x > 600 || x < 20)
	{
		collision = true;
	}
	for (pltIt = platforms.begin(); pltIt != platforms.end(); pltIt++) {
		if (checkCollision((*pltIt))) {
			collision=true;
			break;
		}
	}*/
	if (anyCollision(x,y)) {
		return true;
	}
	return collision;
}
