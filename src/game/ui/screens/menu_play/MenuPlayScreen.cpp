#include "MenuPlayScreen.h"
#include "../../../../engine/utility/Asset.h"
#include "../../../../engine/Audio.h"
#include "../../../mission/Mission1.h"

#include <cstdint>

uint8_t currentSelectedMission = 0x00;

MenuPlayScreen::MenuPlayScreen() : GenericScreen() {
	backgroundBlack = Asset::loadTexture((char *)"assets/menu/background_black.png");

	flashingNeon = new Sound(Asset::loadSound((char *)"assets/sound/flashing_neon.mp3"));
	backgroundBuzz = new Music(Asset::loadMusic((char *)"assets/sound/electric_transformer_loop.mp3"));

  headPopup = new HeadPopup(Bounds2((Window::width / 2) - 500, (Window::height / 2) - 350, 1000, 700));

	//mission1InfoText = new Text(popupMissionIntroContainer, Vector2f(10, 10), &Mission1::description, Asset::loadFont((char *)"assets/ModernDOS.ttf", 12));

	//mission1Button = new Mission1Button(popupMissionsContainer,
	//																		Bounds2(0, 0, (int)popupMissionsContainer->bounds.size.x, 100),
	//																		Asset::loadTexture((char *)"assets/menu/new_game.png"),
	//																		Color::WHITE,
	//																		1);

	headButton = new HeadButton(screenContainer,
															Bounds2(40, 40, 40, 40),
															Asset::loadTexture((char *)"assets/menu/new_game.png"));
}

MenuPlayScreen::~MenuPlayScreen() {
}

uint8_t backgroundBuzzTimeout = TARGET_FPS; // 1 sec
bool buzzPlaying = false;

void MenuPlayScreen::init() {
	headButton->linkPopup(&headPopup);

	//mission1Button->linkMissionInfo(&currentSelectedMission);

	Audio::playSound(flashingNeon, false, 0.5f);
}

void MenuPlayScreen::render() {
	if (backgroundBuzzTimeout <= 0 && !buzzPlaying) {
		Audio::playMusic(backgroundBuzz, false, 0.5f);
		Audio::stopMusic(5.0f);
		buzzPlaying = true;
	} else if (backgroundBuzzTimeout > 0) {
		backgroundBuzzTimeout--;
		Graphics::drawTexture(backgroundBlack, Vector2f(0, 0), Color::BLACK, Vector2f(Window::width, Window::height));
	}

	if (!buzzPlaying) {
		return;
	}

	screenContainer->render();
	headButton->render();
  headPopup->renderPopup();
}

void MenuPlayScreen::onWindowResized() {
	screenContainer->setBounds(Bounds2((Window::width / 2) - (std::min((int)Window::width, 1920) / 2), 0, std::min((int)Window::width, 1920), std::min((int)Window::height, 1080)));
	//mission1Button->setBounds(Bounds2(0, 0, (int)popupMissionsContainer->bounds.size.x, 100));
}

void MenuPlayScreen::showPopup() {
	//mission1Button->render();
	loadMissionButton->render();
	newMissionButton->render();
	showMissionInfo();
}

void MenuPlayScreen::showMissionInfo() {
	switch (currentSelectedMission) {
		default:
		case 0x00: break;
		case Mission1::ID:
			//mission1InfoText->render(true);
			break;
	}
}