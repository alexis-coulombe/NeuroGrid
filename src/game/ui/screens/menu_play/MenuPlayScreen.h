#ifndef ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_MENUPLAYSCREEN_H_
#define ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_MENUPLAYSCREEN_H_

#include "../../../../engine/ui/GenericScreen.h"
#include "../../../../engine/utility/Music.h"
#include "../../../../engine/utility/Sound.h"
#include "../../../../engine/Texture.h"

class MenuPlayScreen : public GenericScreen {
 private:
  Texture *background;
  Texture *backgroundBlack;
  Music *backgroundBuzz;
  Sound *flashingNeon;

 public:
  MenuPlayScreen();
  void init() override;
  void render() override;
};

#endif //ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_MENUPLAYSCREEN_H_
