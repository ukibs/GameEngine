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
	void setImage(Image* newImg) { image = newImg; };
	void setText(string newTxt) { text->setText(newTxt); };
	void update();
	void onClick();
	void onOver();
private:
	Image* image;
	Text* text;
	SDL_Renderer* gRenderer;
	SDL_Rect area;
};

