#include "TimerManager.h"

TimerManager::TimerManager()
{
	init();
}

TimerManager::~TimerManager()
{
	fpsTimer.~Timer();
}

void TimerManager::init()
{
	fpsTimer.start();
	avgFPS = 0;
	countedFrames = 0;
}

void TimerManager::update()
{
	avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
	if (avgFPS > 2000000)
	{
		avgFPS = 0;
	}
	countedFrames++;
}

float TimerManager::getFPS()
{
	return avgFPS;
}
