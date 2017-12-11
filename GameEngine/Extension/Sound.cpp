#include "Sound.h"



Sound::Sound()
{
}

Sound::Sound(Mix_Music *music, std::string name)
{
	this->track = music;
	this->name = name;
}

Sound::Sound(Mix_Chunk * effect, std::string name)
{
	this->soundEffect = effect;
	this->name = name;
}

std::string Sound::GetName()
{
	return name;
}


Sound::~Sound()
{
}

void Sound::play()
{
	if (track != NULL) {
		Mix_PlayMusic(track, -1);
	}
	else if (soundEffect != NULL) {
		Mix_PlayChannel(-1, soundEffect, 0);
	}
	
}

void Sound::stop()
{

}
