#pragma once
#include <vector>
#include "Collider.h"
#include "Singleton.h"
using namespace std;

class ColliderManager : public Singleton<ColliderManager>
{
private:
	vector<Collider*> colliders;
	
public:
	ColliderManager();
	~ColliderManager();
	void addCollider(string name, string tag, float x, float y, float w, float h);
	Collider* getColliderByName(string name);
	bool anyCollision(Collider check);
	string getCollisionName(Collider check);
	string getCollisionTag(Collider check);
	void destroyCollider(string name);
};

