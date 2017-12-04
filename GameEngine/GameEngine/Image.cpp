#include "Image.h"



Image::Image()
{
}

Image::Image(SDL_Renderer * gRendererRef, string path, string name,int depth,bool visible)
{
	gRenderer = gRendererRef;
	if (loadFromFile(path)) {
		cout << "Good";
	}
	this->name = name;
	this->depth = depth;
}

Image::~Image()
{
}

void Image::render(int x, int y,SDL_Rect * clip, double angle, SDL_Point * center, SDL_RendererFlip flip)
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
