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
	vector <Sound*> sounds;

public:
	bool loadMusic(string path,string name);
	bool loadEffect(string path, string name);
	bool init();
	SoundManager();
	~SoundManager();
	void play(string name);
	void stopMusic();
	void toggleMusic();
	void close();
};

