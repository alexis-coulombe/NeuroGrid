#ifndef ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_ELEMENTS_MISSION1BUTTON_H_
#define ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_ELEMENTS_MISSION1BUTTON_H_

#include "../../../../../engine/ui/GenericButton.h"

class Mission1Button : GenericButton {
 private:
  const uint8_t ID = 1;

 public:
  uint8_t *showMissionInfoTrigger;

  Mission1Button(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color = Color::WHITE, uint8_t zLevel = 0);

  void render() override;
  void onClick() override;
  void onHover() override;
	using GenericButton::setBounds;

  void linkMissionInfo(uint8_t *missionInfoShowPtr);
};

#endif //ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_ELEMENTS_MISSION1BUTTON_H_
