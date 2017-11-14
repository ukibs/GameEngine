#pragma once

#include <string>
#include <SDL.h>
#include <vector>

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
	std::string name;
	//SDL_Keysym key;
	//SDL_Keycode key;
	std::vector <SDL_Keycode> keys;
	std::vector <SDL_Keycode>::iterator keyIt;

	bool down;
	bool pressed;
	bool released;
	bool repeated;
};