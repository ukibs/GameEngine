#pragma once
#include "Item.h"
#include "GameManager.h"
using namespace Platform;
class ItemFinal:public Item
{
public:
	ItemFinal(string name, int x, int y, int depth, float w, float h,GameManager* mng);
	~ItemFinal();
	void collect();
	bool getCollected() { return collected; }
	void update() {};
private:
	GameManager* manager;
	bool collected = false;
};

