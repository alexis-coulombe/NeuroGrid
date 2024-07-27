//
// Created by acoulombe on 7/21/24.
//

#ifndef ASM_SRC_GAME_UI_SCREENS_INTRO_INTROSCREEN_H
#define ASM_SRC_GAME_UI_SCREENS_INTRO_INTROSCREEN_H

#include "../../../../engine/ui/GenericScreen.h"
#include "../../../../engine/Texture.h"
#include "../../../../engine/Font.h"
#include "../../../../engine/utility/Music.h"
#include "../../../../engine/fsm/FSM.h"

class IntroScreen : public GenericScreen {
 private:
  Texture *backgroundBlack;
  Texture *backgroundIntro1;
  Texture *backgroundIntro2;
  Font *font;
  Music *backgroundMusic;

  void renderFirstScreen();
  void renderFirstScreenText();
  void renderSecondScreen();
  void renderSecondScreenText();
  void renderForeground();
 public:
  IntroScreen();
  void init() override;
  void render() override;
  void onWindowResized() override;

  bool checkCondition(FSM_condition_t condition);
  void checkAction(FSM_action_t action);
};

#endif //ASM_SRC_GAME_UI_SCREENS_INTRO_INTROSCREEN_H
