#pragma once
#include <SDL.h>

class Sound
{
private:
	//Mix_Music * track;
	bool loop;
	float duration;
public:
	Sound();
	void play();
	void stop();
	~Sound();
};

