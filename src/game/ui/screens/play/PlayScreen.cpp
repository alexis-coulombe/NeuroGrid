#include "PlayScreen.h"
#include "../../../../engine/Window.h"

PlayScreen::PlayScreen() : GenericScreen() {
	screenContainer = new Container(nullptr, Bounds2((Window::width / 2) - (std::min(Window::width, 1920) / 2), 0, std::min(Window::width, 1920), std::min(Window::height, 1080)));

	inputContainer = new Container(screenContainer, Bounds2(0, 0, (Window::width / 6), Window::height));
	gameContainer = new Container(screenContainer, Bounds2((Window::width / 6), 0, (Window::width / 6) * 4, Window::height));
	outputContainer = new Container(screenContainer, Bounds2((Window::width / 6) * 5, 0, (Window::width / 6), Window::height));
}

PlayScreen::~PlayScreen() {
}

void PlayScreen::init() {
}

void PlayScreen::render() {
	screenContainer->render();
	inputContainer->render();
	gameContainer->render();
	outputContainer->render();
}

void PlayScreen::onWindowResized() {
	screenContainer->setBounds(Bounds2((Window::width / 2) - (std::min(Window::width, 1920) / 2), 0, std::min(Window::width, 1920), std::min(Window::height, 1080)));
	inputContainer->setBounds(Bounds2(0, 0, (Window::width / 6), (int) inputContainer->parentContainer->bounds.size.y));
	gameContainer->setBounds(Bounds2((Window::width / 6), 0, (Window::width / 6) * 4, (int) inputContainer->parentContainer->bounds.size.y));
	outputContainer->setBounds(Bounds2((Window::width / 6) * 5, 0, (Window::width / 6), (int) inputContainer->parentContainer->bounds.size.y));
}