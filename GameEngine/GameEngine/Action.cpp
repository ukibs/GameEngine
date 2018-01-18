#include "Action.h"

Action::Action(string name)
{
	this->name = name;
}

Action::Action(string name, key* keyToAdd, ...)
{
	this->name = name;
	va_list arguments;
	for (va_start(arguments, keyToAdd); keyToAdd != NULL; keyToAdd = va_arg(arguments, key*)) {
		keys.push_back(keyToAdd);
	}
	va_end(arguments);
}

Action::~Action()
{
	keys.clear();
}

void Action::addKey(string name) 
{
	key* keyToAdd = InputManager::GetInstance().getKey(name);
	if (keyToAdd != NULL) 
	{
		InputManager::GetInstance().changeKeyStatus(keyToAdd->getName());
		keys.push_back(keyToAdd);
	}
}

string Action::getAction()
{
	return name;
}

bool Action::getPressed()
{
	return pressed;
}

bool Action::getDown()
{
	return down;
}

bool Action::getReleased()
{
	return released;
}

void Action::update()
{
	pressed = false;
	down = false;
	released = false;
	for (vector<key*>::iterator keyIt = keys.begin(); keyIt < keys.end(); keyIt++) {
		//
		if ((*keyIt)->getDown()) 
		{
			
			down = true;
			pressed = !prevDown;
			break;
		}
	}
	if (prevDown && !down) {
		released = true;
	}
	prevDown = down;
}
