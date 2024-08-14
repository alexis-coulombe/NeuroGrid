#ifndef ASM_INPUT_H
#define ASM_INPUT_H

#include "utility/Vector2f.h"
#include "utility/Bounds2.h"
#include <string>
#include <SDL.h>
#include <unordered_set>
#include <mutex>
#include <iostream>

class Input {
 protected:
	static inline Input *instance = nullptr;

	Input() = default;
	~Input() = default;

 public:
	Vector2f mousePosition = Vector2f();
	Vector2f mouseMotion = Vector2f();
	float mouseScroll = 0;
	uint8_t mouseZLevel = 0;
	std::string typedText;
	enum MouseMode {
		VISIBLE,
		HIDDEN,
		LOCKED
	};
	enum MouseButton {
		LEFT = 1,
		MIDDLE = 2,
		RIGHT = 3
	};
	enum Key {
		Return = '\r',
		Escape = 27,
		Backspace = '\b',
		Tab = '\t',
		Space = ' ',
		Exclamation = '!',
		DoubleQuote = '"',
		Hash = '#',
		Percent = '%',
		Dollar = '$',
		Ampersand = '&',
		SingleQuote = '\'',
		LeftParen = '(',
		RightParen = ')',
		Asterisk = '*',
		Plus = '+',
		Comma = ',',
		Minus = '-',
		Period = '.',
		Slash = '/',
		NumRow0 = '0',
		NumRow1 = '1',
		NumRow2 = '2',
		NumRow3 = '3',
		NumRow4 = '4',
		NumRow5 = '5',
		NumRow6 = '6',
		NumRow7 = '7',
		NumRow8 = '8',
		NumRow9 = '9',
		Colon = ':',
		Semicolon = ';',
		Less = '<',
		Equals = '=',
		Greater = '>',
		Question = '?',
		At = '@',
		LeftBracket = '[',
		Backslash = '\\',
		RightBracket = ']',
		Caret = '^',
		Underscore = '_',
		Backquote = '`',
		A = 'a',
		B = 'b',
		C = 'c',
		D = 'd',
		E = 'e',
		F = 'f',
		G = 'g',
		H = 'h',
		I = 'i',
		J = 'j',
		K = 'k',
		L = 'l',
		M = 'm',
		N = 'n',
		O = 'o',
		P = 'p',
		Q = 'q',
		R = 'r',
		S = 's',
		T = 't',
		U = 'u',
		V = 'v',
		W = 'w',
		X = 'x',
		Y = 'y',
		Z = 'z',
		CapsLock = SDL_SCANCODE_CAPSLOCK | SDLK_SCANCODE_MASK,
		F1 = SDL_SCANCODE_F1 | SDLK_SCANCODE_MASK,
		F2 = SDL_SCANCODE_F2 | SDLK_SCANCODE_MASK,
		F3 = SDL_SCANCODE_F3 | SDLK_SCANCODE_MASK,
		F4 = SDL_SCANCODE_F4 | SDLK_SCANCODE_MASK,
		F5 = SDL_SCANCODE_F5 | SDLK_SCANCODE_MASK,
		F6 = SDL_SCANCODE_F6 | SDLK_SCANCODE_MASK,
		F7 = SDL_SCANCODE_F7 | SDLK_SCANCODE_MASK,
		F8 = SDL_SCANCODE_F8 | SDLK_SCANCODE_MASK,
		F9 = SDL_SCANCODE_F9 | SDLK_SCANCODE_MASK,
		F10 = SDL_SCANCODE_F10 | SDLK_SCANCODE_MASK,
		F11 = SDL_SCANCODE_F11 | SDLK_SCANCODE_MASK,
		F12 = SDL_SCANCODE_F12 | SDLK_SCANCODE_MASK,
		PrintScreen = SDL_SCANCODE_PRINTSCREEN | SDLK_SCANCODE_MASK,
		ScrollLock = SDL_SCANCODE_SCROLLLOCK | SDLK_SCANCODE_MASK,
		Pause = SDL_SCANCODE_PAUSE | SDLK_SCANCODE_MASK,
		Insert = SDL_SCANCODE_INSERT | SDLK_SCANCODE_MASK,
		Home = SDL_SCANCODE_HOME | SDLK_SCANCODE_MASK,
		PageUp = SDL_SCANCODE_PAGEUP | SDLK_SCANCODE_MASK,
		Delete = SDL_SCANCODE_DELETE | SDLK_SCANCODE_MASK,
		End = SDL_SCANCODE_END | SDLK_SCANCODE_MASK,
		PageDown = SDL_SCANCODE_PAGEDOWN | SDLK_SCANCODE_MASK,
		Right = SDL_SCANCODE_RIGHT | SDLK_SCANCODE_MASK,
		Left = SDL_SCANCODE_LEFT | SDLK_SCANCODE_MASK,
		Down = SDL_SCANCODE_DOWN | SDLK_SCANCODE_MASK,
		Up = SDL_SCANCODE_UP | SDLK_SCANCODE_MASK,
		NumpadDivide = SDL_SCANCODE_KP_DIVIDE | SDLK_SCANCODE_MASK,
		NumpadMultiply = SDL_SCANCODE_KP_MULTIPLY | SDLK_SCANCODE_MASK,
		NumpadMinus = SDL_SCANCODE_KP_MINUS | SDLK_SCANCODE_MASK,
		NumpadPlus = SDL_SCANCODE_KP_PLUS | SDLK_SCANCODE_MASK,
		NumpadEnter = SDL_SCANCODE_KP_ENTER | SDLK_SCANCODE_MASK,
		Numpad1 = SDL_SCANCODE_KP_1 | SDLK_SCANCODE_MASK,
		Numpad2 = SDL_SCANCODE_KP_2 | SDLK_SCANCODE_MASK,
		Numpad3 = SDL_SCANCODE_KP_3 | SDLK_SCANCODE_MASK,
		Numpad4 = SDL_SCANCODE_KP_4 | SDLK_SCANCODE_MASK,
		Numpad5 = SDL_SCANCODE_KP_5 | SDLK_SCANCODE_MASK,
		Numpad6 = SDL_SCANCODE_KP_6 | SDLK_SCANCODE_MASK,
		Numpad7 = SDL_SCANCODE_KP_7 | SDLK_SCANCODE_MASK,
		Numpad8 = SDL_SCANCODE_KP_8 | SDLK_SCANCODE_MASK,
		Numpad9 = SDL_SCANCODE_KP_9 | SDLK_SCANCODE_MASK,
		Numpad0 = SDL_SCANCODE_KP_0 | SDLK_SCANCODE_MASK,
		NumpadPeriod = SDL_SCANCODE_KP_PERIOD | SDLK_SCANCODE_MASK,
		LeftControl = SDL_SCANCODE_LCTRL | SDLK_SCANCODE_MASK,
		LeftShift = SDL_SCANCODE_LSHIFT | SDLK_SCANCODE_MASK,
		LeftAlt = SDL_SCANCODE_LALT | SDLK_SCANCODE_MASK,
		RightControl = SDL_SCANCODE_RCTRL | SDLK_SCANCODE_MASK,
		RightShift = SDL_SCANCODE_RSHIFT | SDLK_SCANCODE_MASK,
		RightAlt = SDL_SCANCODE_RALT | SDLK_SCANCODE_MASK,
	};

	Input(Input &other) = delete;
	Input operator=(const Input &) = delete;
	static Input *getInstance();

	void pollEvents();
	void setMouseMode(MouseMode mode);
	bool getMouseButtonDown(MouseButton button);
	bool getMouseButtonHeld(MouseButton button);
	bool getMouseButtonUp(MouseButton button);
	bool getKeyDown(Key key, bool allowAutorepeat = false);
	bool getKeyHeld(Key key);
	bool getKeyUp(Key key);
	bool mouseInBounds(Bounds2 bounds);
	void setMouseZLevel(uint8_t z);
	uint8_t getMouseZLevel();

 private:
	std::unordered_set<MouseButton> mouseButtonsDown;
	std::unordered_set<MouseButton> mouseButtonsHeld;
	std::unordered_set<MouseButton> mouseButtonsUp;
	std::unordered_set<Key> keysDown;
	std::unordered_set<Key> keysDownAutorepeat;
	std::unordered_set<Key> keysHeld;
	std::unordered_set<Key> keysUp;
};

#endif //ASM_INPUT_H
