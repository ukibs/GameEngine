#pragma once
#include "SoundManager.h"

class Sound
{
private:
	SDL_AudioFormat track;
	bool loop;
	float duration;
public:
	Sound();
	void play();
	void stop();
	~Sound();
};

