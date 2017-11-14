#include "key.h"



key::key(string nam, SDL_Keycode code)
{
	name = nam;
	assignCode = code;
	time = 0.0f;
	pressed = false;
}

void key::updateData(SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN && e.key.keysym.sym == assignCode)
	{
		pressed = true;
	}
	else
	{
		pressed = false;
	}
	time = SDL_GetTicks();
}


key::~key()
{
}
