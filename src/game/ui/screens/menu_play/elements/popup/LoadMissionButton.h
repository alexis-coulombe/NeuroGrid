#ifndef ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_ELEMENTS_LOADMISSIONBUTTON_H_
#define ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_ELEMENTS_LOADMISSIONBUTTON_H_

#include "../../../../../engine/ui/GenericButton.h"

class LoadMissionButton : GenericButton {
 public:
  LoadMissionButton(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color = Color::WHITE, uint8_t zLevel = 0);

  void onRender() override;
  void onClick() override;
  void onHover() override;
	using GenericButton::setBounds;
};

#endif //ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_ELEMENTS_LOADMISSIONBUTTON_H_
