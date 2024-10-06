#ifndef ASM_QUIT_POPUP_H
#define ASM_QUIT_POPUP_H

#include "../../../../../engine/ui/GenericPopup.h"
#include "popup/QuitToMenuButton.h"
#include "popup/ContinueButton.h"

class QuitPopup : public GenericPopup {
 private:
	Container *popupContainer;
	Container *textContainer;

	Container *buttonContainer;
	Container *quitButtonContainer;
	Container *continueButtonContainer;

	QuitToMenuButton *quitButton;
	ContinueButton *continueButton;
 public:
	QuitPopup(Bounds2 bounds);

	void onShow() override;
	void renderPopup() override;
	void onHide() override;
};

#endif //ASM_QUIT_POPUP_H