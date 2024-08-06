#include "MenuPlayScreen.h"
#include "../../../../engine/utility/Asset.h"
#include "../../../../engine/Audio.h"
#include "../../../mission/Mission1.h"

#include <cstdint>

bool canShowPopup = false;
uint8_t currentSelectedMission = 0x00;

MenuPlayScreen::MenuPlayScreen() : GenericScreen() {
	backgroundBlack = Asset::loadTexture((char *)"assets/menu/background_black.png");

	flashingNeon = new Sound(Asset::loadSound((char *)"assets/sound/flashing_neon.mp3"));
	backgroundBuzz = new Music(Asset::loadMusic((char *)"assets/sound/electric_transformer_loop.mp3"));

	screenContainer = new Container(nullptr,
																	Bounds2((Window::width / 2) - (std::min((int) Window::width, 1920) / 2), 0, std::min((int) Window::width, 1920), std::min((int) Window::height, 1080)),
																	Asset::loadTexture((char *)"assets/menu/background.png"));

	popupContainer = new Container(nullptr, Bounds2((Window::width / 2) - 500, (Window::height / 2) - 350, 1000, 700));
	popupMissionsContainer = new Container(popupContainer, Bounds2(0, 0, (int)popupContainer->bounds.size.x / 3, (int)popupContainer->bounds.size.y));
	popupMissionIntroContainer = new Container(popupContainer, Bounds2((int)popupContainer->bounds.size.x / 3, 0, (int)popupContainer->bounds.size.x / 3 * 2, (int)popupContainer->bounds.size.y / 2));
	popupMissionInfoContainer = new Container(popupContainer, Bounds2((int)popupContainer->bounds.size.x / 3, (int)popupContainer->bounds.size.y / 2, (int)popupContainer->bounds.size.x / 3 * 2, (int)popupContainer->bounds.size.y / 2));
	popupMissionInfoStatsContainer = new Container(popupMissionInfoContainer, Bounds2(0, 0, (int)popupMissionInfoContainer->bounds.size.x, (int)popupMissionInfoContainer->bounds.size.y / 2));
	popupMissionInfoCurrentGameContainer = new Container(popupMissionInfoContainer, Bounds2(0, (int)popupMissionInfoContainer->bounds.size.y / 2, (int)popupMissionInfoContainer->bounds.size.x, (int)popupMissionInfoContainer->bounds.size.y / 2));
	popupMissionInfoCurrentGameStatsContainer = new Container(popupMissionInfoCurrentGameContainer, Bounds2(0, 0, (int)popupMissionInfoCurrentGameContainer->bounds.size.x, (int)popupMissionInfoCurrentGameContainer->bounds.size.y / 2));
	popupMissionInfoCurrentGameButtonsContainer = new Container(popupMissionInfoCurrentGameContainer, Bounds2(0, (int)popupMissionInfoCurrentGameContainer->bounds.size.y / 2, (int)popupMissionInfoCurrentGameContainer->bounds.size.x, (int)popupMissionInfoCurrentGameContainer->bounds.size.y / 2));

	newMissionButton = new NewMissionButton(popupMissionInfoCurrentGameButtonsContainer,
																					Bounds2(0, 0, (int)popupMissionInfoCurrentGameButtonsContainer->bounds.size.x / 2, (int)popupMissionInfoCurrentGameButtonsContainer->bounds.size.y),
																					Asset::loadTexture((char *)"assets/menu/new_game.png"),
																					Color::WHITE,
																					1);
	loadMissionButton = new LoadMissionButton(popupMissionInfoCurrentGameButtonsContainer,
																						Bounds2((int)popupMissionInfoCurrentGameButtonsContainer->bounds.size.x / 2, 0, (int)popupMissionInfoCurrentGameButtonsContainer->bounds.size.x / 2, (int)popupMissionInfoCurrentGameButtonsContainer->bounds.size.y),
																						Asset::loadTexture((char *)"assets/menu/new_game.png"),
																						Color::WHITE,
																						1);

	//mission1InfoText = new Text(popupMissionIntroContainer, Vector2f(10, 10), &Mission1::description, Asset::loadFont((char *)"assets/ModernDOS.ttf", 12));

	mission1Button = new Mission1Button(popupMissionsContainer,
																			Bounds2(0, 0, (int)popupMissionsContainer->bounds.size.x, 100),
																			Asset::loadTexture((char *)"assets/menu/new_game.png"),
																			Color::WHITE,
																			1);

	closePopupButton = new ClosePopupButton(popupContainer,
																					Bounds2((int)popupContainer->bounds.size.x - 40, 0, 40, 40),
																					Asset::loadTexture((char *)"assets/menu/new_game.png"),
																					Color::WHITE,
																					1);
	headButton = new HeadButton(screenContainer,
															Bounds2(40, 40, 40, 40),
															Asset::loadTexture((char *)"assets/menu/new_game.png"));
}

MenuPlayScreen::~MenuPlayScreen() {
	delete background;
	delete backgroundBlack;
	delete flashingNeon;
	delete backgroundBuzz;

	delete screenContainer;

	delete popupContainer;
	delete popupMissionsContainer;
	delete popupMissionIntroContainer;
	delete popupMissionInfoContainer;
	delete popupMissionInfoStatsContainer;
	delete popupMissionInfoCurrentGameContainer;
	delete popupMissionInfoCurrentGameStatsContainer;
	delete popupMissionInfoCurrentGameButtonsContainer;

	delete newMissionButton;
	delete loadMissionButton;

	delete mission1InfoText;

	delete mission1Button;
	delete closePopupButton;
	delete headButton;
}

uint8_t backgroundBuzzTimeout = TARGET_FPS; // 1 sec
bool buzzPlaying = false;

void MenuPlayScreen::init() {
	headButton->linkPopup(&canShowPopup);

	mission1Button->linkMissionInfo(&currentSelectedMission);
	closePopupButton->linkPopup(&canShowPopup);

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

	if (canShowPopup) {
		showPopup();
	}
}

void MenuPlayScreen::onWindowResized() {
	screenContainer->setBounds(Bounds2((Window::width / 2) - (std::min((int)Window::width, 1920) / 2), 0, std::min((int)Window::width, 1920), std::min((int)Window::height, 1080)));

	popupContainer->setBounds(Bounds2((Window::width / 2) - 500, (Window::height / 2) - 350, 1000, 700));
	popupMissionsContainer->setBounds(Bounds2(0, 0, (int)popupContainer->bounds.size.x / 3, (int)popupContainer->bounds.size.y));
	popupMissionIntroContainer->setBounds(Bounds2((int)popupContainer->bounds.size.x / 3, 0, (int)popupContainer->bounds.size.x / 3 * 2, (int)popupContainer->bounds.size.y / 2));
	popupMissionInfoContainer->setBounds(Bounds2((int)popupContainer->bounds.size.x / 3, (int)popupContainer->bounds.size.y / 2, (int)popupContainer->bounds.size.x / 3 * 2, (int)popupContainer->bounds.size.y / 2));
	popupMissionInfoStatsContainer->setBounds(Bounds2(0, 0, (int)popupMissionInfoContainer->bounds.size.x, (int)popupMissionInfoContainer->bounds.size.y / 2));
	popupMissionInfoCurrentGameContainer->setBounds(Bounds2(0, (int)popupMissionInfoContainer->bounds.size.y / 2, (int)popupMissionInfoContainer->bounds.size.x, (int)popupMissionInfoContainer->bounds.size.y / 2));
	popupMissionInfoCurrentGameStatsContainer->setBounds(Bounds2(0, 0, (int)popupMissionInfoCurrentGameContainer->bounds.size.x, (int)popupMissionInfoCurrentGameContainer->bounds.size.y / 2));
	popupMissionInfoCurrentGameButtonsContainer->setBounds(Bounds2(0, (int)popupMissionInfoCurrentGameContainer->bounds.size.y / 2, (int)popupMissionInfoCurrentGameContainer->bounds.size.x, (int)popupMissionInfoCurrentGameContainer->bounds.size.y / 2));

	newMissionButton->setBounds(Bounds2(0, 0, (int)popupMissionInfoCurrentGameButtonsContainer->bounds.size.x / 2, (int)popupMissionInfoCurrentGameButtonsContainer->bounds.size.y));
	loadMissionButton->setBounds(Bounds2((int)popupMissionInfoCurrentGameButtonsContainer->bounds.size.x / 2, 0, (int)popupMissionInfoCurrentGameButtonsContainer->bounds.size.x / 2, (int)popupMissionInfoCurrentGameButtonsContainer->bounds.size.y));

	mission1Button->setBounds(Bounds2(0, 0, (int)popupMissionsContainer->bounds.size.x, 100));

	closePopupButton->setBounds(Bounds2((int)popupContainer->bounds.size.x - 40, 0, 40, 40));
}

void MenuPlayScreen::showPopup() {
	Graphics::drawTexture(backgroundBlack, Vector2f(0, 0), Color::TRANSPARENT_HALF, Vector2f(Window::width, Window::height));
	popupContainer->render();
	popupMissionsContainer->render();
	popupMissionIntroContainer->render();
	popupMissionInfoContainer->render();
	popupMissionInfoStatsContainer->render();
	popupMissionInfoCurrentGameContainer->render();
	popupMissionInfoCurrentGameStatsContainer->render();
	popupMissionInfoCurrentGameButtonsContainer->render();

	mission1Button->render();
	loadMissionButton->render();

	newMissionButton->render();
	closePopupButton->render();

	showMissionInfo();
}

void MenuPlayScreen::showMissionInfo() {
	if (!canShowPopup) {
		return;
	}

	switch (currentSelectedMission) {
		default:
		case 0x00: break;
		case Mission1::ID:
			//mission1InfoText->render(true);
			break;
	}
}