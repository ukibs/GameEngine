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

void ActionManager::addAction(string name, string keyName, ...)
{
	Action newAction(name);
	va_list arguments;
	for (va_start(arguments, keyName); !keyName.empty(); keyName = va_arg(arguments, string)) {
		newAction.addKey(keyName);
	}
	va_end(arguments);
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
