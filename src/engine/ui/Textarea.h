#ifndef ASM_TEXTAREA_H
#define ASM_TEXTAREA_H

#include <vector>
#include "../utility/Bounds2.h"
#include "../utility/Color.h"
#include "../Input.h"
#include "../Graphics.h"
#include "../utility/Asset.h"
#include "Container.h"
#include "../utility/Timer.h"
#include "../../Config.h"
#include <sstream>

class Textarea {
 private:
	uint8_t caretLine = 0;
	uint8_t caretColumn = 0;

	std::vector<std::string> *lines;
	uint8_t caretAnimation = 0;
	bool showCaret = true;
	uint8_t lastLine;

	static inline bool keyWasPressed = false;
	static inline bool resetTimer = false;
	static void handleKeyPressed();
 	Timer *timer;

 public:
	static const uint8_t NOT_FOUND = 0xFF;
	static const uint8_t DUPLICATE = 0xFF;

	Bounds2 *bounds;
	Container *parentContainer;

	Font *font;
	Color textColor;

	uint8_t zLevel;
	std::string text;

	bool inFocus = false;
	bool readonly = false;
	uint8_t highlightedLine = NOT_FOUND;

	Textarea(Container *parentContainer, Vector2f position, Font *font, Color textColor = Color::BLACK, uint8_t zLevel = 0);

	void update();
	void render();

	virtual void onClick();
	virtual void onHover() = 0;
	virtual void onBeforeRender(uint8_t line) = 0;
	virtual void onAfterRender(uint8_t line) = 0;
	virtual void onLineExit(uint8_t line) = 0;
	virtual void onLineEnter(uint8_t line) = 0;
	virtual void onLineChange(uint8_t line) = 0;

	void moveCaretUp();
	void moveCaretDown();
	void moveCaretLeft();
	void moveCaretRight();
	std::string *getTextOfCurrentLine();
	std::vector<std::string> *getLines();
	uint8_t getNonEmptyLines();
	void setText(uint8_t line, std::string text);
	void setParentContainer(Container *container);
	Vector2f getRelativePositionWithParentContainer();
	uint8_t getLineOfLabel(std::string label);

	void onKeyUp();
	void onKeyDown();
	void onKeyLeft();
	void onKeyRight();
	void onKeyEnter();
	void onKeyBackspace();
	void onKeyDelete();
	void onKeyHome();
	void onKeyEnd();
	void onKeyPageUp();
	void onKeyPageDown();
};

#endif //ASM_TEXTAREA_H
