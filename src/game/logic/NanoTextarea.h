#ifndef ASM_NANOTEXTAREA_H
#define ASM_NANOTEXTAREA_H

#include "../../engine/ui/Textarea.h"

class NanoTextarea : public Textarea {
 public:
	NanoTextarea(Container *parentContainer, Vector2f position, uint8_t cols, uint8_t rows, Font *font, Color textColor);

	void onHover() override;
	void onLineExit(uint8_t line) override;
	void onLineEnter(uint8_t line) override;
	void onLineChange(uint8_t line) override;
};


#endif //ASM_NANOTEXTAREA_H
