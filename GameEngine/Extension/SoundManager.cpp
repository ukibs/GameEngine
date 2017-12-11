#include "SoundManager.h"



SoundManager::SoundManager()
{
	init();
	loadMedia();
}


SoundManager::~SoundManager()
{
}

bool SoundManager::init()
{
	bool success;
	//Initialize SDL
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
		/*//Initialize PNG loading
		int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		success = false;
	}*/

	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	return success;
}

bool SoundManager::loadMedia()
{
	//Loading success flag
	bool success = true;

	/*//Load prompt texture
	if (!gPromptTexture.loadFromFile("21_sound_effects_and_music/prompt.png"))
	{
		printf("Failed to load prompt texture!\n");
		success = false;
	}*/

	//Load music
	gMusic = Mix_LoadMUS("sound/beat.wav");
	if (gMusic == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	return success;
}

void SoundManager::close()
{

	//Free the music
	Mix_FreeMusic(gMusic);
	gMusic = NULL;

	//Quit SDL subsystems
	Mix_Quit();
}

void SoundManager::play()
{
	Mix_PlayMusic(gMusic, -1);
}