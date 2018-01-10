#include "ObjectManager.h"



ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
}

void ObjectManager::addObject(Object * newObject)
{
	objects.push_back(newObject);
}

void ObjectManager::addObject(string name, int x, int y, int depth, float w, float h)
{
	Object * newObj = new Object(name, x, y, depth, w, h);
	objects.push_back(newObj);
}

void ObjectManager::update()
{
	int i = 0;
	for (vector <Object*>::iterator objIt = objects.begin(); objIt != objects.end(); objIt++)
	{
		(*objIt)->postUpdate();
		
	}
}

Object* ObjectManager::getObjectByName(string name)
{
	for (vector <Object*>::iterator objIt = objects.begin(); objIt != objects.end(); objIt++) {
		if ((*objIt)->name==name) {
			return (*objIt);
		}
	}
	return NULL;
}

void ObjectManager::destroyObject(string name)
{
	for (vector<Object*>::iterator objIt = objects.begin(); objIt != objects.end(); objIt++)
	{
		if ((*objIt)->name == name)
		{
			objects.erase(objIt);
			return;
		}
	}
}
