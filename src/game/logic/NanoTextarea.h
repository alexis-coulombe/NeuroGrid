#ifndef ASM_NANOTEXTAREA_H
#define ASM_NANOTEXTAREA_H

#include "../../engine/ui/Textarea.h"
#include "ParserError.h"

class NanoTextarea : public Textarea {
 public:
	ParserError error = ParserError("", "", ParserError::ERROR_TYPE::NONE, 0);
	bool blocking = false;

	NanoTextarea(Container *parentContainer, Vector2f position, uint8_t cols, uint8_t rows, Font *font, Color textColor);

	void onHover() override;
	void onRender(uint8_t line) override;
	void onLineExit(uint8_t line) override;
	void onLineEnter(uint8_t line) override;
	void onLineChange(uint8_t line) override;
};

#endif //ASM_NANOTEXTAREA_H
