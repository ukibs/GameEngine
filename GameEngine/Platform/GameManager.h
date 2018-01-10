#pragma once
#include "Object.h"
#include "Item.h"
#include "JumpMan.h"
#include <vector>
namespace Platform {
	class GameManager : public Object
	{
	public:
		GameManager(string name, int x, int y, int w, int h, int depth = 0);
		~GameManager();
	private:
		vector<Item*> items;
		JumpMan* player;
		vector<Object*> platforms;
		virtual void update();
		void initWalls();
		void initPlatforms();
		void initItems();
		void initPlayer();
	};
}

