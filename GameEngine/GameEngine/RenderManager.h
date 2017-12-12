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

class RenderManager : public Singleton<RenderManager>
{
	friend class Singleton<RenderManager>;
public:
	RenderManager();
	~RenderManager();
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	bool init();
	void postUpdate();
	void addImage(std::string path,std::string name);
	void addText(std::string text, std::string name);
	SDL_Renderer* gRenderer;
	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;
	std::vector<Image> images;
	std::vector<Image>::iterator imageIt;
	std::vector<Text> texts;
	std::vector<Text>::iterator textIt;
	Image* getImageByName(string name);
	Text* getTextByName(string name);
	void setFont(string path);
	void preUpdate();
private:
	TTF_Font* gFont;
};

