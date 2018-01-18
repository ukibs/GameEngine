#pragma once
#include <SDL.h>
#include <string>
#include <stdio.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL_ttf.h>
//#include "RenderManager.h"
using namespace std;
class Text
{
private:
	int width;
	int height;
	int depth = 0;
	TTF_Font *gFont = NULL;
	string text;
	SDL_Renderer* gRenderer;
	SDL_Texture* file;
	SDL_Color color = { 0,0,0 };
	float alpha;
	bool visible;
	float scale;
	void update();
	//void setToRender(int, int);
	bool loadFromRenderedText(string textureText);
	void free();
public:
	string name;
	int x;
	int y;
	Text();
	Text(string text, string name, int x, int y, float w, float h, int depth, bool visible);	
	~Text();
	void setText(string newText);
	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void setFont(string path, int size = 10);
	void render(SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	// Get/Set operations
	// Width
	int getWidth() { return width; }
	void setWidth(int value) { width = value; }
	// Height
	int getHeight() { return height; }
	void setHeight(int value) { height = value; }
	void destroy();
};

