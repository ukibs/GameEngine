#include "RenderManager.h"



RenderManager::RenderManager()
{
}


RenderManager::~RenderManager()
{
}

bool RenderManager::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}

				//Initialize SDL_ttf
				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}
			}
		}
	}
	if (success) setFont("./Config/OpenSans-Bold.ttf");

	return success;
}

void RenderManager::postUpdate()
{
	SDL_RenderPresent(gRenderer);
}

void RenderManager::addImage(std::string path,std::string name)
{
	Image* newImage = new Image(gRenderer, path,name);
	images.push_back(newImage);
}

void RenderManager::addText(std::string text, std::string name)
{
	Text* newText = new Text(gRenderer, text, name,gFont);
	texts.push_back(*newText);
}

Image * RenderManager::getImageByName(string name)
{
	for (vector<Image*>::iterator imageIt = images.begin(); imageIt != images.end(); imageIt++) {
		if ((*imageIt)->name==name) {
			return (*imageIt);
		}
	}
	return NULL;
}

Text * RenderManager::getTextByName(string name)
{
	for (vector<Text>::iterator textIt = texts.begin(); textIt != texts.end(); textIt++) {
		if (textIt->name == name) {
			return &(*textIt);
		}
	}
	return NULL;
}

void RenderManager::setFont(string path)
{
	gFont = TTF_OpenFont(path.c_str(), 10);
}

void RenderManager::preUpdate()
{
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);
}

