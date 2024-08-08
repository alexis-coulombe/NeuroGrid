#ifndef ASM_CLOSE_BUTTON_H
#define ASM_CLOSE_BUTTON_H

#include "../GenericButton.h"
#include "../GenericPopup.h"

class CloseButton : public GenericButton {
 public:
  CloseButton(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color, uint8_t zLevel);
  void linkPopup(GenericPopup *popup);

  void onRender() override;
  void onClick() override;
  void onHover() override;
 private:
  GenericPopup *popup;
};

#endif