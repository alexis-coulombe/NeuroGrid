#ifndef ASM_TEXTAREA_H
#define ASM_TEXTAREA_H

#include <vector>
#include "../utility/Bounds2.h"
#include "../utility/Color.h"
#include "../Input.h"
#include "../Graphics.h"
#include "../utility/Asset.h"
#include "Container.h"
#include <sstream>

class Textarea {
 public:
	uint16_t id;
	uint8_t cols, rows;
	Bounds2 *bounds;
	Container *parentContainer;

	Font *font;
	Color textColor;

	std::string text;

	float fontSize = 12;
	uint8_t fontWidth = 8;

	bool inFocus = false;
	bool readonly = false;
	uint8_t highlightedLine = 0xFF;

	uint8_t lineError = -1;
	uint8_t caretLine = 0;
	uint8_t caretColumn = 0;

	Textarea(Container *parentContainer, Vector2f position, uint8_t cols, uint8_t rows, Font *font, Color textColor = Color::BLACK);

	void update();

	virtual void render();
	virtual void onClick();
	virtual void onHover() = 0;
	virtual void onLineExit(uint8_t line) = 0;
	virtual void onLineEnter(uint8_t line) = 0;
	virtual void onLineChange(uint8_t line) = 0;

	void setParentContainer(Container *container);
	std::vector<std::string> *getLines();
	std::string getFullText();
	std::string *getTextOfCurrentLine();
	void moveCaretUp();
	void moveCaretDown();
	void moveCaretLeft();
	void moveCaretRight();
	Vector2f getRelativePositionWithParentContainer();
 private:
	std::vector<std::string> *lines;
	uint8_t caretAnimation = 0;
	bool showCaret = true;
	uint8_t lastLine;
};

#endif //ASM_TEXTAREA_H
