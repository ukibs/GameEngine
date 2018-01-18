#include "Button.h"



Button::Button(string name, string text, int x, int y, int depth, float w, float h):Object(name,x,y,depth,w,h)
{
	this->text = new Text(text, "text_"+name, x, y, w, h, depth, true);
	area.x = x;
	area.y = y;
	area.w = w;
	area.h = h;
	buttonClick = defaultFunction;
}

void Button::defaultFunction(bool *a)
{
	cout << "nothing";
}


Button::~Button()
{
	text->~Text();
	Object::destroy();
}

void Button::update() {
	int mouseX =  InputManager::GetInstance().getMouseX();
	int mouseY =  InputManager::GetInstance().getMouseY();
	if ((area.x <= mouseX) && ((area.x + area.w) >= mouseX) && (area.y <= mouseY) && ((area.y + area.h) >= mouseY)) {
		if (InputManager::GetInstance().getLeftMousePressed()) {
			onClick();
		}
		else {
			onOver();
		}
	}
}

void Button::onClick() {
	buttonClick(aux);
	//cout << name << " ha sido clickado\n";
}

void Button::onOver() {
	cout << name << " tiene el raton encima\n";
}

void Button::destroy()
{
	text->destroy();
	Object::destroy();
}

void Button::setFunction(void(*function)(bool*), bool*a)
{
	aux = a;
	buttonClick = function;
}
