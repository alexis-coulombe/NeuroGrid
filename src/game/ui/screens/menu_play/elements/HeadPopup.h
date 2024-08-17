#ifndef ASM_HEAD_POPUP_H
#define ASM_HEAD_POPUP_H

#include "../../../../../engine/ui/GenericPopup.h"
#include "popup/NewMissionButton.h"
#include "popup/LoadMissionButton.h"
#include "Mission1Button.h"
#include "../../../../../engine/ui/Text.h"

class HeadPopup : public GenericPopup {
 public:
	std::vector<std::string> *missionDescription = new std::vector<std::string>{""};

	HeadPopup(Bounds2 bounds);

	void onShow() override;
	void renderPopup() override;
	void onHide() override;
 private:
	Container *popupMissionsContainer;
	Container *popupMissionIntroContainer;
	Container *popupMissionInfoContainer;
	Text *popupMissionIntroText;

	Container *popupMissionInfoStatsContainer;
	Container *popupMissionInfoCurrentGameContainer;
	Container *popupMissionInfoCurrentGameStatsContainer;
	Container *popupMissionInfoCurrentGameButtonsContainer;

	Mission1Button *mission1Button;

	NewMissionButton *newGameButton;
	LoadMissionButton *loadGameButton;

	NewMissionButton *newMissionButton;
	LoadMissionButton *loadMissionButton;
};

#endif