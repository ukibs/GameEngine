#include "ColliderManager.h"



ColliderManager::ColliderManager()
{
}


ColliderManager::~ColliderManager()
{
}

void ColliderManager::addCollider(string name, string tag, float x, float y, float w, float h)
{
	Collider* newCollider = new Collider(name, tag, x, y, w, h);
	colliders.push_back(newCollider);
}

Collider* ColliderManager::getColliderByName(string name)
{
	for (vector<Collider*>::iterator collIt = colliders.begin(); collIt != colliders.end(); collIt++) {
		if ((*collIt)->getName() == name) {
			return *collIt;
		}
	}
	return NULL;
}

bool ColliderManager::anyCollision(Collider check)
{
	for (vector<Collider*>::iterator collIt = colliders.begin(); collIt != colliders.end(); collIt++)
	{
		if(check.checkCollision((*collIt)->getCollider()) && check.getName() != (*collIt)->getName())
		{
			return true;
		}
	}
	return false;
}

string ColliderManager::getCollisionName(Collider check)
{
	for (vector<Collider*>::iterator collIt = colliders.begin(); collIt != colliders.end(); collIt++)
	{
		if (check.checkCollision((*collIt)->getCollider()) && check.getName() != (*collIt)->getName())
		{
			return (*collIt)->getName();
		}
	}
	return "";
}

string ColliderManager::getCollisionTag(Collider check)
{
	for (vector<Collider*>::iterator collIt = colliders.begin(); collIt != colliders.end(); collIt++)
	{
		if (check.checkCollision((*collIt)->getCollider()) && check.getName() != (*collIt)->getName())
		{
			return (*collIt)->getTag();
		}
	}
	return "";
}

void ColliderManager::destroyCollider(string name)
{
	for (vector<Collider*>::iterator collIt = colliders.begin(); collIt != colliders.end(); collIt++)
	{
		if (name == (*collIt)->getName())
		{
			colliders.erase(collIt);
			return;
		}
	}
	return;
}
