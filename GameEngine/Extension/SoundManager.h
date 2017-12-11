#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <cstdio>
#include <vector>
#include "Sound.h"
#include "Singleton.h"
using namespace std;

class SoundManager : public Singleton<SoundManager>
{
private:
	vector <Sound> sounds;
	vector <Sound>::iterator soundIt;
	Mix_Music * gMusic;
	bool init();
	bool loadMedia();
	void close();

public:
	SoundManager();
	~SoundManager();
	void play();
};

