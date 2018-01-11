#pragma once
#include <vector>

#include "Object.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "ActionManager.h"

#include "EnemyShip.h"

class PlayerShip : public Object
{
public:
	PlayerShip();
	PlayerShip(string name, int x, int y, int w, int h, Image* sprite = NULL, int depth = 0);
	~PlayerShip();

	void update();

	void CheckCollisionsWithEnemies(vector<EnemyShip*>);

private:
	int speed = 10;
	//Image * image;		// Revisar
};

