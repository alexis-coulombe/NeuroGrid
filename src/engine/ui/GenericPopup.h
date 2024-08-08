#ifndef ASM_GENERIC_POPUP_H
#define ASM_GENERIC_POPUP_H

#include "../ui/Container.h"
#include "../utility/Bounds2.h"
#include "../ui/popup/CloseButton.h"

class GenericPopup {
 public:
	Container popupContainer;
    Texture backgroundOverlay;
    CloseButton closeButton;

    uint8_t zLevel = 0;
    bool isVisible = false;

	GenericPopup(Bounds2 bounds);
    void show();
    void hide();

    virtual void onShow() = 0;
	virtual void renderPopup() = 0;
    virtual void onHide() = 0;
  private:
    Bounds2 bounds;

    void render();
};

#endif