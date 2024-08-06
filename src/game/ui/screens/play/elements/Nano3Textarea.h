#ifndef ASM_SRC_GAME_UI_SCREENS_PLAY_ELEMENTS_NANO3TEXTAREA_H_
#define ASM_SRC_GAME_UI_SCREENS_PLAY_ELEMENTS_NANO3TEXTAREA_H_

#include "../../../../../engine/ui/Textarea.h"
#include "../../../../../engine/Graphics.h"

class Nano3Textarea : public Textarea {
 public:
	Nano3Textarea(Container *parentContainer, Vector2f position, uint8_t cols, uint8_t rows, Font *font, Color textColor);

	void onHover() override;
};

#endif //ASM_SRC_GAME_UI_SCREENS_PLAY_ELEMENTS_NANO3TEXTAREA_H_
