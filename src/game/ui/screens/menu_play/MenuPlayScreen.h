#ifndef ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_MENUPLAYSCREEN_H_
#define ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_MENUPLAYSCREEN_H_

#include "../../../../engine/ui/GenericScreen.h"
#include "../../../../engine/utility/Music.h"
#include "../../../../engine/utility/Sound.h"
#include "../../../../engine/Texture.h"
#include "elements/HeadButton.h"
#include "elements/ClosePopupButton.h"
#include "elements/HeadMission1Button.h"
#include "../../../../engine/ui/Text.h"
#include "elements/NewMissionButton.h"
#include "elements/LoadMissionButton.h"

class MenuPlayScreen : public GenericScreen {
 private:
  Texture *background;
  Texture *backgroundBlack;
  Sound *flashingNeon;
  Music *backgroundBuzz;
  Container *screenContainer;

  Container *popupContainer;
  Container *popupMissionsContainer;
	Container *popupMissionIntroContainer;
	Container *popupMissionInfoContainer;
	Container *popupMissionInfoStatsContainer;
	Container *popupMissionInfoCurrentGameContainer;
	Container *popupMissionInfoCurrentGameStatsContainer;
	Container *popupMissionInfoCurrentGameButtonsContainer;

	NewMissionButton *newMissionButton;
	LoadMissionButton *loadMissionButton;

  HeadMission1Button *headMission1Button;
	Text *mission1InfoText;

  ClosePopupButton *closePopupButton;
  HeadButton *headButton;

 public:
  MenuPlayScreen();
	~MenuPlayScreen();
  void init() override;
  void render() override;
  void onWindowResized() override;

  void showPopup();
  void showMissionInfo();
};

#endif //ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_MENUPLAYSCREEN_H_
