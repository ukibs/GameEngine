#pragma once
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "PlayerShip.h"
#endif // !GAMEMANAGER_H

#include <vector>

#include "Object.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "ActionManager.h"

//#include "GameManager.h"
#include "EnemyShip.h"

//using namespace VerticalShooter;

class PlayerShip : public Object
{
public:
	PlayerShip();
	PlayerShip(string name, int x, int y, int w, int h, Image* sprite = NULL, int depth = 0);
	//PlayerShip(string name, int x, int y, int w, int h, GameManager *, Image* sprite = NULL, int depth = 0);
	~PlayerShip();

	void update();

	void CheckCollisionsWithEnemies(vector<EnemyShip*>);

	bool GetShooting() { return shooting; };

private:

	//GameManager * gameMgr;

	int speed = 10;
	//Image * image;		// Revisar


	bool shooting;
};

