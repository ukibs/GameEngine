#include "Object.h"
#include "ObjectManager.h"



Object::Object()
{
}

Object::Object(string name,int x, int y,int depth, float w, float h, string tag)
{
	this->name = name;
	this->tag = tag;
	this->x = x;
	this->y = y;
	this->width = w;
	this->height = h;
	this->depth = depth;
	addCollider(name, tag, this->x, this->y, this->width, this->height);
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
		image.setToRender(x, y);
		collider->Update(x, y);
}

void Object::addCollider(string name, string tag, float x, float y, float w, float h)
{
	ColliderManager::GetInstance().addCollider(name, tag, x, y, w, h);
	this->collider = ColliderManager::GetInstance().getColliderByName(name);
}


void Object::addImage(string path,string name)
{
	RenderManager::GetInstance().addImage(path, name);
	image = *RenderManager::GetInstance().getImageByName(name);
}

void Object::setImage(Image* newImage)
{
	image = *newImage;
}

SDL_Rect Object::getCollider()
{
	return collider->getCollider();
}

bool Object::checkCollision(Object * b,int x, int y)
{
	collider->Update(x, y);
	return collider->checkCollision(b->getCollider());
}

bool Object::anyCollision(int x, int y)
{
	collider->Update(x, y);
	return collider->anyCollision();
}

string Object::getCollisionName(int x, int y)
{
	collider->Update(x, y);
	return collider->getCollisionName();
}

string Object::getCollisionTag(int x, int y)
{
	collider->Update(x, y);
	return collider->getCollisionTag();
}

void Object::destroy()
{
	ObjectManager::GetInstance().destroyObject(name);
	collider->destroy();
}

void Object::update(){}

string Object::getName()
{
	return name;
}