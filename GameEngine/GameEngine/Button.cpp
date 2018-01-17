#include "Button.h"



Button::Button(string name, string text, int x, int y, int depth, float w, float h):Object(name,x,y,depth,0,0)
{
	this->text = new Text(text, name, x, y, w, h, depth, true);
	area.x = x;
	area.y = y;
	area.w = w;
	area.h = h;
}


Button::~Button()
{
}

void Button::update() {
	int mouseX = InputManager::GetInstance().getMouseX();
	int mouseY = InputManager::GetInstance().getMouseY();
	if (area.x >= mouseX && area.x + area.w <= mouseX && area.y >= mouseY && area.y + area.y <= mouseY) {
		if (InputManager::GetInstance().getLeftMousePressed) {
			onClick();
		}
		else {
			onOver();
		}
	}
	image->render(x,y);
}

void Button::onClick() {
	cout << name << " ha sido clickado\n";
}

void Button::onOver() {
	cout << name << " tiene el raton encima\n";
}