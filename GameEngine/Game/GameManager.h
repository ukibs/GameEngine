#pragma once
#include <vector>
#include <string.h>
// Engine headers

#include "EngineManager.h"

#include "SoundManager.h"

//Game headers
#include "Player.h"
#include "Enemy.h"


namespace Snake
{
	class GameManager
	{
	private:
		Object * walls[4];
		Player * player;
		Enemy * enemy;
		// Menu variable
		bool inMenu;
		bool quitGamePressed;
		Button * button;
		Object * menu;
		bool quit;
		void start();
		bool click;

	public:
		GameManager();
		~GameManager();
		void initWalls();
		void initPlayer();
		void loadMedia();
		void createActions();
		bool update();
		void setMenu();
		void hideMenu();
		static void startGame(bool*);
		void close();
	};
};