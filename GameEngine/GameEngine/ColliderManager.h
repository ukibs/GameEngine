#pragma once
#include <vector>
#include "Collider.h"
#include "Singleton.h"
using namespace std;

class ColliderManager : public Singleton<ColliderManager>
{
private:
	vector<Collider> colliders;
	vector<Collider>::iterator collIt;

public:
	ColliderManager();
	~ColliderManager();

	void addCollider(string name, int x, int y, float w, float h);
	Collider* getColliderByName(string name);
	bool anyCollision(Collider check);
};

