#ifndef ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_MENUPLAYSCREEN_H_
#define ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_MENUPLAYSCREEN_H_

#include "../../../../engine/ui/GenericScreen.h"
#include "../../../../engine/utility/Music.h"
#include "../../../../engine/utility/Sound.h"
#include "../../../../engine/Texture.h"
#include "../../../../engine/ui/GenericButton.h"
#include "elements/HeadButton.h"
#include "elements/ClosePopupButton.h"

class MenuPlayScreen : public GenericScreen {
 private:
  Texture *background;
  Texture *backgroundBlack;
  Sound *flashingNeon;
  Music *backgroundBuzz;
  Container *screenContainer;
  Container *popupContainer;

  ClosePopupButton *closePopupButton;
  HeadButton *headButton;

 public:
  MenuPlayScreen();
  void init() override;
  void render() override;
  void onWindowResized() override;

  void showPopup();
};

#endif //ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_MENUPLAYSCREEN_H_
