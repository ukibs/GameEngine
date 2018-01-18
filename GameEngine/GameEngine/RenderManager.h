#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include <stdio.h>
#include "Singleton.h"
#include "Image.h"
#include "Text.h"
#include <iostream>
using namespace std;

class RenderManager : public Singleton<RenderManager>
{
	friend class Singleton<RenderManager>;
private:
	SDL_Renderer* gRenderer;
	SDL_Window* gWindow = NULL;
	vector<Image*> images;
	vector<Image*> imgToRender;
	vector<Text*> texts;
	//vector<Text*> textToRender;
	void render();
public:
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	RenderManager();
	~RenderManager();
	bool init();
	void postUpdate();
	void addImage(string path,string name);
	void addText(Text *);
	Image* getImageByName(string name);
	void preUpdate();
	SDL_Renderer* getRenderer();
	void close();
	void addToRender(Image* img);
	//void addToRender(Text* text);
};

