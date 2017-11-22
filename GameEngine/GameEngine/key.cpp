#include "key.h"
#include <cstdio>
#include <iostream>



key::key(string nam, SDL_Keycode code, string asci)
{
	name = nam;
	assignCode = code;
	time = 0.0f;
	pressed = false;
	ascii = asci;
}

void key::updateData(SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN && e.key.keysym.sym == assignCode)
	{
		pressed = true;
		cout << name << ": " << pressed;
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
