#include "GameManager.h"



GameManager::GameManager(string name, int x, int y, int w, int h, int depth) : Object(name, x, y, depth, w, h)
{
	// Images for the game
	RenderManager::GetInstance().addImage("images/PlayerShip.jpg", "PlayerShip");
	RenderManager::GetInstance().addImage("images/dot.jpg", "Dot");

	// The player image
	Image* img_player = RenderManager::GetInstance().getImageByName("PlayerShip");

	// create the player
	playerShip = new PlayerShip("PlayerShip", 200, 200, 45, 37, img_player);

	// Create the enemy ships
	for (int i = 0; i < 10; i++) {
		string shipName = "EnemyShip" + to_string(i);
		enemyShips.push_back(new EnemyShip(shipName, -50, -50, 45, 37, img_player));
	}

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
	currentTime++;
	timeFromLastSpawn++;
	if (timeFromLastSpawn > 10) {
		//cout << "Spawning enemy" << endl;
		activateEnemy();
		timeFromLastSpawn = 0;
	}
}

void GameManager::activateEnemy(){
	vector<EnemyShip*>::iterator esIT;
	for (esIT = enemyShips.begin(); esIT < enemyShips.end(); esIT++) {
		if ((*esIT)->isAlive() == false) {
			(*esIT)->Activate();
			return;
		}
	}
	cout << "All enemies currently active" << endl;
}