#include "GameManager.h"
using namespace VerticalShooter;
GameManager::GameManager() {
	quit = false;
	start();
	if (!quit) {
		init();
	}
}

void GameManager::start() {
	EngineManager::CreateSingleton();
	SoundManager::CreateSingleton();
	if (!EngineManager::GetInstance().start() || !SoundManager::GetInstance().init()) {
		quit = true;
	}
}

void GameManager::close() {
	SoundManager::GetInstance().close();
	EngineManager::GetInstance().close();
}

void GameManager::init()
{
	//create some actions
	// Movement ones
	ActionManager::GetInstance().addAction("up", "w");
	ActionManager::GetInstance().getActionByName("up")->addKey("up");
	ActionManager::GetInstance().addAction("down", "s");
	ActionManager::GetInstance().getActionByName("down")->addKey("down");
	ActionManager::GetInstance().addAction("left", "a");
	ActionManager::GetInstance().getActionByName("left")->addKey("left");
	ActionManager::GetInstance().addAction("right", "d");
	ActionManager::GetInstance().getActionByName("right")->addKey("right");
	// Action ones
	ActionManager::GetInstance().addAction("shoot", "space");
	ActionManager::GetInstance().addAction("accept", "return");
	ActionManager::GetInstance().addAction("quit", "escape");

	// Get the screen width an height for the start
	int screenHeight = RenderManager::GetInstance().SCREEN_HEIGHT;
	int screenWidth = RenderManager::GetInstance().SCREEN_WIDTH;

	// Images for the game
	RenderManager::GetInstance().addImage("images/Space.png", "Space");
	RenderManager::GetInstance().addImage("images/PlayerShip.png", "PlayerShip");
	RenderManager::GetInstance().addImage("images/Water.png", "Water");
	RenderManager::GetInstance().addImage("images/AlienShip.png", "AlienShip");
	RenderManager::GetInstance().addImage("images/SpaceLemon.png", "SpaceLemon");
		
	// Backgroudn for the game
	//backGround = new Object("Background", 0, 0, 100, RenderManager::GetInstance().SCREEN_WIDTH, RenderManager::GetInstance().SCREEN_WIDTH);
	//backGround->addImage("images/Space.png", "Space");
	/*backGround = new Object("Background", 0, 0, 100, 
		RenderManager::GetInstance().SCREEN_WIDTH, RenderManager::GetInstance().SCREEN_WIDTH,
		"images/Space.png", "Space");*/

	// Create the water layers
	Image* img_water = RenderManager::GetInstance().getImageByName("Water");
	for (int i = 0; i < 7; i++) {
		string layerName = "Water" + to_string(i);
		waterLayers.push_back(new WaterLayer(layerName, 0, screenHeight + (i * 20) - 100, screenWidth, screenWidth * 0.75, img_water, 100 - (i * 20)));
	}

	// Create the enemy ships
	Image* img_alien = RenderManager::GetInstance().getImageByName("AlienShip");
	for (int i = 0; i < 10; i++) {
		string shipName = "EnemyShip" + to_string(i);
		enemyShips.push_back(new EnemyShip(shipName, screenWidth, screenHeight, 100, 85, img_alien, 10));
	}

	// Create the proyectiles
	Image* img_proyectile = RenderManager::GetInstance().getImageByName("SpaceLemon");
	for (int i = 0; i < 20; i++) {
		string shipName = "Proyectile" + to_string(i);
		proyectiles.push_back(new Proyectile(shipName, screenWidth, screenHeight, 12, 6, img_proyectile, 0));
	}

	// create the player
	Image* img_player = RenderManager::GetInstance().getImageByName("PlayerShip");
	playerShip = new PlayerShip("PlayerShip", screenWidth, screenHeight, 45, 37, img_player, -1);

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
	title3 = new Text("SHOOTER", "TitleText3", 20, 20, 200, 100, 0, true);
	title3->setFont("Config/xirod.ttf", 40);
	title3->setColor(255, 255, 255);
			// Start instruction
	startInstructions = new Text("ENTER TO START", "StartText", 20, 20, 200, 100, 0, true);
	startInstructions->setFont("Config/xirod.ttf", 20);
	startInstructions->setColor(255, 255, 255);
			// Quit instruction
	quitInstructions = new Text("QUIT TO EXIT", "QuitText", 20, 20, 200, 100, 0, true);
	quitInstructions->setFont("Config/xirod.ttf", 20);
	quitInstructions->setColor(255, 255, 255);
			// Best score
	bestScore = new Text("MAX SCORE: 0", "QuitText", 20, 20, 200, 100, 0, true);
	bestScore->setFont("Config/xirod.ttf", 20);
	bestScore->setColor(255, 255, 255);

	// Sounds
	SoundManager::GetInstance().loadEffect("sound/Lazer.wav", "Lazer");
	SoundManager::GetInstance().loadEffect("sound/Explosion.wav", "Explosion");

	// Music
	SoundManager::GetInstance().loadMusic("sound/MenuMusic.mp3", "MenuMusic");
	SoundManager::GetInstance().loadMusic("sound/GameMusic.mp3", "GameMusic");
	//
	inMenu = true;

	//
	SetMenu();
}


	GameManager::~GameManager()
	{
	}

	bool GameManager::update()
	{
		// Paint space
		//Image * spaceImage = RenderManager::GetInstance().getImageByName("Space");
		RenderManager::GetInstance().addToRender("Space",500);
			//
		quit = EngineManager::GetInstance().update();
		if (inMenu) {

			quitGamePressed = ActionManager::GetInstance().getPressed("quit");

			if (ActionManager::GetInstance().getReleased("accept")) {
				HideMenu();
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

			// Game over check
			if (playerShip->GetLifes() <= 0 || ActionManager::GetInstance().getPressed("quit")) {
				playerShip->SetLifes(0);
				EndGame();
				SetMenu();
			}
		}
		quit = quit || GetQuitGame();
		return quit;
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
		title1->x = screenWidth / 2 - (title1->getWidth()/2);
		title1->y = 50;
		title2->x = screenWidth / 2 - (title2->getWidth()/2);
		title2->y = 120;
		title3->x = screenWidth / 2 - (title2->getWidth() / 2);
		title3->y = 190;
		startInstructions->x = screenWidth / 2 - (startInstructions->getWidth() / 2);
		startInstructions->y = 300;
		quitInstructions->x = screenWidth / 2 - (quitInstructions->getWidth() / 2);
		quitInstructions->y = 350;
		bestScore->x = screenWidth - bestScore->getWidth() - 10;
		bestScore->y = 10;
		//
		lifesText->x = 1000;
		scoreText->x = 1000;
		// Music
		SoundManager::GetInstance().play("MenuMusic");
	}

	void VerticalShooter::GameManager::HideMenu()
	{
		int screenWidth = RenderManager::GetInstance().SCREEN_WIDTH;
		// 
		title1->x = 1000;
		title2->x = 1000;
		title3->x = 1000;
		startInstructions->x = 1000;
		quitInstructions->x = 1000;
		bestScore->x = 1000;
		//
		lifesText->x = 10;
		scoreText->x = screenWidth - scoreText->getWidth() - 10;
	}

	void VerticalShooter::GameManager::StartGame()
	{
		inMenu = false;
		playerShip->Activate();
		SoundManager::GetInstance().play("GameMusic");
	}

	void VerticalShooter::GameManager::EndGame()
	{
		if (maxScore < currentScore) {
			maxScore = currentScore;
		}
		bestScore->setText("Max score: " + to_string(maxScore));
		currentScore = 0;
		inMenu = true;
		// Clean screen
		CleanEnemiesAndBullets();
	}

	void VerticalShooter::GameManager::CleanEnemiesAndBullets()
	{
		// Enemies
		vector<EnemyShip*>::iterator esIT;
		for (esIT = enemyShips.begin(); esIT < enemyShips.end(); esIT++) {
			if ((*esIT)->isAlive() == true) {
				(*esIT)->Kill();
			}
		}
		// Bullets
		vector<Proyectile*>::iterator proyecIT;
		for (proyecIT = proyectiles.begin(); proyecIT < proyectiles.end(); proyecIT++) {
			if ((*proyecIT)->isAlive() == true) {
				(*proyecIT)->Kill();
			}
		}
	}

