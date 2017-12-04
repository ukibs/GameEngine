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
	}
	else if(e.type == SDL_KEYUP && e.key.keysym.sym==assignCode)
	{
		pressed = false;
	}
	time = SDL_GetTicks();
}

string key::getName()
{
	return name;
}

bool key::getPressed()
{
	return pressed;
}


key::~key()
{
	
}
