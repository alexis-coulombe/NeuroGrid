#ifndef ASM_NANO1TEXTAREA_H
#define ASM_NANO1TEXTAREA_H

#include "../../../../../engine/ui/Textarea.h"
#include "../../../../../engine/Graphics.h"

class Nano1Textarea : public Textarea {
public:
	Nano1Textarea(Container *parentContainer, Vector2f position, uint8_t cols, uint8_t rows, Font *font, Color textColor);

	void onHover() override;
	void onLineExit(uint8_t line) override;
	void onLineEnter(uint8_t line) override;
	void onLineChange(uint8_t line) override;
};


#endif //ASM_NANO1TEXTAREA_H
