#include "WaterLayer.h"



WaterLayer::WaterLayer()
{
}

WaterLayer::WaterLayer(string name, int x, int y, int w, int h, Image * sprite, int depth) : Object(name, x, y, depth, w, h)
{
	setImage(sprite);
	initialHeight = h;
	initialWidth = w;

	speed = 1.5;

	image.setWidth(w);
	image.setHeight(h);
}


WaterLayer::~WaterLayer()
{
}

void WaterLayer::Reset()
{
	x = 0;
	y = RenderManager::GetInstance().SCREEN_HEIGHT - 100;
	depth = 100;
}

void WaterLayer::update()
{
	y += 3;
	//x -= 1;
	floatDepth -= speed;
	depth = floatDepth;

	//image.setWidth(initialWidth + 100 - depth);
	//image.setHeight(initialHeight + 100 - depth);

	if (y > RenderManager::GetInstance().SCREEN_HEIGHT) {
		Reset();
	}
}
