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
	for (collIt = colliders.begin(); collIt != colliders.end(); collIt++) {
		if (collIt->name == name) {
			return &(*collIt);
		}
	}
	return NULL;
}
