#ifndef ASM_HEAD_POPUP_H
#define ASM_HEAD_POPUP_H

#include "../../engine/ui/GenericPopup.h"
#include "popup/NewMissionButton.h"
#include "popup/LoadMissionButton.h"

class HeadPopup : public GenericPopup {
 public:
    HeadPopup();
    
    void onShow() override;
    void renderPopup(Bounds2 bounds) override;
    void onHide() override;
private:
    Container *popupMissionsContainer;
    Container *popupMissionIntroContainer;
    Container *popupMissionInfoContainer;
    Container *popupMissionInfoStatsContainer;
    Container *popupMissionInfoCurrentGameContainer;
    Container *popupMissionInfoCurrentGameStatsContainer;
    Container *popupMissionInfoCurrentGameButtonsContainer;

    NewMissionButton *newMissionButton;
	LoadMissionButton *loadMissionButton;
};

#endif