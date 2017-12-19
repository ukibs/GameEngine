#pragma once
#include <string>
#include <vector>
#include "Image.h"
#include "Text.h"
#include "ColliderManager.h"
#include "RenderManager.h"

using namespace std;

class Object
{
protected:
	string name;
	string tag;
	int x;
	int y;
	float width;
	float height;
	Collider collider;
	//vector <Image*> images;
	Image image;
	Text text;
	int depth;

public:
	Object();
	Object(string name,int x,int y,int depth, float w, float h);
	~Object();
	void start();
	void postUpdate();
	virtual void update();
	void addImage(string path,string name);
	void addCollider(string name, int x, int y, float w, float h);
	void setImage(Image* newImage);
	void setText(Text* newText);
	SDL_Rect getCollider();
	bool checkCollision(Object * b);
	bool anyCollision();
	string getName();
};

