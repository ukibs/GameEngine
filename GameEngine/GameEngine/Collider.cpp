#include "Collider.h"
#include "ColliderManager.h"



Collider::Collider()
{
}

Collider::Collider(string name, string tag, int x, int y, int w, int h)
{
	this->name = name;
	this->tag = tag;
	collider.x = x;
	collider.y = y;
	collider.w = w;
	collider.h = h;
}

Collider::~Collider()
{
}

void Collider::Update(int x, int y)
{
	collider.x = x;
	collider.y = y;
}

bool Collider::checkCollision(SDL_Rect b)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = collider.x;
	rightA = collider.x + collider.w;
	topA = collider.y;
	bottomA = collider.y + collider.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;
	
	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}

SDL_Rect Collider::getCollider()
{
	return this->collider;
}

void Collider::destroy()
{
	ColliderManager::GetInstance().destroyCollider(name);
}

bool Collider::anyCollision()
{
	return ColliderManager::GetInstance().anyCollision(*this);
}

string Collider::getCollisionName()
{
	return ColliderManager::GetInstance().getCollisionName(*this);
}

string Collider::getCollisionTag()
{
	return ColliderManager::GetInstance().getCollisionTag(*this);
}

string Collider::getName()
{
	return name;
}

string Collider::getTag()
{
	return tag;
}