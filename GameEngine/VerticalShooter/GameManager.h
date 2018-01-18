#pragma once
#include <vector>
#include <string.h>
// Engine headers
#include "EngineManager.h"
#include "SoundManager.h"
//Game headers
#include "EnemyShip.h"
#include "PlayerShip.h"
#include "WaterLayer.h"
#include "Proyectile.h"

/*
	Stuff to do
	- Sound
		+ Effects
		+ Music
	- Menu
	- Botón para salir del juego
*/
namespace VerticalShooter {
	class GameManager 
	{
	public:
		GameManager();
		~GameManager();

		bool GetQuitGame() { return inMenu && quitGamePressed; }
		bool update();
		void close();
	private:
		void init();
		void start();
		bool quit;
		// Menu variable
		bool inMenu;
		bool quitGamePressed;

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
			// Game ones
		Text * lifesText;
		Text * scoreText;
			// Menu ones
		Text * title1;
		Text * title2;
		Text * title3;
		Text * startInstructions;
		Text * quitInstructions;
		Text * bestScore;

		// Score stuff
		int currentScore;
		int maxScore;

		//Time stuff
		float currentTime;
		float timeFromLastSpawn;

		// Game functions
		void activateEnemy();

		void activateProyectile();
		void checkProyectiles();

		//
		void SetMenu();
		void HideMenu();
		void StartGame();
		void EndGame();
		void CleanEnemiesAndBullets();
	};
}

