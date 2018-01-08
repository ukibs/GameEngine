#include "Item.h"

Item::Item(string name, int x, int y, int depth, float w, float h) : Object(name, x, y, depth, w, h)
{
}


Item::~Item()
{
}
//lo que haria al ser recogida
void Item::collect()
{
	SoundManager::GetInstance().play("sound_1");
}
