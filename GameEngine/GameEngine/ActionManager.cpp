#include "ActionManager.h"



ActionManager::ActionManager()
{
}


ActionManager::~ActionManager()
{
	actions.clear();
}

void ActionManager::addAction(Action action)
{
	actions.push_back(action);
}

void ActionManager::addAction(string name, string keyName) 
{
	Action newAction(name);
	newAction.addKey(keyName);
	actions.push_back(newAction);
}

void ActionManager::addAction(string name,int numKeys, string keyName, ...) {
	Action newAction(name);
	va_list arguments;
	va_start(arguments, keyName);
	for (int i=0; i<numKeys; i++) {
		newAction.addKey(keyName);
		keyName = va_arg(arguments, string);
	}
	newAction.addKey(keyName);
	va_end(arguments);
	actions.push_back(newAction);
}

void ActionManager::removeAction(string name)
{
	for (vector <Action>::iterator actionIt = actions.begin(); actionIt != actions.end(); actionIt++) {
		if (actionIt->getAction()==name) {
			//hay que probarlo!!
			actions.erase(actionIt);
		}
	}
}

void ActionManager::update()
{
	InputManager::GetInstance().keyboardCheck();
	for (vector <Action>::iterator actionIt = actions.begin(); actionIt != actions.end(); actionIt++)
	{
		actionIt->update();
	}
}

bool ActionManager::getDown(string name)
{
	for (vector <Action>::iterator actionIt = actions.begin(); actionIt != actions.end(); actionIt++)
	{
		if (actionIt->getAction() == name) 
		{
			return actionIt->getDown();
		}
	}
	cout << "no existe la accion" << endl;
	return false;
}

bool ActionManager::getPressed(string name)
{
	for (vector <Action>::iterator actionIt = actions.begin(); actionIt != actions.end(); actionIt++) {
		if (actionIt->getAction() == name) {
			return actionIt->getPressed();
		}
	}
	cout << "no existe la accion" << endl;
	return false;
}

bool ActionManager::getReleased(string name)
{
	for (vector <Action>::iterator actionIt = actions.begin(); actionIt != actions.end(); actionIt++) {
		if (actionIt->getAction() == name) {
			return actionIt->getReleased();
		}
	}
	printf("no existe la accion");
	return false;
}

Action* ActionManager::getActionByName(string name)
{
	for (vector <Action>::iterator actionIt = actions.begin(); actionIt != actions.end(); actionIt++) {
		if (actionIt->getAction() == name) {
			return &(*actionIt);
		}
	}
	printf("no existe la accion");
	return NULL;
}
