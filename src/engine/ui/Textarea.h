//
// Created by acoulombe on 4/14/24.
//

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

    Color backgroundColor;
    Color textColor;
    Color currentLineColor;

    std::string text;

    uint8_t fontSize = 12;
		uint8_t fontWidth = 8;

    bool inFocus = false;

    uint8_t caretLine = 0;
		uint8_t caretColumn = 0;

    Textarea(Container *parentContainer, Vector2 position, uint8_t cols, uint8_t rows, Color backgroundColor = Color::TRANSPARENT, Color textColor = Color::BLACK, Color currentLineColor = Color::WHITE);

    void update();

    virtual void render(Font *font);

    virtual void onClick();

    virtual void onHover() = 0;

		virtual void onLineExit() = 0;

		virtual void onLineEnter() = 0;

		std::vector<std::string> *getLines();

		std::string getFullText();

    std::string* getTextOfCurrentLine();

    void moveCaretUp();

    void moveCaretDown();

    void moveCaretLeft();

    void moveCaretRight();

private:
	std::vector<std::string> *lines;
	uint8_t caretAnimation = 0;
	bool showCaret = true;
};


#endif //ASM_TEXTAREA_H
