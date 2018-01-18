#include "SoundManager.h"



SoundManager::SoundManager()
{
}


SoundManager::~SoundManager()
{
}

bool SoundManager::init()
{
	bool success=true;
	//Initialize SDL
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}

	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	return success;
}

bool SoundManager::loadMusic(string path,string name)
{
	//Loading success flag
	bool success = true;

	//Load music
	Mix_Music *newMusic;
	newMusic = Mix_LoadMUS(path.c_str());
	if (newMusic == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	} 
	Sound* newSound = new Sound(newMusic,name);
	sounds.push_back(newSound);
	return success;
}

bool SoundManager::loadEffect(string path, string name)
{
	//Loading success flag
	bool success = true;

	//Load music
	Mix_Chunk *newMusic = Mix_LoadWAV(path.c_str());
	if (newMusic == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	} Sound* newSound = new Sound(newMusic, name);
	sounds.push_back(newSound);
	return success;
}

void SoundManager::close()
{
	stopMusic();
	for (vector<Sound*>::iterator soundIt = sounds.begin(); soundIt < sounds.end(); soundIt++) {
		(*soundIt)->destroy();
	}
	
	Mix_CloseAudio();
	// force a quit
	while (Mix_Init(0))
		Mix_Quit();
}

void SoundManager::play(string name)
{
	for (vector<Sound*>::iterator soundIt = sounds.begin(); soundIt != sounds.end(); soundIt++) {
		if ((*soundIt)->GetName() == name) {
			(*soundIt)->play();
		}
	}
}

void SoundManager::stopMusic()
{
	Mix_HaltMusic();
}

void SoundManager::toggleMusic()
{
	if (Mix_PausedMusic() == 0) {
 		Mix_PauseMusic();
	}
	else {
		Mix_ResumeMusic();
	}
}
