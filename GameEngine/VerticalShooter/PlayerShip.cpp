#include "PlayerShip.h"

PlayerShip::PlayerShip()
{
}

PlayerShip::PlayerShip(string name, int x, int y, int w, int h, Image* sprite, int depth) : Object(name, x, y, depth, w, h)
{
	setImage(sprite);
	image.setWidth(w);
	image.setHeight(h);
	lifes = 3;
}

/*PlayerShip::PlayerShip(string name, int x, int y, int w, int h, GameManager * gameMgr, Image* sprite, int depth) : Object(name, x, y, depth, w, h)
{
	setImage(sprite);
	this->gameMgr = gameMgr;
}*/

PlayerShip::~PlayerShip()
{
}

void PlayerShip::update() 
{
	// Movement
	int newX = x;
	int newY = y;
	if (ActionManager::GetInstance().getDown("right"))
	{
		newX = x + speed;
	}
	if (ActionManager::GetInstance().getDown("left"))
	{
		newX = x - speed;
	}
	if (ActionManager::GetInstance().getDown("up"))
	{
		newY = y - speed;
	}
	if (ActionManager::GetInstance().getDown("down"))
	{
		newY = y + speed;
	}

	// Control to not go out of screen
	if (newY < 0) newY = 0;
	if (newY > RenderManager::GetInstance().SCREEN_HEIGHT - height) newY = RenderManager::GetInstance().SCREEN_HEIGHT - height;
	if (newX < 0) newX = 0;
	if (newX > RenderManager::GetInstance().SCREEN_WIDTH - width) newX = RenderManager::GetInstance().SCREEN_WIDTH - width;

	//cout << "Updating";
	x = newX;
	y = newY;

	// Shooting
	shooting = ActionManager::GetInstance().getPressed("shoot");
}

void PlayerShip::CheckCollisionsWithEnemies(vector<EnemyShip*> enemyShips)
{
	vector<EnemyShip*>::iterator esIT;
	for (esIT = enemyShips.begin(); esIT < enemyShips.end(); esIT++) {
		if (checkCollision(*esIT, x, y) && (*esIT)->getDepth() <= 1){
			cout << "Collision with " << (*esIT)->getName() << endl;
			(*esIT)->Kill();
			LoseLife();
		}
	}
}

void PlayerShip::LoseLife() {
	lifes--;
	if (lifes <= 0) {
		// Game over
	}
	else {
		x = RenderManager::GetInstance().SCREEN_WIDTH / 2 - width;
		y = RenderManager::GetInstance().SCREEN_HEIGHT - 100;
		SoundManager::GetInstance().play("Explosion");
	}
}