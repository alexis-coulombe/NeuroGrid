#ifndef ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_MENUPLAYSCREEN_H_
#define ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_MENUPLAYSCREEN_H_

#include "../../../../engine/ui/GenericScreen.h"
#include "../../../../engine/utility/Music.h"
#include "../../../../engine/utility/Sound.h"
#include "../../../../engine/utility/Texture.h"
#include "elements/HeadButton.h"
#include "elements/Mission1Button.h"
#include "../../../../engine/ui/Text.h"
#include "elements/HeadPopup.h"

class MenuPlayScreen : public GenericScreen {
 private:
  Texture *background;
  Texture *backgroundBlack;
  Sound *flashingNeon;
  Music *backgroundBuzz;
  HeadPopup *headPopup;

  HeadButton *headButton;

 public:
  MenuPlayScreen();
	~MenuPlayScreen();
  void init() override;
  void render() override;
  void onWindowResized() override;
};

#endif //ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_MENUPLAYSCREEN_H_
