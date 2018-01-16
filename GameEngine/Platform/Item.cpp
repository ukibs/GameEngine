#include "Item.h"

Item::Item():Object()
{
}

Item::Item(string name, int x, int y, int depth, float w, float h,Uint8 time) : Object(name, x, y, depth, w, h)
{
	//this->time = time;
	//timer.start();
}


Item::~Item()
{
}
//lo que haria al ser recogida
void Item::collect()
{
	SoundManager::GetInstance().play("sound_1");
}

void Item::update()
{
	/*if (timer.getTicks() >= time) {
		collect();
	}*/
}
