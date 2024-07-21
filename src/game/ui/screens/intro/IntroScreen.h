//
// Created by acoulombe on 7/21/24.
//

#ifndef ASM_SRC_GAME_UI_SCREENS_INTRO_INTROSCREEN_H
#define ASM_SRC_GAME_UI_SCREENS_INTRO_INTROSCREEN_H

#include "../../../../engine/ui/GenericScreen.h"
#include "../../../../engine/Texture.h"
#include "../../../../engine/Font.h"
#include "../../../../engine/utility/Music.h"

class IntroScreen : public GenericScreen {
 private:
  Texture *backgroundBlack;
  Texture *backgroundIntro1;
  Texture *backgroundIntro2;
  Font *font;
  Music *backgroundMusic;
 public:
  IntroScreen();
  void init() override;

  void render() override;
};

#endif //ASM_SRC_GAME_UI_SCREENS_INTRO_INTROSCREEN_H
