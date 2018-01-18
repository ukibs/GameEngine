#include "GameManager.h"
using namespace Snake;


	GameManager::GameManager()
	{
		quit = false;
		start();
		loadMedia();
		initPlayer();
		initWalls();
		setMenu();
		createActions();
		inMenu = true;
		click = false;
	}

	void GameManager::start() {
		EngineManager::CreateSingleton();
		SoundManager::CreateSingleton();
		if (!EngineManager::GetInstance().start() || !SoundManager::GetInstance().init()) {
			cout << "Falied to initialize!\n";
			quit = true;
		}
	}

	void GameManager::initWalls()
	{
		//create the walls
		walls[0] = new Object("obj_wall1", 0, 0, 0, 640, 20);
		walls[2] = new Object("obj_wall3", 0, 20, 0, 20, 480);
		walls[3] = new Object("obj_wall4", 620, 0, 0, 20, 480);
		walls[1] = new Object("obj_wall2", 0, 460, 0, 640, 20);
		Image * img_horWall = RenderManager::GetInstance().getImageByName("img_horWall");
		walls[0]->setImage(img_horWall);
		walls[1]->setImage(img_horWall);
		Image * img_verWall = RenderManager::GetInstance().getImageByName("img_verWall");
		walls[2]->setImage(img_verWall);
		walls[3]->setImage(img_verWall);
	}

	void GameManager::initPlayer()
	{
		//create the enemy
		enemy = new Enemy("obj_enemy", 200, 100, 0, 20, 20);
		Image* img_DotE = RenderManager::GetInstance().getImageByName("img_enemy");
		enemy->setImage(img_DotE);

		//create the player
		player = new Player("obj_dot", 25, 25, 0, 20, 20);
	}

	void GameManager::loadMedia()
	{
		//load the images for the environment
		RenderManager::GetInstance().addImage("images/horWall.jpg", "img_horWall");
		RenderManager::GetInstance().addImage("images/verWall.jpg", "img_verWall");
		//load Music and sound effects
		SoundManager::GetInstance().loadEffect("sound/high.wav", "sound_1");
		SoundManager::GetInstance().loadMusic("sound/beat.wav", "music_1");
		//the image for the player & enemy
		RenderManager::GetInstance().addImage("images/dot.bmp", "player");
		RenderManager::GetInstance().addImage("images/manzana.jpg", "img_enemy");
		//GUI
		RenderManager::GetInstance().addImage("images/snakeMenu.png", "menu");
		RenderManager::GetInstance().addImage("images/button.png", "img_button");
	}

	void GameManager::createActions()
	{
		//create some actions
		ActionManager::GetInstance().addAction("up","w");
		ActionManager::GetInstance().getActionByName("up")->addKey("up");
		ActionManager::GetInstance().addAction("down","s");
		ActionManager::GetInstance().getActionByName("down")->addKey("down");
		ActionManager::GetInstance().addAction("left","a");
		ActionManager::GetInstance().getActionByName("left")->addKey("left");
		ActionManager::GetInstance().addAction("right","d");
		ActionManager::GetInstance().getActionByName("right")->addKey("right");
	}

	bool GameManager::update()
	{
		quit = EngineManager::GetInstance().update();
		if (inMenu) 
		{
			quitGamePressed = ActionManager::GetInstance().getPressed("quit");

			if (click) {
				inMenu = false;
				hideMenu();
				player->setActive(true);
			}
		}
		else
		{
			if (enemy->caught(player))
			{
				player->addBody();
				SoundManager::GetInstance().play("sound_1");
			}
			if (InputManager::GetInstance().checkKey("space"))
			{
				SoundManager::GetInstance().toggleMusic();
			}
		}
		return quit;
	}

	GameManager::~GameManager()
	{
	}

	void GameManager::setMenu()
	{
		int screenWidth = RenderManager::GetInstance().SCREEN_WIDTH;
		int screenHeight = RenderManager::GetInstance().SCREEN_HEIGHT;
		// Set the menu button
		menu = new Object("mainMenu", 0, 0, 0, screenWidth, screenHeight);
		Image* menuImage = RenderManager::GetInstance().getImageByName("menu");
		menu->setImage(menuImage);
		button = new Button("obj_but1", "Boton 1", 200, 200, 0, 40, 20);
		Image* img_b = RenderManager::GetInstance().getImageByName("img_button");
		button->setImage(img_b);
		button->setImageHeight(20);
		button->setImageWidth(40);
		button->setFunction(startGame, &click);
	}

	void GameManager::hideMenu()
	{
		menu->destroy();
		button->destroy();
	}

	void GameManager::startGame(bool * c)
	{
		*c = true;
		SoundManager::GetInstance().play("music_1");
	}

	void GameManager::close() {
		SoundManager::GetInstance().close();
		EngineManager::GetInstance().close();
	}