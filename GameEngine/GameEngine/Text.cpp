#include "Text.h"
#include "RenderManager.h"


Text::Text()
{
}

Text::Text(string text, string name, int x, int y, float w, float h, int depth, bool visible):Object(name, x, y, depth, w, h)
{
	gRenderer = RenderManager::GetInstance().getRenderer();
	this->text = text;
	this->visible = visible;
	setFont("./Config/OpenSans-Bold.ttf");
	loadFromRenderedText(text);
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

void Text::setFont(string path)
{
	gFont = TTF_OpenFont(path.c_str(), 10);
}

void Text::update()
{
	render(x, y);
}
