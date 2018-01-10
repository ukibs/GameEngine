#include "ColliderManager.h"



ColliderManager::ColliderManager()
{
}


ColliderManager::~ColliderManager()
{
}

void ColliderManager::addCollider(string name, float x, float y, float w, float h)
{
	Collider* newCollider = new Collider(name, x, y, w, h);
	colliders.push_back(*newCollider);
}

Collider* ColliderManager::getColliderByName(string name)
{
	for (vector<Collider>::iterator collIt = colliders.begin(); collIt != colliders.end(); collIt++) {
		if (collIt->name == name) {
			return &(*collIt);
		}
	}
	return NULL;
}

bool ColliderManager::anyCollision(Collider check)
{
	for (vector<Collider>::iterator collIt = colliders.begin(); collIt != colliders.end(); collIt++)
	{
		if(check.checkCollision(collIt->getCollider()) && check.name != collIt->name)
		{
			return true;
		}
	}
	return false;
}

string ColliderManager::getCollisionName(Collider check)
{
	for (vector<Collider>::iterator collIt = colliders.begin(); collIt != colliders.end(); collIt++)
	{
		if (check.checkCollision(collIt->getCollider()) && check.name != collIt->name)
		{
			return collIt->name;
		}
	}
	return "";
}

void ColliderManager::destroyCollider(string name)
{
	for (vector<Collider>::iterator collIt = colliders.begin(); collIt != colliders.end(); collIt++)
	{
		if (name == collIt->name)
		{
			colliders.erase(collIt);
			return;
		}
	}
	return;
}
