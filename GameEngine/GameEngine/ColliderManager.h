#pragma once
#include <vector>
#include "Collider.h"
#include "Singleton.h"
using namespace std;

class ColliderManager : public Singleton<ColliderManager>
{
public:
	ColliderManager();
	~ColliderManager();

	void addCollider(string name, float x, float y, float w, float h);
	vector<Collider> colliders;
	vector<Collider>::iterator collIt;
	Collider* getColliderByName(string name);
	bool anyCollision(Collider check);
	string getCollisionName(Collider check);
};

