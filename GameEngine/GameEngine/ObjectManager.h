#pragma once
#include <string>
#include <cstdio>
#include "Singleton.h"
#include "Object.h"
using namespace std;


class ObjectManager : public Singleton<ObjectManager>
{
public:
	ObjectManager();
	~ObjectManager();
	void addObject(Object * newObject);
	void addObject(string name, int x, int y, int depth = 0, float height = 1, float width = 1);
	void update();
	Object* getObjectByName(string name);
	void destroyObject(Object * o);
private:
	vector <Object*> objects;
	//vector <Object*>::iterator objIt;
};

