#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <string>

class Sound
{
private:
	Mix_Music * track;
	Mix_Chunk * soundEffect;
	bool loop;
	float duration;
	std::string name;
public:
	Sound();
	Sound(Mix_Music *music, std::string name);
	Sound(Mix_Chunk *effect, std::string name);
	std::string GetName();
	void play();
	void stop();
	void destroy();
	~Sound();
};

