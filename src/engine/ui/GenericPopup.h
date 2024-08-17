#ifndef ASM_GENERIC_POPUP_H
#define ASM_GENERIC_POPUP_H

#include "../ui/Container.h"
#include "../utility/Bounds2.h"
#include "GenericButton.h"

class CloseButton;

class GenericPopup {
 public:
	Container *popupContainer;
	Texture *backgroundOverlay;
	CloseButton *closeButton;

	uint8_t zLevel = 0;
	bool isVisible = false;

	GenericPopup(Bounds2 bounds);
	void show();
	void hide();

	virtual void onShow() = 0;
	virtual void renderPopup() = 0;
	virtual void onHide() = 0;
	void render();
 private:
	Bounds2 bounds;
};

class CloseButton : public GenericButton {
 public:
	CloseButton(Container *parentContainer, Bounds2 bounds, Color color, uint8_t zLevel);
	void linkPopup(GenericPopup *popup);

	void onRender() override;
	void onPress() override;
	void onClick() override;
	void onHover() override;
 private:
	GenericPopup *popup;
};

#endif