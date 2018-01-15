#pragma once
#include <string>
#include <vector>
#include "Image.h"
#include "ColliderManager.h"
#include "RenderManager.h"

using namespace std;

class Object
{
protected:
	string name;
	string tag;
	float width;
	float height;
	Collider* collider;
	Image image;
	int depth;
public:
	int x;
	int y;
	Object();
	Object(string name,int x,int y,int depth, float w, float h, string tag = "");
	~Object();
	void start();
	void postUpdate();
	virtual void update();
	void addImage(string path,string name);
	void addCollider(string name, string tag, float x, float y, float w, float h);
	void setImage(Image* newImage);
	SDL_Rect getCollider();
	bool checkCollision(Object * b,int x,int y);
	bool anyCollision(int x,int y);
	string getCollisionName(int x, int y);
	string getCollisionTag(int x, int y);
	void destroy();
	string getName();
};

