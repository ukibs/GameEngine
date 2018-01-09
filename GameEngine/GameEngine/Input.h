#pragma once

#include <string>
#include <SDL.h>
#include <vector>
using namespace std;

class Input
{
public:
	Input();
	Input(std::string kName);
	Input(std::string kName, SDL_Keycode assignedKey, ...);

	void AddKey(SDL_Keycode assignedKey);

	void SetValues(SDL_Event& e);

	std::string GetName();

	bool GetDown();
	bool GetPressed();
	bool GetReleased();

private:
	string name;
	//SDL_Keysym key;
	//SDL_Keycode key;
	vector <SDL_Keycode> keys;
	//vector <SDL_Keycode>::iterator keyIt;

	bool down;
	bool pressed;
	bool released;
	bool repeated;
};