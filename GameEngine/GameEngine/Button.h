#pragma once
#include "Text.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "Object.h"
class Button: public Object
{
public:
	Button(string name, string text, int x, int y, int depth, float w, float h);
	~Button();
	void setText(string newTxt) { text->setText(newTxt); };
	void update();
	void onClick();
	void onOver();
	Image getImage() { return image; };
	void destroy();
private:
	Text* text;
	SDL_Rect area;
};

