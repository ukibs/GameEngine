#include "GameManager.h"
using namespace VerticalShooter;
	GameManager::GameManager(string name, int x, int y, int w, int h, int depth) : Object(name, x, y, depth, w, h)
	{
		// Images for the game
		//RenderManager::GetInstance().addImage("images/Space.png", "Space");
		RenderManager::GetInstance().addImage("images/PlayerShip.png", "PlayerShip");
		RenderManager::GetInstance().addImage("images/Water.png", "Water");
		RenderManager::GetInstance().addImage("images/Dot.jpg", "Dot");

		// The player image
		Image* img_player = RenderManager::GetInstance().getImageByName("PlayerShip");

		//
		backGround = new Object("Background", 0, 0, 100, RenderManager::GetInstance().SCREEN_WIDTH, RenderManager::GetInstance().SCREEN_WIDTH);
		backGround->addImage("images/Space.png", "Space");

		// Create the water layers
		Image* img_water = RenderManager::GetInstance().getImageByName("Water");
		int screenHeight = RenderManager::GetInstance().SCREEN_HEIGHT;
		int screenWidth = RenderManager::GetInstance().SCREEN_WIDTH;
		for (int i = 0; i < 5; i++) {
			string layerName = "Water" + to_string(i);
			waterLayers.push_back(new WaterLayer(layerName, 0, screenHeight + (i * 20) - 100, screenWidth, screenWidth * 0.75, img_water, 100 - (i * 20)));
		}

		

		// Create the enemy ships
		for (int i = 0; i < 10; i++) {
			string shipName = "EnemyShip" + to_string(i);
			enemyShips.push_back(new EnemyShip(shipName, -50, -50, 45, 37, img_player, 10));
		}

		// create the player
		playerShip = new PlayerShip("PlayerShip", 200, 200, 45, 37, img_player);

		// Timer shit
		//TimerManager::GetInstance().getFPS();
		currentTime = 0;
		timeFromLastSpawn = 0;
	}


	GameManager::~GameManager()
	{
	}

	void GameManager::update()
	{
		//
		//RenderManager::GetInstance().render("Space", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

		// Time stuff
		currentTime++;
		timeFromLastSpawn++;

		//Enemy spawn
		if (timeFromLastSpawn > 10) {
			//cout << "Spawning enemy" << endl;
			activateEnemy();
			timeFromLastSpawn = 0;
		}

		// Check collisions between enemies and the player
		playerShip->CheckCollisionsWithEnemies(enemyShips);
	}

	void GameManager::activateEnemy() {
		vector<EnemyShip*>::iterator esIT;
		for (esIT = enemyShips.begin(); esIT < enemyShips.end(); esIT++) {
			if ((*esIT)->isAlive() == false) {
				(*esIT)->Activate();
				return;
			}
		}
		//cout << "All enemies currently active" << endl;
	}
