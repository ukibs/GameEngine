#include "JumpMan.h"
#include "ItemFinal.h"


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
	jumping = true;
	newY = y + ySpeed;

	//check to collect items
	string checkName = getCollisionName(newX, newY);
	if (checkName != "") {
		Object* check = ObjectManager::GetInstance().getObjectByName(checkName);

		if (typeid(*check) == typeid(Item) || typeid(*check) == typeid(ItemFinal)) {
			Item *item = dynamic_cast<Item *>(check);
			item->collect();
			if (typeid(*item) == typeid(Item)) {
				item->destroy();
			}
			else {
				newX = x;
				newY = y;
			}
		}
	}
	
	
	//collision check
	if (!anyCollision(newX, newY)) {//no collision
		x = newX;
		y = newY;
	}
	else {
		bool col = false;
		if (!anyCollision(x, newY)) {//collision on x axis
			y = newY;
			col = true;
		}
		if (!anyCollision(newX, y)) {//collision on y axis
			if (ySpeed > 0) { 
				jumping = false; 
			}//if it is grounded
			ySpeed = 0;
			x = newX;
			col = true;
		}
		if(!col) {
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

JumpMan::~JumpMan()
{
}
