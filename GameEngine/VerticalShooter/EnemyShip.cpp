#include "TimerManager.h"

#include "EnemyShip.h"



EnemyShip::EnemyShip(string name, int x, int y, int w, int h, Image* sprite, int depth) : Object(name, x, y, depth, w, h)
{
	setImage(sprite);
	image.setWidth(w);
	image.setHeight(h);
	//this.depth = depth;
	alive = false;
	maxHeight = h;
	maxWidth = w;
	speed = 0.03;
}


EnemyShip::~EnemyShip()
{
}

void EnemyShip::Activate()
{
	alive = true;
	floatY = rand() % (int)(RenderManager::GetInstance().SCREEN_HEIGHT - height - 100);
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
		// "Descending" movement
		floatY += speed * 2;
		y = floatY;
		// Movement in z
		floatDepth -= speed;
		depth = floatDepth;
		image.setDepth(depth);
		// Check to "get bigger" or deactivate
		if(depth <= 0){
			Kill();
		}
		else {
			// Image
			image.setWidth(maxWidth / depth);
			image.setHeight(maxHeight / depth);
			// Collider
			collider->SetHeight(maxHeight / depth);
			collider->SetWidth(maxWidth / depth);
		}
 	}
}