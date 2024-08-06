#include "Input.h"

Input *Input::getInstance() {
	if (instance == nullptr) {
		instance = new Input();
	}
	return instance;
}

void Input::pollEvents() {
	mouseButtonsDown.clear();
	mouseButtonsUp.clear();
	mouseScroll = 0;

	keysDown.clear();
	keysDownAutorepeat.clear();
	keysUp.clear();
	typedText.clear();

	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_MOUSEMOTION: {
				mousePosition = Vector2f((float)event.motion.x, (float)event.motion.y);
				mouseMotion = Vector2f((float)event.motion.xrel, (float)event.motion.yrel);
				break;
			}
			case SDL_MOUSEBUTTONDOWN: {
				mouseButtonsDown.insert((MouseButton)event.button.button);
				mouseButtonsHeld.insert((MouseButton)event.button.button);
				break;
			}
			case SDL_MOUSEBUTTONUP: {
				mouseButtonsHeld.erase((MouseButton)event.button.button);
				mouseButtonsUp.insert((MouseButton)event.button.button);
				break;
			}
			case SDL_MOUSEWHEEL: {
				mouseScroll = (float)event.wheel.y;
				break;
			}
			case SDL_KEYDOWN: {
				if (event.key.repeat == 0) {
					keysDown.insert((Key)event.key.keysym.sym);
					keysHeld.insert((Key)event.key.keysym.sym);
				} else {
					keysDownAutorepeat.insert((Key)event.key.keysym.sym);
				}
				break;
			}
			case SDL_KEYUP: {
				keysUp.insert((Key)event.key.keysym.sym);
				keysHeld.erase((Key)event.key.keysym.sym);
				break;
			}
			case SDL_TEXTINPUT: {
				std::string text;
				for (size_t i = 0; i < SDL_TEXTINPUTEVENT_TEXT_SIZE && event.text.text[i] != '\0'; i++) {
					text += event.text.text[i];
				}
				typedText = text;
				break;
			}
			case SDL_QUIT: {
				exit(0);
				break;
			}
		}
	}
}

void Input::setMouseMode(Input::MouseMode mode) {
	switch (mode) {
		case MouseMode::VISIBLE:SDL_SetRelativeMouseMode(SDL_FALSE);
			SDL_ShowCursor(SDL_ENABLE);
			break;
		case MouseMode::HIDDEN:SDL_SetRelativeMouseMode(SDL_FALSE);
			SDL_ShowCursor(SDL_DISABLE);
			break;
		case MouseMode::LOCKED:SDL_SetRelativeMouseMode(SDL_TRUE);
			break;
	}
}

bool Input::getMouseButtonDown(Input::MouseButton button) {
	return mouseButtonsDown.find(button) != mouseButtonsDown.end();
}

bool Input::getMouseButtonHeld(Input::MouseButton button) {
	return mouseButtonsHeld.find(button) != mouseButtonsHeld.end();
}

bool Input::getMouseButtonUp(Input::MouseButton button) {
	return mouseButtonsUp.find(button) != mouseButtonsUp.end();
}

bool Input::getKeyDown(Input::Key key, bool allowAutorepeat) {
	bool contains = keysDown.find(key) != keysDown.end();

	if (allowAutorepeat && contains) {
		return true;
	}

	return contains;
}

bool Input::getKeyHeld(Input::Key key) {
	return keysHeld.find(key) != keysHeld.end();
}

bool Input::getKeyUp(Input::Key key) {
	return keysUp.find(key) != keysUp.end();
}

bool Input::mouseInBounds(Bounds2 bounds) {
	return bounds.contains(Input::getInstance()->mousePosition);
}

void Input::setMouseZLevel(uint8_t z) {
	mouseZLevel = z;
}

uint8_t Input::getMouseZLevel() {
	return mouseZLevel;
}