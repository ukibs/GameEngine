#include "Text.h"
#include "RenderManager.h"


Text::Text()
{
}

Text::Text(string text, string name, int x, int y, float w, float h, int depth, bool visible)
{
	this->name = name;
	this->x = x;
	this->y = y;
	this->width = w;
	this->height = h;
	//depth

	gRenderer = RenderManager::GetInstance().getRenderer();
	this->text = text;
	this->visible = visible;
	setFont("./Config/OpenSans-Bold.ttf");
	loadFromRenderedText(text);
	RenderManager::GetInstance().addText(this);
}

Text::~Text()
{
	free();
}

void Text::render(SDL_Rect * clip, double angle, SDL_Point * center, SDL_RendererFlip flip)
{
	if (visible) {
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
}

void Text::destroy()
{
	RenderManager::GetInstance().destroyText(this);
	this->~Text();
}

/*void Text::setToRender(int x, int y)
{
	this->x = x;
	this->y = y;
	RenderManager::GetInstance().addToRender(this);
}*/

bool Text::loadFromRenderedText(std::string textureText)
{
	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), color);
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

void Text::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	color = { red,green,blue };
	loadFromRenderedText(text);
}

void Text::setVisible(bool change)
{
	visible = change;
}

void Text::setFont(string path, int size)
{
	gFont = TTF_OpenFont(path.c_str(), size);
}

void Text::update()
{
	//render(x, y);
	//setToRender(x, y);
}
