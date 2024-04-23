//
// Created by acoulombe on 4/14/24.
//

#ifndef ASM_TEXTAREA_H
#define ASM_TEXTAREA_H

#include <vector>
#include "../utility/Bounds2.h"
#include "../utility/Color.h"
#include "../Input.h"

class Textarea {
public:
    const static int MAX_LINES = 10;
    uint8_t id;
    Bounds2 bounds = Bounds2(Vector2(0, 0), Vector2(0, 0));
    Color backgroundColor = Color::TRANSPARENT;
    Color textColor = Color::BLACK;
    Color currentLineColor = Color::WHITE;
    std::string text;
    int fontSize = 12;
    int fontWidth = 8;
    bool inFocus = false;

    int caretLine = 0;
    int caretColumn = 0;

    Textarea(uint8_t id, Bounds2 bounds, Color backgroundColor, Color textColor, Color currentLineColor);

    void update();

    virtual void render() = 0;

    virtual void onClick();

    virtual void onHover() = 0;

    std::string *getLines();

    std::string getTextByLine(int line);

private:
    std::string lines[MAX_LINES];
    int lineCount;

    void parseLines();
};


#endif //ASM_TEXTAREA_H
