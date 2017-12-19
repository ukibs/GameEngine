#pragma once
#include <SDL.h>
#include <string>
#include <iostream>
using namespace std;

class Collider
{
private:
	SDL_Rect collider;
	string name;

public:
	Collider();
	Collider(string name, int x, int y, int w, int h);
	~Collider();

	bool checkCollision(SDL_Rect b);
	bool anyCollision();
	void Update(int x, int y);
	SDL_Rect getCollider();
	string getName();
};

