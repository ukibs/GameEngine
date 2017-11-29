#pragma once
#include <SDL.h>
#include <string>
#include <stdio.h>
#include <SDL_image.h>
#include <iostream>
using namespace std;
class Image
{
public:
	Image();
	Image(SDL_Renderer* gRenderer,string path, string name,int depth=0,bool visible=false);
	~Image();
	string name;
	int height;
	int width;
	int depth;
	float alpha;
	bool visible;
	float scale;
	//float x;
	//float y;
	SDL_Renderer* gRenderer;
	SDL_Texture* file;
	void render(int x,int y,SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	bool loadFromFile(std::string path);
};
