#pragma once
#include <SDL.h>
//#include <SDL_mixer.h>
#include <SDL_audio.h>
#include <stdio.h>
#include <string>
#include <cstdio>
#include <vector>
#include "Sound.h"
using namespace std;

class SoundManager
{
private:
	vector <Sound> sounds;
	vector <Sound>::iterator soundIt;
public:
	SoundManager();
	~SoundManager();
};

