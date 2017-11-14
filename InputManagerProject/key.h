#pragma once
#include <string>
#include <SDL.h>
using namespace::std;
class key
{
private:
	string name;
	SDL_Keycode assignCode;
	float time;
	bool pressed;
public:
	key(string, SDL_Keycode);
	void updateData(SDL_Event&);
	~key();
};

