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
}

void HeadPopup::renderPopup() {
	popupMissionsContainer->render();
	popupMissionIntroContainer->render();
	popupMissionInfoContainer->render();
	popupMissionInfoStatsContainer->render();
	popupMissionInfoCurrentGameContainer->render();
	popupMissionInfoCurrentGameStatsContainer->render();
	popupMissionInfoCurrentGameButtonsContainer->render();

	newMissionButton->render();
	loadMissionButton->render();
}

void HeadPopup::onHide() {

}