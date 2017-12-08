#pragma once
#include <SDL.h>
#include <string>
#include <iostream>
using namespace std;

class Collider
{
public:
	Collider();
	Collider(string name, int x, int y, int w, int h);
	~Collider();

	SDL_Rect collider;
	string name;

	bool checkCollision(SDL_Rect b);
	void Update(int x, int y);
	SDL_Rect getCollider();
};

