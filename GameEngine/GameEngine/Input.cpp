
#include "Input.h"

Input::Input() {
	name = "";
	//key = ;
}
Input::Input(std::string kName) {
	name = kName;
}

Input::Input(std::string kName, SDL_Keycode assignedKey, ...) {
	name = kName;
	va_list arguments;
	for (va_start(arguments, assignedKey); assignedKey != NULL; assignedKey = va_arg(arguments, SDL_Keycode)) {
		keys.push_back(assignedKey);
	}
	va_end(arguments);
}

void Input::AddKey(SDL_Keycode assignedKey) {
	keys.push_back(assignedKey);
}

void Input::SetValues(SDL_Event& e) {
	//Reset values
	pressed = false;
	released = false;
	down = false;
	repeated = true;
	//
	for (vector <SDL_Keycode>::iterator keyIt = keys.begin(); keyIt < keys.end(); keyIt++) {
		//
		pressed = pressed || (e.type == SDL_KEYDOWN && e.key.repeat == 0 && e.key.keysym.sym == *keyIt);
		//
		released = released || (e.type == SDL_KEYUP && e.key.repeat == 0 && e.key.keysym.sym == *keyIt);
		//
		down = down || (e.type == SDL_KEYDOWN && e.key.keysym.sym == *keyIt);
		//
		//repeated = repeated && (e.key.repeat > 0 && e.key.keysym.sym == *keyIt);
	}
}

std::string Input::GetName() {
	return name;
}

bool Input::GetDown() {
	return down;
}
bool Input::GetPressed() {
	return pressed;
	//return (down && !repeated);
}
bool Input::GetReleased() {
	return released;
	//return (!down && !repeated);
}