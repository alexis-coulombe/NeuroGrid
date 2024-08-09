#ifndef ASM_BUTTONHEAD_H
#define ASM_BUTTONHEAD_H

#include "../../../../../engine/ui/GenericButton.h"
#include "HeadPopup.h"

class HeadButton : public GenericButton {
 public:
  HeadButton(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color = Color::WHITE, uint8_t zLevel = 0);

  void onRender() override;
  void onClick() override;
  void onHover() override;

  void linkPopup(HeadPopup *popup);
 private:
  HeadPopup *popup;
};

#endif //ASM_BUTTONHEAD_H
