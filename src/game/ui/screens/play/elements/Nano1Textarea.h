#ifndef ASM_NANO1TEXTAREA_H
#define ASM_NANO1TEXTAREA_H

#include "../../../../../engine/ui/Textarea.h"
#include "../../../../../engine/Graphics.h"

class Nano1Textarea : public Textarea {
public:
	Nano1Textarea(Container *parentContainer, Vector2 position, uint8_t cols, uint8_t rows, Color backgroundColor = Color::TRANSPARENT, Color textColor = Color::BLACK, Color currentLineColor = Color::WHITE);

	void onClick() override;
	void onHover() override;
	void onLineExit() override;
	void onLineEnter() override;
};


#endif //ASM_NANO1TEXTAREA_H
