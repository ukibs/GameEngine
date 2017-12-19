#include "ColliderManager.h"



ColliderManager::ColliderManager()
{
}


ColliderManager::~ColliderManager()
{
}

void ColliderManager::addCollider(string name, int x, int y, float w, float h)
{
	Collider* newCollider = new Collider(name, x, y, w, h);
	colliders.push_back(*newCollider);
}

Collider* ColliderManager::getColliderByName(string name)
{
	for (collIt = colliders.begin(); collIt != colliders.end(); collIt++) {
		if (collIt->getName() == name) {
			return &(*collIt);
		}
	}
	return NULL;
}

bool ColliderManager::anyCollision(Collider check)
{
	for (collIt = colliders.begin(); collIt != colliders.end(); collIt++) 
	{
		if(check.checkCollision(collIt->getCollider()) && check.getName() != collIt->getName())
		{
			return true;
		}
	}
	return false;
}
