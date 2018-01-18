#pragma once
#include <vector>
#include <string.h>
// Engine headers
#include "Object.h"
#include "TimerManager.h"
#include "Text.h"
#include "SoundManager.h"
#include "Button.h"
//Game headers
#include "Player.h"
#include "Enemy.h"


namespace Snake
{
	class GameManager : public Object
	{
	private:
		Object * walls[4];
		Player * player;
		Enemy * enemy;
		// Menu variable
		bool inMenu;
		bool quitGamePressed;
		Button * button;
	public:
		GameManager(string name, int x, int y, int w, int h, int depth = 0);
		~GameManager();
		void initWalls();
		void initPlayer();
		void loadMedia();
		void createActions();
		void update();
		void setMenu();
		void hideMenu();
	};
};