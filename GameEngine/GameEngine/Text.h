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
public:
	Text();
	Text(string text, string name, int x, int y, float w, float h, int depth, bool visible);	
	//change the contetnt of the text
	void setText(string newText);
	void setFont(string path);
	~Text();
private:
	//Globally used font
	TTF_Font *gFont = NULL;
	string text;
	void update();
	SDL_Renderer* gRenderer;
	SDL_Texture* file;
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	//Creates image from font string
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor = { 0,0,0 });
	void free();
	
	float alpha;
	bool visible;
	float scale;
};

