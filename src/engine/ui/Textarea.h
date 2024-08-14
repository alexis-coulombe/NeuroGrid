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
 private:
	uint8_t caretLine = 0;
	uint8_t caretColumn = 0;

	std::vector<std::string> *lines;
	uint8_t caretAnimation = 0;
	bool showCaret = true;
	uint8_t lastLine;

 public:
	uint8_t cols, rows;
	Bounds2 *bounds;
	Container *parentContainer;

	Font *font;
	Color textColor;

	std::string text;

	bool inFocus = false;
	bool readonly = false;
	uint8_t highlightedLine = 0xFF;

	Textarea(Container *parentContainer, Vector2f position, uint8_t cols, uint8_t rows, Font *font, Color textColor = Color::BLACK);

	void update();
	void render();

	virtual void onClick();
	virtual void onHover() = 0;
	virtual void onRender(uint8_t line) = 0;
	virtual void onLineExit(uint8_t line) = 0;
	virtual void onLineEnter(uint8_t line) = 0;
	virtual void onLineChange(uint8_t line) = 0;

	void moveCaretUp();
	void moveCaretDown();
	void moveCaretLeft();
	void moveCaretRight();
	std::string *getTextOfCurrentLine();
	std::vector<std::string> *getLines();
	void setParentContainer(Container *container);
	Vector2f getRelativePositionWithParentContainer();
};

#endif //ASM_TEXTAREA_H
