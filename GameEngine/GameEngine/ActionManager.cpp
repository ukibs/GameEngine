#include "ActionManager.h"



ActionManager::ActionManager()
{
}


ActionManager::~ActionManager()
{
}

void ActionManager::addAction(Action action)
{
	actions.push_back(action);
}

void ActionManager::addAction(string name, string keyName) {
	Action newAction(name);
	newAction.addKey(keyName);
	actions.push_back(newAction);
}

void ActionManager::addAction( string name, string keyNames[])
{
	Action newAction(name);
	for (int i=0;i<sizeof(keyNames);i++) {
		newAction.addKey(keyNames[i]);
	}
	actions.push_back(newAction);
}

void ActionManager::removeAction(string name)
{
	for (actionIt = actions.begin(); actionIt != actions.end(); actionIt++) {
		if (actionIt->getAction()==name) {
			//hay que probarlo!!
			actions.erase(actionIt);
		}
	}
}

void ActionManager::update()
{
	for (actionIt = actions.begin(); actionIt != actions.end(); actionIt++) {
		actionIt->update();
	}
}

bool ActionManager::getDown(string name)
{
	for (actionIt = actions.begin(); actionIt != actions.end(); actionIt++) {
		if (actionIt->getAction() == name) {
			return actionIt->getDown();
		}
	}
	printf("no existe la accion");
	return false;
}

bool ActionManager::getPressed(string name)
{
	for (actionIt = actions.begin(); actionIt != actions.end(); actionIt++) {
		if (actionIt->getAction() == name) {
			return actionIt->getPressed();
		}
	}
	printf("no existe la accion");
	return false;
}

bool ActionManager::getReleased(string name)
{
	for (actionIt = actions.begin(); actionIt != actions.end(); actionIt++) {
		if (actionIt->getAction() == name) {
			return actionIt->getReleased();
		}
	}
	printf("no existe la accion");
	return false;
}

Action* ActionManager::getActionByName(string name)
{
	for (actionIt = actions.begin(); actionIt != actions.end(); actionIt++) {
		if (actionIt->getAction() == name) {
			return &(*actionIt);
		}
	}
	printf("no existe la accion");
	return NULL;
}
