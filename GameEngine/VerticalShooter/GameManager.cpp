#include "GameManager.h"
using namespace VerticalShooter;
	GameManager::GameManager(string name, int x, int y, int w, int h, int depth) : Object(name, x, y, depth, w, h)
	{
		// Images for the game
		//RenderManager::GetInstance().addImage("images/Space.png", "Space");
		RenderManager::GetInstance().addImage("images/PlayerShip.png", "PlayerShip");
		RenderManager::GetInstance().addImage("images/Water.png", "Water");
		RenderManager::GetInstance().addImage("images/AlienShip.png", "AlienShip");
		RenderManager::GetInstance().addImage("images/SpaceLemon.png", "SpaceLemon");
		
		// Backgroudn for the game
		backGround = new Object("Background", 0, 0, 100, RenderManager::GetInstance().SCREEN_WIDTH, RenderManager::GetInstance().SCREEN_WIDTH);
		backGround->addImage("images/Space.png", "Space");

		// Create the water layers
		Image* img_water = RenderManager::GetInstance().getImageByName("Water");
		int screenHeight = RenderManager::GetInstance().SCREEN_HEIGHT;
		int screenWidth = RenderManager::GetInstance().SCREEN_WIDTH;
		for (int i = 0; i < 7; i++) {
			string layerName = "Water" + to_string(i);
			waterLayers.push_back(new WaterLayer(layerName, 0, screenHeight + (i * 20) - 100, screenWidth, screenWidth * 0.75, img_water, 100 - (i * 20)));
		}

		

		// Create the enemy ships
		Image* img_alien = RenderManager::GetInstance().getImageByName("AlienShip");
		for (int i = 0; i < 10; i++) {
			string shipName = "EnemyShip" + to_string(i);
			enemyShips.push_back(new EnemyShip(shipName, -50, -50, 100, 85, img_alien, 10));
		}

		// Create the proyectiles
		Image* img_proyectile = RenderManager::GetInstance().getImageByName("SpaceLemon");
		for (int i = 0; i < 20; i++) {
			string shipName = "Proyectile" + to_string(i);
			proyectiles.push_back(new Proyectile(shipName, -50, -50, 12, 6, img_proyectile, 0));
		}

		// create the player
		Image* img_player = RenderManager::GetInstance().getImageByName("PlayerShip");
		playerShip = new PlayerShip("PlayerShip", 200, 200, 45, 37, img_player);

		// Timer shit
		//TimerManager::GetInstance().getFPS();
		currentTime = 0;
		timeFromLastSpawn = 0;

		// Score stuff
		currentScore = 0;
		maxScore = 0;

		// Text stuff
			// Game ones
				// Score
		scoreText = new Text("Score: " + to_string(currentScore), "ScoreText", 400, 20, 200, 100, 0, true);
		scoreText->setFont("Config/xirod.ttf", 20);
		scoreText->setColor(255, 255, 255);
				// Life
		lifesText = new Text("Lifes: " + to_string(playerShip->GetLifes()), "ScoreText", 20, 20, 200, 100, 0, true);
		lifesText->setFont("Config/xirod.ttf", 20);
		lifesText->setColor(255, 255, 255);
			// Menu ones
				// Title
		title1 = new Text("NOT", "TitleText1", 20, 20, 200, 100, 0, true);
		title1 ->setFont("Config/xirod.ttf", 40);
		title1->setColor(255, 255, 255);
		title2 = new Text("VERTICAL", "TitleText2", 20, 20, 200, 100, 0, true);
		title2->setFont("Config/xirod.ttf", 40);
		title2->setColor(255, 255, 255);
				// Start instruction
		startInstructions = new Text("ENTER TO START", "StartText", 20, 20, 200, 100, 0, true);
		startInstructions->setFont("Config/xirod.ttf", 20);
		startInstructions->setColor(255, 255, 255);
				// Quit instruction
		quitInstructions = new Text("QUIT TO EXIT", "QuitText", 20, 20, 200, 100, 0, true);
		quitInstructions->setFont("Config/xirod.ttf", 20);
		quitInstructions->setColor(255, 255, 255);

		// Sounds
		SoundManager::GetInstance().loadEffect("sound/Lazer.wav", "Lazer");
		SoundManager::GetInstance().loadEffect("sound/Explosion.wav", "Explosion");

		//
		inMenu = true;
	}


	GameManager::~GameManager()
	{
	}

	void GameManager::update()
	{
		//
		if (inMenu) {

			quitGamePressed = ActionManager::GetInstance().getPressed("quit");

			if (ActionManager::GetInstance().getReleased("accept")) {
				StartGame();
			}
		}
		else
		{
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
			lifesText->setText("Lifes: " + to_string(playerShip->GetLifes()));

			// Shoots from the player
			if (playerShip->GetShooting()) {

				activateProyectile(); // Get x and y of thge player
			}

			// Proyectile control
			checkProyectiles();
		}
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

	void GameManager::activateProyectile() {
		vector<Proyectile*>::iterator proyecIT;
		for (proyecIT = proyectiles.begin(); proyecIT < proyectiles.end(); proyecIT++) {
			if ((*proyecIT)->isAlive() == false) {
				(*proyecIT)->Activate(playerShip->x, playerShip->y);
				SoundManager::GetInstance().play("Lazer");
				return;
			}
		}
		//cout << "All enemies currently active" << endl;
	}

	void GameManager::checkProyectiles()
	{
		vector<Proyectile*>::iterator proyecIT;
		for (proyecIT = proyectiles.begin(); proyecIT < proyectiles.end(); proyecIT++) {
			if ((*proyecIT)->isAlive() == true) {
				// Order it to make the checkings
				currentScore += (*proyecIT)->CheckCollisionsWithEnemies(enemyShips);
				scoreText->setText("Score: " + to_string(currentScore));
			}
		}
	}

	void VerticalShooter::GameManager::SetMenu()
	{
		int screenWidth = RenderManager::GetInstance().SCREEN_WIDTH;
		int screenHeight = RenderManager::GetInstance().SCREEN_HEIGHT;
		// Set the menu texts
		title1->x = screenWidth - (title1->getWidth()/2);
		title1->y = 50;
		title2->x = screenWidth - (title2->getWidth()/2);
		title2->y = 100;
		startInstructions->x = screenWidth - (startInstructions->getWidth() / 2);
		startInstructions->y = 150;
		quitInstructions->x = screenWidth - (quitInstructions->getWidth() / 2);
		quitInstructions->y = 200;
	}

	void VerticalShooter::GameManager::StartGame()
	{

	}

	void VerticalShooter::GameManager::EndGame()
	{

	}

