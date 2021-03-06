#pragma once
#include <SDL.h>
#include <string>
#include <stdio.h>
#include <SDL_image.h>
#include <iostream>
using namespace std;
class Image
{
private:
	string name;
	int height;
	int width;
	int depth;
	float alpha;
	bool visible;
	float scale;
	SDL_Renderer* gRenderer;
	SDL_Texture* file;
	int x;
	int y;
public:
	Image();
	Image(SDL_Renderer* gRenderer,string path, string name,int depth=0,bool visible=false);
	~Image();
	void setToRender(int x,int y);
	bool loadFromFile(std::string path);
	string getName();
	// Get/Set operations
		// Width
	int getWidth() { return width; }
	void setWidth(int value) { width = value; }
		// Height
	int getHeight() { return height; }
	void setHeight(int value) { height = value; }
		// Depth
	int getDepth() { return depth; };
	void setDepth(int newD) { depth = newD; };
		// Visibility
	bool getVisibility() { return visible; }
	void setVisibility(bool value) { visible = value; }
	// Render
	void render(SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
};

