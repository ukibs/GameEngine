#include "Text.h"



Text::Text()
{
}


Text::Text(SDL_Renderer * gRendererRef, string text, string name,TTF_Font* font, int depth, bool visible)
{
	gRenderer = gRendererRef;
	gFont = font;
	//For now only black text
	if (loadFromRenderedText(name)) {
		cout << "Good";
	}
	this->name = name;
	this->depth = depth;
}

Text::~Text()
{
}

void Text::render(int x, int y, SDL_Rect * clip, double angle, SDL_Point * center, SDL_RendererFlip flip)
{
	//set rendering space and render to screen
	SDL_Rect renderQuad = { x,y,width,height };
	//set clip rendering dimensions
	if (clip != NULL) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	//Render to screen
	SDL_RenderCopyEx(gRenderer, file, clip, &renderQuad, angle, center, flip);
}

bool Text::loadFromRenderedText(std::string textureText, SDL_Color textColor)
{
	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
	if (textSurface != NULL)
	{
		//Create texture from surface pixels
		file = SDL_CreateTextureFromSurface(gRenderer, textSurface);
		if (file == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get image dimensions
			width = textSurface->w;
			height = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}
	else
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}


	//Return success
	return file != NULL;
}
void Text::free()
{
	//Free texture if it exists
	if (file != NULL)
	{
		SDL_DestroyTexture(file);
		file = NULL;
		width = 0;
		height = 0;
	}
}
void Text::setText(string newText)
{
	free();
	loadFromRenderedText(newText);
}

string Text::getName()
{
	return name;
}
