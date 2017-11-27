#pragma once
#include <SDL.h>
#include <string>
#include <stdio.h>
#include <SDL_image.h>
class Image
{
public:
	Image(SDL_Renderer* gRenderer,std::string);
	~Image();
	int height;
	int width;
	float alpha;
	bool visible;
	float scale;
	float x;
	float y;
	SDL_Renderer* gRenderer;
	SDL_Texture* file;
	void render(SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	bool loadFromFile(std::string path);
};

