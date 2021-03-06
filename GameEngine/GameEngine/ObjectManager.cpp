#include "ObjectManager.h"



ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
	for (vector<Object*>::iterator objIt = objects.begin(); objIt != objects.end(); objIt++) {
		(*objIt)->~Object();
	}
	objects.clear();
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
		i++;
		
	}
}

Object* ObjectManager::getObjectByName(string name)
{
	for (vector <Object*>::iterator objIt = objects.begin(); objIt != objects.end(); objIt++) {
		if ((*objIt)->getName()==name) {
			return (*objIt);
		}
	}
	return NULL;
}

void ObjectManager::destroyObject(string name)
{
	for (vector<Object*>::iterator objIt = objects.begin(); objIt != objects.end(); objIt++)
	{
		if ((*objIt)->getName() == name)
		{
			objects.erase(objIt);
			return;
		}
	}
}

void ObjectManager::close()
{
	objects.clear();
}
