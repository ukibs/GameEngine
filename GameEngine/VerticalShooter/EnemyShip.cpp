#include "TimerManager.h"

#include "EnemyShip.h"



EnemyShip::EnemyShip(string name, int x, int y, int w, int h, Image* sprite, int depth) : Object(name, x, y, depth, w, h)
{
	setImage(sprite);
	//this.depth = depth;
	alive = false;
	maxHeight = h;
	maxWidth = w;
	speed = 0.07;
}


EnemyShip::~EnemyShip()
{
}

void EnemyShip::Activate()
{
	alive = true;
	y = rand() % (int)(RenderManager::GetInstance().SCREEN_HEIGHT - height);
	x = rand() % (int)(RenderManager::GetInstance().SCREEN_WIDTH - width);
	floatDepth = 10;
	//cout << "Activating: " << x << ", " << y << endl;
}

void EnemyShip::Kill()
{
	alive = false;
	x = -100;
	y = -100;
	//cout << "Deactivating: " << x << ", " << y << endl;
}



void EnemyShip::update() {
	if (alive){
		y -= speed / 2;
		floatDepth -= speed;
		depth = floatDepth;
		//cout << depth << ", " << floatDepth << endl;
		//if (y > RenderManager::GetInstance().SCREEN_HEIGHT + 10) {
		if(depth <= 0){
			Kill();
		}
		else {
			image.setWidth(maxWidth / depth);
			image.setHeight(maxHeight / depth);
		}
 	}
}