#pragma once
#ifndef PLATFORM_H
#define PLATFORM_H
#include "GameManager.h"
#endif
#include "EngineManager.h"
#include "Item.h"
#include <random>
#include "JumpMan.h"
#include <vector>
namespace Platform {
	const int maxLevels = 3;
	const int maxPlatf = 10;
	const int maxItems = 10;
	class GameManager : public Object
	{
	public:
		GameManager(string name, int x, int y, int w, int h, int depth = 0);
		~GameManager();
		void reset();
	private:
		vector<Item*> items;
		JumpMan* player;
		vector<Object*> walls;
		vector<Object*> platforms;
		void update() {};
		void initLevel(int nivel);
		void initWalls();
		void initPlatforms(int nivel);
		void initItems(int nivel);
		void initPlayer();
		void cleanPlatforms();
		void cleanItems();
		void loadMedia();
		int level = 0;
		//info for the location of the platforms(x,y)
		int lvlsP[maxLevels][maxPlatf][2] = { 
				{ { 100,400 },{ 300,400 },{ 500,400 } } ,
				{ { 100,400 },{ 200,400 },{ 300,400 },{ 400,400 },{ 500,400 },{ 300,300 } },
				{ { 150,400 },{ 300,400 },{ 450,400 },{ 225,300 },{ 375,300 },{ 300,200 } } };
		//info for the location of the items(x,y), the last one is negative to indicate that its the last one and its for the final item
		int lvlsI[maxLevels][maxItems][3] = {
				{ {100,370} , {300,370 } , {500,370 } , {-300,-300} },
				{ {100,370 } , {200,370 } , {300,370 } , {400,370 } , {500,370 } , {-300,-270} },
				{ { 150,370 },{ 300,370 },{ 450,370 },{ 225,270 },{ 375,270 },{ -300,-170 } } };
		//list of the item images
		vector<string> imgNames;
		//random
		random_device rd;
		void initPull();
	};
};

