#include "EngineManager.h"



EngineManager::EngineManager()
{
}


EngineManager::~EngineManager()
{
}

bool EngineManager::start()
{
	//Create the managers
	
	TimerManager::CreateSingleton();
	InputManager::CreateSingleton();
	ActionManager::CreateSingleton();
	ColliderManager::CreateSingleton();
	ObjectManager::CreateSingleton();
	RenderManager::CreateSingleton();
	
	
	//Initialize SDL
	if (!RenderManager::GetInstance().init())
	{
		printf("Failed to initialize!\n");
		return false;
	}
	return true;
}

bool EngineManager::update()
{
	TimerManager::GetInstance().update();
	ActionManager::GetInstance().update();
	RenderManager::GetInstance().preUpdate();
	ObjectManager::GetInstance().update();
	RenderManager::GetInstance().postUpdate();
	
	return InputManager::GetInstance().checkQuit();;
}

void EngineManager::close()
{
	RenderManager::GetInstance().close();
	RenderManager::DestroySingleton();
	ObjectManager::GetInstance().close();
	ObjectManager::DestroySingleton();
	ColliderManager::GetInstance().close();
	ColliderManager::DestroySingleton();
	ActionManager::GetInstance().close();
	ActionManager::GetInstance();
	InputManager::GetInstance().close();
	InputManager::DestroySingleton();
	//TimerManager::GetInstance().close();
	TimerManager::DestroySingleton();
}
