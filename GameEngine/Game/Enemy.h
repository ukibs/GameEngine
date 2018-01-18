#pragma once
#include "Object.h"
#include "ObjectManager.h"
class Enemy: public Object
{
public:
	Enemy(string name, int x, int y, int depth, float w, float h);
	~Enemy();
	bool caught(Object*);
};

