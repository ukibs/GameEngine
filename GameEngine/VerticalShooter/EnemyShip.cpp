#include "TimerManager.h"

#include "EnemyShip.h"



EnemyShip::EnemyShip(string name, int x, int y, int w, int h, Image* sprite, int depth) : Object(name, x, y, depth, w, h)
{
	setImage(sprite);
	//this.depth = depth;
	alive = false;
}


EnemyShip::~EnemyShip()
{
}

void EnemyShip::Activate()
{
	alive = true;
	y = -50;
	x = rand() % (int)(RenderManager::GetInstance().SCREEN_WIDTH - width);
	//cout << "Activating: " << x << ", " << y << endl;
}

void EnemyShip::Kill()
{
	alive = false;
	x = -100;
	y = -100;
}



void EnemyShip::update() {
	if (alive){
		y += speed;
		if (y > RenderManager::GetInstance().SCREEN_HEIGHT + 10) {
			Kill();
		}
	}
}