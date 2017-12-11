#pragma once
#include <SDL.h>
#include "Timer.h"
#include "Singleton.h"
class TimerManager : public Singleton<TimerManager>
{
public:
	//Initializes variables
	TimerManager();
	~TimerManager();

	void init();
	void update();
	float getFPS();


private:
	//Frames per second timer
	Timer fpsTimer;
	float avgFPS;
	int countedFrames;

};

