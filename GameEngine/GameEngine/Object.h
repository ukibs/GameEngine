#pragma once
#include <string>
#include <vector>
#include "Image.h"
#include "RenderManager.h"

using namespace std;
class Object
{
public:
	Object();
	Object(string name,int x,int y,int depth=0);
	~Object();
	string name;
	string tag;
	int x;
	int y;
	//vector <Image*> images;
	Image image;
	int depth;
	void start();
	void update();
	void addImage(string path,string name);
	void setImage(Image* newImage);
};

