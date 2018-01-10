#pragma once
#include <SDL.h>
#include <string>
#include <stdio.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL_ttf.h>
#include "Object.h"
using namespace std;
class Text:public Object
{
private:
	TTF_Font *gFont = NULL;
	string text;
	SDL_Renderer* gRenderer;
	SDL_Texture* file;
	float alpha;
	bool visible;
	float scale;
	void update();
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	bool loadFromRenderedText(string textureText, SDL_Color textColor = { 0,0,0 });
	void free();
public:
	Text();
	Text(string text, string name, int x, int y, float w, float h, int depth, bool visible);	
	~Text();
	void setText(string newText);
	void setFont(string path);
};

