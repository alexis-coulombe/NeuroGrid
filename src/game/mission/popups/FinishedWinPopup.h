#ifndef ASM_FINISHED_WIN_POPUP_H
#define ASM_FINISHED_WIN_POPUP_H

#include "../../../engine/ui/GenericPopup.h"
#include "../../../engine/ui/Text.h"

class FinishedWinPopup : public GenericPopup {
 public:
	Container *graphContainer;

	Container *buttonContainer;
	Container *continueButtonContainer;
	Container *quitButtonContainer;

	FinishedWinPopup(Bounds2 bounds);

	void onShow() override;
	void renderPopup() override;
	void onHide() override;
};

#endif //ASM_FINISHED_WIN_POPUP_H