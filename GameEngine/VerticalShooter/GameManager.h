#pragma once

#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H
#include "GameManager.h"
#endif // !GAMEMANAGER_H

#include <vector>
#include <string.h>

#include "Object.h"
#include "TimerManager.h"
#include "Text.h"

#include "EnemyShip.h"
#include "PlayerShip.h"
#include "WaterLayer.h"
#include "Proyectile.h"

/*
	Stuff to do
	- Text
		+ Lifes
		+ Score
	- Sound
		+ Effects
		+ Music
	- Menu
	- Colliders
*/
namespace VerticalShooter {
	class GameManager : public Object
	{
	public:
		GameManager(string name, int x, int y, int w, int h, int depth = 0);
		~GameManager();

	private:
		// The player
		PlayerShip * playerShip;

		// Proyectiles
		vector<Proyectile*> proyectiles;

		//Enemies
		vector<EnemyShip*> enemyShips;

		//Background
		Object * backGround;

		// Water layers
		vector<WaterLayer*> waterLayers;

		// Text stuff
		Text * lifesText;
		Text * scoreText;

		// Score stuff
		int currentScore;
		int maxScore;

		//Time stuff
		float currentTime;
		float timeFromLastSpawn;

		// Game functions
		void update();

		void activateEnemy();

		void activateProyectile();
		void checkProyectiles();
	};
}

