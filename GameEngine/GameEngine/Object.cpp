#include "Object.h"



Object::Object()
{
}

Object::Object(string name,int x, int y,int depth)
{
	this->name = name;
	this->x = x;
	this->y = y;
	this->depth = depth;
}

Object::~Object()
{
}

void Object::start()
{
}

void Object::update()
{
	image->render(x,y);
}

void Object::addImage(string path,string name)
{
	RenderManager::GetInstance().addImage(path, name);
	image = RenderManager::GetInstance().getImageByName(name);
}

void Object::setImage(Image* newImage)
{
	image = newImage;
}
