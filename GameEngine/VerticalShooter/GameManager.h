#pragma once

#include <vector>
#include <string.h>

#include "Object.h"
#include "TimerManager.h"

#include "EnemyShip.h"
#include "PlayerShip.h"

class GameManager : public Object
{
public:
	GameManager(string name, int x, int y, int w, int h, int depth = 0);
	~GameManager();

private:
	// THe player
	PlayerShip * playerShip;

	//Enemies
	vector<EnemyShip*> enemyShips;

	//Time stuff
	float currentTime;
	float timeFromLastSpawn;

	//
	void update();
	void activateEnemy();
};
