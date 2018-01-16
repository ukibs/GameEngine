#include <stdlib.h> 

#include "Proyectile.h"

Proyectile::Proyectile(string name, int x, int y, int w, int h, Image* sprite, int depth) : Object(name, x, y, depth, w, h)
{
	setImage(sprite);
	//this.depth = depth;
	alive = false;
	maxHeight = h;
	maxWidth = w;
	speed = 0.07;
}


Proyectile::~Proyectile()
{
}

void Proyectile::Activate(int playerX, int playerY)
{
	alive = true;
	y = playerY;
	x = playerX;
	floatDepth = 1;
	//cout << "Activating: " << x << ", " << y << endl;
}

void Proyectile::Kill()
{
	alive = false;
	x = -100;
	y = -100;
	//cout << "Deactivating: " << x << ", " << y << endl;
}



void Proyectile::update() {
	// If it's active
	if (alive) {
		//y = speed * 10;
		floatDepth += speed;
		depth = floatDepth;
		//cout << depth << ", " << floatDepth << endl;
		//if (y > RenderManager::GetInstance().SCREEN_HEIGHT + 10) {
		if (depth >= 10){
			Kill();
		}
		else {
			image.setWidth(maxWidth / depth);
			image.setHeight(maxHeight / depth);
		}

	}
}

int Proyectile::CheckCollisionsWithEnemies(vector<EnemyShip*> enemyShips)
{
	vector<EnemyShip*>::iterator esIT;
	for (esIT = enemyShips.begin(); esIT < enemyShips.end(); esIT++) {
		if (checkCollision(*esIT, x, y)){ 
			int distance = abs((*esIT)->getDepth() - depth);
			if (distance <= 1) {
				cout << "Impact on " << (*esIT)->getName() << endl;
				(*esIT)->Kill();
				Kill();
				return 100;
			}
		}
	}
	return 0;
}