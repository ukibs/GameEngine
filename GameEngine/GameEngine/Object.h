#pragma once
#include <string>
#include <vector>
#include "Image.h"
#include "ColliderManager.h"
#include "RenderManager.h"

using namespace std;

class Object
{
public:
	Object();
	Object(string name,int x,int y,int depth, float w, float h);
	~Object();
	string name;
	string tag;
	int x;
	int y;
	float width;
	float height;
	Collider collider;
	//vector <Image*> images;
	Image image;
	//Text text;
	int depth;
	void start();
	void postUpdate();
	virtual void update();
	void addImage(string path,string name);
	void addCollider(string name, float x, float y, float w, float h);
	void setImage(Image* newImage);
	//void setText(Text* newText);
	SDL_Rect getCollider();
	bool checkCollision(Object * b,int x,int y);
	bool anyCollision(int x,int y);
	string getCollisionName(int x, int y);
	void destroy();
};

