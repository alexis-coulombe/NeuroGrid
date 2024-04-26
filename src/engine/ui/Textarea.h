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
#include <sstream>

class Textarea {
public:
    const static int MAX_LINES = 10;
    uint8_t id;
    int cols, rows;
    Bounds2 *bounds;
    Color backgroundColor = Color::TRANSPARENT;
    Color textColor = Color::BLACK;
    Color currentLineColor = Color::WHITE;
    std::string text;
    int fontSize = 12;
    int fontWidth = 8;
    bool inFocus = false;

    int caretLine = 0;
    int caretColumn = 0;

    Textarea(uint8_t id, Vector2 position, int cols, int rows, Color backgroundColor, Color textColor, Color currentLineColor);

    void update();

    virtual void render(Font *font);

    virtual void onClick();

    virtual void onHover() = 0;

    std::string *getLines();

    std::string getTextOfCurrentLine();

    void moveCaretUp();

    void moveCaretDown();

    void moveCaretLeft();

    void moveCaretRight();

private:
    std::string lines[MAX_LINES];
};


#endif //ASM_TEXTAREA_H
