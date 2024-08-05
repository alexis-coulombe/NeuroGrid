#include "PlayScreen.h"
#include "../../../../engine/Window.h"

PlayScreen::PlayScreen() : GenericScreen() {
	screenContainer = new Container(nullptr, Bounds2((Window::width / 2) - (std::min(Window::width, 1920) / 2), 0, std::min(Window::width, 1920), std::min(Window::height, 1080)));

	inputContainer = new Container(screenContainer, Bounds2(0, 0, (std::min(Window::width, 1920) / 6), std::min(Window::height, 1080)));
	gameContainer = new Container(screenContainer, Bounds2((std::min(Window::width, 1920) / 6), 0, (std::min(Window::width, 1920) / 6) * 4, std::min(Window::height, 1080)));
	outputContainer = new Container(screenContainer, Bounds2((std::min(Window::width, 1920) / 6) * 5, 0, (std::min(Window::width, 1920) / 6), std::min(Window::height, 1080)));

	nano1Container = new Container(gameContainer, Bounds2(0, 0, (int) gameContainer->bounds.size.x / 3, (int) gameContainer->bounds.size.y / 4 * 3));
	nano1Textarea = new Nano1Textarea(nano1Container, Vector2(0, 0), 20, 20, Color::WHITE, Color::WHITE, Color::WHITE);
	nano2Container = new Container(gameContainer, Bounds2((int) gameContainer->bounds.size.x / 3, 0, (int) gameContainer->bounds.size.x / 3, (int) gameContainer->bounds.size.y / 4 * 3));
	nano3Container = new Container(gameContainer, Bounds2((int) gameContainer->bounds.size.x / 3 * 2, 0, (int) gameContainer->bounds.size.x / 3, (int) gameContainer->bounds.size.y / 4 * 3));

	missionDescriptionContainer = new Container(gameContainer, Bounds2(0, (int) gameContainer->bounds.size.y / 4 * 3, (int) gameContainer->bounds.size.x, (int) gameContainer->bounds.size.y / 4));

	input1 = new Container(inputContainer, Bounds2(0, 0, (int) inputContainer->bounds.size.x / 3, (int) inputContainer->bounds.size.y));
	input2 = new Container(inputContainer, Bounds2((int) inputContainer->bounds.size.x / 3, 0, (int) inputContainer->bounds.size.x / 3, (int) inputContainer->bounds.size.y));
	input3 = new Container(inputContainer, Bounds2((int) inputContainer->bounds.size.x / 3 * 2, 0, (int) inputContainer->bounds.size.x / 3, (int) inputContainer->bounds.size.y));

	output1 = new Container(outputContainer, Bounds2(0, 0, (int) outputContainer->bounds.size.x / 3, (int) outputContainer->bounds.size.y));
	output2 = new Container(outputContainer, Bounds2((int) outputContainer->bounds.size.x / 3, 0, (int) outputContainer->bounds.size.x / 3, (int) outputContainer->bounds.size.y));
	output3 = new Container(outputContainer, Bounds2((int) outputContainer->bounds.size.x / 3 * 2, 0, (int) outputContainer->bounds.size.x / 3, (int) outputContainer->bounds.size.y));
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

	nano1Container->render();
	nano1Textarea->render(Asset::loadFont((char *)"assets/ModernDOS.ttf", 10));
	nano2Container->render();
	nano3Container->render();

	input1->render();
	input2->render();
	input3->render();

	output1->render();
	output2->render();
	output3->render();
}

void PlayScreen::onWindowResized() {
	screenContainer->setBounds(Bounds2((Window::width / 2) - (std::min(Window::width, 1920) / 2), 0, std::min(Window::width, 1920), std::min(Window::height, 1080)));

	inputContainer->setBounds(Bounds2(0, 0, (std::min(Window::width, 1920) / 6), (int) inputContainer->parentContainer->bounds.size.y));
	gameContainer->setBounds(Bounds2((std::min(Window::width, 1920) / 6), 0, (std::min(Window::width, 1920) / 6) * 4, (int) inputContainer->parentContainer->bounds.size.y));
	outputContainer->setBounds(Bounds2((std::min(Window::width, 1920) / 6) * 5, 0, (std::min(Window::width, 1920) / 6), (int) inputContainer->parentContainer->bounds.size.y));

	nano1Container->setBounds(Bounds2(0, 0, (int) gameContainer->bounds.size.x / 3, (int) gameContainer->bounds.size.y));
	nano2Container->setBounds(Bounds2((int) gameContainer->bounds.size.x / 3, 0, (int) gameContainer->bounds.size.x / 3, (int) gameContainer->bounds.size.y));
	nano3Container->setBounds(Bounds2((int) gameContainer->bounds.size.x / 3 * 2, 0, (int) gameContainer->bounds.size.x / 3, (int) gameContainer->bounds.size.y));

	input1->setBounds(Bounds2(0, 0, (int) inputContainer->bounds.size.x / 3, (int) inputContainer->bounds.size.y));
	input2->setBounds(Bounds2((int) inputContainer->bounds.size.x / 3, 0, (int) inputContainer->bounds.size.x / 3, (int) inputContainer->bounds.size.y));
	input3->setBounds(Bounds2((int) inputContainer->bounds.size.x / 3 * 2, 0, (int) inputContainer->bounds.size.x / 3, (int) inputContainer->bounds.size.y));

	output1->setBounds(Bounds2(0, 0, (int) outputContainer->bounds.size.x / 3, (int) outputContainer->bounds.size.y));
	output2->setBounds(Bounds2((int) outputContainer->bounds.size.x / 3, 0, (int) outputContainer->bounds.size.x / 3, (int) outputContainer->bounds.size.y));
	output3->setBounds(Bounds2((int) outputContainer->bounds.size.x / 3 * 2, 0, (int) outputContainer->bounds.size.x / 3, (int) outputContainer->bounds.size.y));
}