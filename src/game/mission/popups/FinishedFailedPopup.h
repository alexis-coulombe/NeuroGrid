#ifndef ASM_FINISHED_FAILED_POPUP_H
#define ASM_FINISHED_FAILED_POPUP_H

#include "../../../engine/ui/GenericPopup.h"
#include "../../../engine/ui/Text.h"

class FinishedFailedPopup : public GenericPopup {
 public:
	FinishedFailedPopup(Bounds2 bounds);

	void onShow() override;
	void renderPopup() override;
	void onHide() override;
};

#endif //ASM_FINISHED_FAILED_POPUP_H