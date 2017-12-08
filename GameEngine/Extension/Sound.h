#pragma once
#include <SDL.h>

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

