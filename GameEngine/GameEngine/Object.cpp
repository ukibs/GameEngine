#include "Object.h"
#include "ObjectManager.h"



Object::Object()
{
}

Object::Object(string name,int x, int y,int depth, float w, float h)
{
	this->name = name;
	this->x = x;
	this->y = y;
	width = w;
	height = h;
	this->depth = depth;
	addCollider(name, this->x, this->y, this->width, this->height);
	ObjectManager::GetInstance().addObject(this);
}

Object::~Object()
{
}

void Object::start()
{
}

void Object::postUpdate()
{
		update();
		image.render(x, y);
		text.render(x, y);
		collider.Update(this->x, this->y);
}

void Object::addCollider(string name, float x, float y, float w, float h)
{
	ColliderManager::GetInstance().addCollider(name, x, y, w, h);
	collider = *(ColliderManager::GetInstance().getColliderByName(name));
}


void Object::addImage(string path,string name)
{
	RenderManager::GetInstance().addImage(path, name);
	image = *(RenderManager::GetInstance().getImageByName(name));
}

void Object::setImage(Image* newImage)
{
	image = *newImage;
}

void Object::setText(Text * newText)
{
	text = *newText;
}

SDL_Rect Object::getCollider()
{
	return collider.getCollider();
}

bool Object::checkCollision(Object * b)
{
	return collider.checkCollision(b->getCollider());
}

bool Object::anyCollision()
{
	return collider.anyCollision();
}

void Object::update(){}