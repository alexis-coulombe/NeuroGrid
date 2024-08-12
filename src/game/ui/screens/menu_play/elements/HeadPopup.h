#ifndef ASM_HEAD_POPUP_H
#define ASM_HEAD_POPUP_H

#include "../../../../../engine/ui/GenericPopup.h"
#include "popup/NewMissionButton.h"
#include "popup/LoadMissionButton.h"

class HeadPopup : public GenericPopup {
 public:
	HeadPopup(Bounds2 bounds);

	void onShow() override;
	void renderPopup() override;
	void onHide() override;
 private:
	Container *popupMissionsContainer;
	Container *popupMissionIntroContainer;
	Container *popupMissionInfoContainer;
	Container *popupMissionInfoStatsContainer;
	Container *popupMissionInfoCurrentGameContainer;
	Container *popupMissionInfoCurrentGameStatsContainer;
	Container *popupMissionInfoCurrentGameButtonsContainer;

	NewMissionButton *newGameButton;
	LoadMissionButton *loadGameButton;

	NewMissionButton *newMissionButton;
	LoadMissionButton *loadMissionButton;
};

#endif