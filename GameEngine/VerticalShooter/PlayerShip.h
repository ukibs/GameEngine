#pragma once
#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "PlayerShip.h"
#endif // !GAMEMANAGER_H

#include <vector>
// Engine libraries
#include "Object.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "ActionManager.h"
#include "SoundManager.h"
// Game headers
#include "EnemyShip.h"

class PlayerShip : public Object
{
public:
	PlayerShip();
	PlayerShip(string name, int x, int y, int w, int h, Image* sprite = NULL, int depth = 0);
	~PlayerShip();

	void update();

	void CheckCollisionsWithEnemies(vector<EnemyShip*>);
	void Activate();

	bool GetShooting() { return shooting; };
	int GetLifes() { return lifes; };
	void SetLifes(int value) { lifes = value; };

private:

	int speed = 10;

	int lifes;

	bool shooting;

	//
	void LoseLife();
};

