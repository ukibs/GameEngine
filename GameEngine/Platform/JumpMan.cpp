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
	string checkName = checkForItem(newX,newY);
	if (checkName != "") {
		Object* check = ObjectManager::GetInstance().getObjectByName(checkName);
		Item *item = dynamic_cast<Item *>(check);
		item->collect();
		if (typeid(*item) == typeid(Item)) {
			item->kill();
		}
		else {
			newX = x;
			newY = y;
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

string JumpMan::checkForItem(int newX, int newY)
{
	string checkName = getCollisionName(newX, newY);
	//si colisiona con algo
	if (checkName != "") {
		Object* check = ObjectManager::GetInstance().getObjectByName(checkName);
		//si es item devuelve su nombre
		if (typeid(*check) == typeid(Item) || typeid(*check) == typeid(ItemFinal)) {
			return checkName;
		}
		//si no es item busca la colision en eje x
		else {
			checkName = getCollisionName(newX, y);
			if (checkName != "") {
				Object* check = ObjectManager::GetInstance().getObjectByName(checkName);

				if (typeid(*check) == typeid(Item) || typeid(*check) == typeid(ItemFinal)) {
					return checkName;
				}
			}
			//si colisiona con un no item en x prueba en y
			else {
				checkName = getCollisionName(x, newY);
				if (checkName != "") {
					Object* check = ObjectManager::GetInstance().getObjectByName(checkName);

					if (typeid(*check) == typeid(Item) || typeid(*check) == typeid(ItemFinal)) {
						return checkName;
					}
				}
				else return "";
			}
		}
	}
	//si no colisiona con nada
	else {
		return "";
	}
	return "";
}
