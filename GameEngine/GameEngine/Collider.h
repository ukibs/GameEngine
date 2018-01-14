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
	string tag;

public:
	Collider();
	Collider(string name, string tag, int x, int y, int w, int h);
	~Collider();

	bool checkCollision(SDL_Rect b);
	bool anyCollision();
	string getCollisionName();
	string getCollisionTag();
	void Update(int x, int y);
	SDL_Rect getCollider();
	string getName();
	string getTag();
	void destroy();
};

