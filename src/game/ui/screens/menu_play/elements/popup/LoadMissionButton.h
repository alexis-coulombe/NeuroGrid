#ifndef ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_ELEMENTS_LOADMISSIONBUTTON_H_
#define ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_ELEMENTS_LOADMISSIONBUTTON_H_

#include "../../../../../../engine/ui/GenericButton.h"

class LoadMissionButton : public GenericButton {
 public:
  LoadMissionButton(Container *parentContainer, Bounds2 bounds, Color color = Color::WHITE, uint8_t zLevel = 0);

  void onRender() override;
	void onPress() override;
  void onClick() override;
  void onHover() override;
	using GenericButton::setBounds;
};

#endif //ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_ELEMENTS_LOADMISSIONBUTTON_H_
