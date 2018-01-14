#pragma once

#include "Object.h"

class WaterLayer : public Object
{
public:
	WaterLayer();
	WaterLayer(string name, int x, int y, int w, int h, Image* sprite = NULL, int depth = 0);
	~WaterLayer();

	void Reset();

private:
	void update();

	int initialHeight;
	int initialWidth;

	float floatDepth;
	float speed;
};

