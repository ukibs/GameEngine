#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include <stdio.h>
#include "Singleton.h"
#include "Image.h"
#include <iostream>
using namespace std;

class RenderManager : public Singleton<RenderManager>
{
	friend class Singleton<RenderManager>;
private:
	SDL_Renderer* gRenderer;
	SDL_Window* gWindow = NULL;
	vector<Image*> images;
public:
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	RenderManager();
	~RenderManager();
	bool init();
	void postUpdate();
	void addImage(string path,string name);
	Image* getImageByName(string name);
	void preUpdate();
	SDL_Renderer* getRenderer();
	void close();
};

