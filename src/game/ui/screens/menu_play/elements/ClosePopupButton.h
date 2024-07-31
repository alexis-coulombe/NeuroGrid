#ifndef ASM_CLOSEPOPUPBUTTON_H
#define ASM_CLOSEPOPUPBUTTON_H

#include "../../../../../engine/ui/GenericButton.h"

class ClosePopupButton : GenericButton {
 public:
  bool *showPopupTrigger;

  ClosePopupButton(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color = Color::WHITE, uint8_t zLevel = 0);

  void render() override;
  void onClick() override;
  void onHover() override;
	using GenericButton::setBounds;

  void linkPopup(bool *popUpShowPtr);
};

#endif //ASM_CLOSEPOPUPBUTTON_H
