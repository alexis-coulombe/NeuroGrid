#include "HeadPopup.h"
#include "../../../../../engine/utility/Asset.h"

HeadPopup::HeadPopup(Bounds2 bounds) : GenericPopup(bounds) {
	popupMissionsContainer = new Container(popupContainer, Bounds2(0, 0, (int)popupContainer->bounds.size.x / 3, (int)popupContainer->bounds.size.y));
	popupMissionIntroContainer = new Container(popupContainer, Bounds2((int)popupContainer->bounds.size.x / 3, 0, (int)popupContainer->bounds.size.x / 3 * 2, (int)popupContainer->bounds.size.y / 2));
	popupMissionInfoContainer = new Container(popupContainer, Bounds2((int)popupContainer->bounds.size.x / 3, (int)popupContainer->bounds.size.y / 2, (int)popupContainer->bounds.size.x / 3 * 2, (int)popupContainer->bounds.size.y / 2));
	popupMissionInfoStatsContainer = new Container(popupMissionInfoContainer, Bounds2(0, 0, (int)popupMissionInfoContainer->bounds.size.x, (int)popupMissionInfoContainer->bounds.size.y / 2));
	popupMissionInfoCurrentGameContainer = new Container(popupMissionInfoContainer, Bounds2(0, (int)popupMissionInfoContainer->bounds.size.y / 2, (int)popupMissionInfoContainer->bounds.size.x, (int)popupMissionInfoContainer->bounds.size.y / 2));
	popupMissionInfoCurrentGameStatsContainer = new Container(popupMissionInfoCurrentGameContainer, Bounds2(0, 0, (int)popupMissionInfoCurrentGameContainer->bounds.size.x, (int)popupMissionInfoCurrentGameContainer->bounds.size.y / 2));
	popupMissionInfoCurrentGameButtonsContainer = new Container(popupMissionInfoCurrentGameContainer, Bounds2(0, (int)popupMissionInfoCurrentGameContainer->bounds.size.y / 2, (int)popupMissionInfoCurrentGameContainer->bounds.size.x, (int)popupMissionInfoCurrentGameContainer->bounds.size.y / 2));
}

void HeadPopup::onShow() {
	popupMissionInfoText = new Text(popupMissionIntroContainer, Vector2f(), std::vector<std::string>{""}, Asset::loadFont((char *)"assets/ModernDOS.ttf", 12));

	newMissionButton = new NewMissionButton(popupMissionInfoCurrentGameButtonsContainer,
																					Bounds2(0, 0, (int)popupMissionInfoCurrentGameButtonsContainer->bounds.size.x / 2, (int)popupMissionInfoCurrentGameButtonsContainer->bounds.size.y),
																					Asset::loadTexture((char *)"assets/menu/new_game.png"),
																					Color::WHITE,
																					zLevel);
	loadMissionButton = new LoadMissionButton(popupMissionInfoCurrentGameButtonsContainer,
																						Bounds2((int)popupMissionInfoCurrentGameButtonsContainer->bounds.size.x / 2, 0, (int)popupMissionInfoCurrentGameButtonsContainer->bounds.size.x / 2, (int)popupMissionInfoCurrentGameButtonsContainer->bounds.size.y),
																						Asset::loadTexture((char *)"assets/menu/new_game.png"),
																						Color::WHITE,
																						zLevel);

	mission1Button = new Mission1Button(popupMissionsContainer,
																			Bounds2(0, 0, (int)popupMissionsContainer->bounds.size.x, 100),
																			Asset::loadTexture((char *)"assets/menu/new_game.png"),
																			Color::WHITE,
																			zLevel);

	mission1Button->linkMissionDescription(missionDescription);
}

void HeadPopup::renderPopup() {
	if(missionDescription != nullptr) {
		popupMissionInfoText->updateText(*missionDescription);
	}

	popupMissionsContainer->render();
	popupMissionIntroContainer->render();
	popupMissionInfoContainer->render();
	popupMissionInfoText->renderAnimateScrolling();

	popupMissionInfoStatsContainer->render();
	popupMissionInfoCurrentGameContainer->render();
	popupMissionInfoCurrentGameStatsContainer->render();
	popupMissionInfoCurrentGameButtonsContainer->render();

	mission1Button->render();

	newMissionButton->render();
	loadMissionButton->render();
}

void HeadPopup::onHide() {

}