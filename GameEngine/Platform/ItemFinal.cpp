#include "ItemFinal.h"

using namespace Platform;

ItemFinal::ItemFinal(string name, int x, int y, int depth, float w, float h,GameManager* mng) : Item(name, x, y, depth, w, h)
{
	manager = mng;
}


ItemFinal::~ItemFinal()
{
}

void ItemFinal::collect()
{
	manager->reset();
}
