#pragma once
#include <string>
#include <SDL.h>

using namespace::std;
class key
{
private:
	string name;
	SDL_Keycode assignCode;
	string ascii;
	float time;
	bool pressed;
public:
	key(string, SDL_Keycode, string);
	void updateData(SDL_Event&);
	string getName();
	bool getPressed();
	~key();
};

