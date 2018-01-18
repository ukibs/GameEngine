#include "Image.h"
#include "RenderManager.h"


Image::Image()
{
}

Image::Image(SDL_Renderer * gRendererRef, string path, string name,int depth,bool visible)
{
	gRenderer = gRendererRef;
	if (loadFromFile(path)) {
		cout << "Good\n";
	}
	this->name = name;
	this->depth = depth;
	RenderManager::GetInstance().addImage(this);
}

Image::~Image()
{
	SDL_DestroyTexture(file);
	file = NULL;
}

void Image::setToRender(int x,int y)
{
	this->x = x;
	this->y = y;
	RenderManager::GetInstance().addToRender(this);
}

void Image::render(SDL_Rect * clip, double angle, SDL_Point * center, SDL_RendererFlip flip)
{
	if (visible = true) {
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

bool Image::loadFromFile(std::string path)
{
	//Get rid of preexisting texture
	//free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			width = loadedSurface->w;
			height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	file = newTexture;
	return file != NULL;
}

string Image::getName()
{
	return name;
}
