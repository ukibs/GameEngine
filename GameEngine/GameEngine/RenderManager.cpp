#include "RenderManager.h"



void RenderManager::close()
{
	images.clear();
	//Destroy window    
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

void RenderManager::addToRender(Image* img)
{
	int i = 0;
	for (vector<Image*>::iterator imgIt = imgToRender.begin(); imgIt != imgToRender.end(); imgIt++) {
		if ((*imgIt)->getDepth() <= img->getDepth()) {
			imgToRender.insert(imgIt, img);
			return;
		}
	}
	imgToRender.push_back(img);
}

void RenderManager::render()
{
	vector<Image*>::iterator imgIt = imgToRender.end() - 1;
	for (imgIt; imgIt != imgToRender.begin(); imgIt--) {
		(*imgIt)->render();
	}
	(*imgIt)->render();
}

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

	return success;
}

void RenderManager::postUpdate()
{
	render();
	SDL_RenderPresent(gRenderer);
	imgToRender.clear();
}

void RenderManager::addImage(std::string path,std::string name)
{
	Image* newImage = new Image(gRenderer, path,name);
	images.push_back(newImage);
}

Image * RenderManager::getImageByName(string name)
{
	for (vector<Image*>::iterator imageIt = images.begin(); imageIt != images.end(); imageIt++) {
		if ((*imageIt)->getName()==name) {
			return (*imageIt);
		}
	}
	return NULL;
}

void RenderManager::preUpdate()
{
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);
}

SDL_Renderer* RenderManager::getRenderer()
{
	return gRenderer;
}



