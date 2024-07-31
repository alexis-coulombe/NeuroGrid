#ifndef ASM_BUTTONHEAD_H
#define ASM_BUTTONHEAD_H

#include "../../../../../engine/ui/GenericButton.h"

class HeadButton : GenericButton {
 public:
  bool *showPopupTrigger;

  HeadButton(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color = Color::WHITE, uint8_t zLevel = 0);

  void render() override;
  void onClick() override;
  void onHover() override;

  void linkPopup(bool *popUpShowPtr);
};

#endif //ASM_BUTTONHEAD_H
