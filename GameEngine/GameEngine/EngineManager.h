#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include <stdio.h>
#include "Singleton.h"
#include "RenderManager.h"
#include "ObjectManager.h"
#include "ActionManager.h"
#include "InputManager.h"
#include "ColliderManager.h"
#include "TimerManager.h"
#include "Button.h"
using namespace std;

class EngineManager : public Singleton<EngineManager>
{
public:
	EngineManager();
	~EngineManager();
	bool start();
	bool update();
	void close();
};

