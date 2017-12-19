#pragma once
#include <SDL.h>
#include <string>
#include <stdio.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL_ttf.h>
using namespace std;
class Text
{
private:
	//Globally used font
	TTF_Font *gFont = NULL;
	string text;
	string name;
	int height;
	int width;
	int depth;
	float alpha;
	bool visible;
	float scale;
	SDL_Renderer* gRenderer;
	SDL_Texture* file;

public:
	Text();
	Text(SDL_Renderer* gRenderer, string text, string name,TTF_Font* font, int depth = 0, bool visible = false);
	~Text();
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	//Creates image from font string
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor = { 0,0,0 });
	void free();
	//change the contetnt of the text
	void setText(string newText);
	string getName();
};

