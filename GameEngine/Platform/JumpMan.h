#pragma once
#include "Object.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "ActionManager.h"
#include <vector>
class JumpMan: public Object
{
public:
	JumpMan();
	JumpMan(string name, int x,int y,int w, int h, Image* sprite = NULL,int depth=0, int xSpeed=1,int ySpeed=0,int jumpSpeed=1,int gravity=1);
	void update();
	int getSpeed();
	void setSpeed(int newSpeed);
	int getJumpSpeed();
	void setJumpSpeed(int newJump);
	int getGravity();
	void setGravity(int newG);
	void addImage(Image * newImage);
	void setPlatforms(Object ** platforms,int numP);
	~JumpMan();
private:
	vector<Object*>  platforms;
	vector<Object*>::iterator pltIt;
	int xSpeed;
	int ySpeed;
	int jumpSpeed;
	bool jumping;
	int gravity;
	Image * sprite;
	bool checkIfCollision(int x,int y);
};

