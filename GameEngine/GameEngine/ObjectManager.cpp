#include "ObjectManager.h"



ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
}

void ObjectManager::addObject(Object newObject)
{
	objects.push_back(newObject);
}

void ObjectManager::addObject(string name, int x, int y, int depth)
{
	Object* newObj = new Object(name, x, y, depth);
	objects.push_back(*newObj);
}

void ObjectManager::update()
{
	int i = 0;
	for (objIt = objects.begin(); objIt != objects.end(); objIt++) {
		objIt->update();
	}
}

Object* ObjectManager::getObjectByName(string name)
{
	for (objIt = objects.begin(); objIt != objects.end(); objIt++) {
		if (objIt->name==name) {
			return &(*objIt);
		}
	}
	return NULL;
}
