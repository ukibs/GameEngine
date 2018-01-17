#include "Item.h"

Item::Item():Object()
{
}

Item::Item(string name, int x, int y, int depth, float w, float h,int time) : Object(name, x, y, depth, w, h)
{
	this->time = time;
	timer.start();
}


Item::~Item()
{
}

void Item::update() {
	if (time <= timer.getTicks()) {
		kill();
	}
}

//lo que haria al ser recogida
void Item::collect()
{
	SoundManager::GetInstance().play("sound_1");
}
//lo quita de pantalla
void Item::kill() {
	x = RenderManager::GetInstance().SCREEN_WIDTH;
	y= RenderManager::GetInstance().SCREEN_HEIGHT;
	timer.stop();
}

void Item::restart(int newX, int newY)
{
	x = newX;
	y = newY;
	timer.start();
}
