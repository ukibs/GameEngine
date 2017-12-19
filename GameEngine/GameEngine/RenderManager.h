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
	TTF_Font* gFont;
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	SDL_Renderer* gRenderer;
	SDL_Window* gWindow = NULL;

	vector<Image> images;
	vector<Image>::iterator imageIt;
	vector<Text> texts;
	vector<Text>::iterator textIt;

public:
	RenderManager();
	~RenderManager();

	bool init();
	void postUpdate();
	void addImage(string path,string name);
	void addText(string text, string name);

	Image* getImageByName(string name);
	Text* getTextByName(string name);
	void setFont(string path);
	void preUpdate();
};

