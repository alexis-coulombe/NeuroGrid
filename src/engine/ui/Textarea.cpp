//
// Created by acoulombe on 4/14/24.
//

#include "Textarea.h"

Textarea::Textarea(uint8_t id, Vector2 position, int cols, int rows, Color backgroundColor, Color textColor, Color currentLineColor) : id(id), cols(cols), rows(rows), backgroundColor(backgroundColor), textColor(textColor), currentLineColor(currentLineColor) {
    bounds = new Bounds2(position.x, position.y, (float) (cols * fontWidth), (float) (rows * fontSize));
}

void Textarea::update() {
    if (inFocus) {
        if (Input::getInstance()->getKeyDown(Input::Backspace) || Input::getInstance()->getKeyHeld(Input::Backspace)) {
            if (!lines[caretLine].empty()) {
                lines[caretLine].pop_back();
            }

            moveCaretLeft();
        }

        if (Input::getInstance()->getKeyDown(Input::Home)) {
            caretColumn = 0;
        }

        if (Input::getInstance()->getKeyDown(Input::End)) {
            caretColumn = (int) getTextOfCurrentLine().length();
        }

        if(Input::getInstance()->getKeyDown(Input::PageUp)) {
            caretLine = 0;
            moveCaretUp();
        }

        if(Input::getInstance()->getKeyDown(Input::PageDown)) {
            caretLine = MAX_LINES - 1;
            moveCaretDown();
        }

        if (!Input::getInstance()->typedText.empty() && lines[caretLine].length() < MAX_LINES) {
            char c = Input::getInstance()->typedText[0];

            if (c >= 'a' && c <= 'z') {
                c ^= 0x20; // Toggle uppercase
            }

            if (!(c >= 'A' && c <= 'Z') && !(c >= '0' && c <= '9') && c != ' ' && c != ':') {
                return;
            }

            lines[caretLine].insert(caretColumn, 1, c);

            moveCaretRight();
        }

        if (Input::getInstance()->getKeyDown(Input::Up) || Input::getInstance()->getKeyHeld(Input::Up)) {
            moveCaretUp();
        }

        if (Input::getInstance()->getKeyDown(Input::Down) || Input::getInstance()->getKeyHeld(Input::Down)) {
            moveCaretDown();
        }

        if (Input::getInstance()->getKeyDown(Input::Left) || Input::getInstance()->getKeyHeld(Input::Left)) {
            moveCaretLeft();
        }

        if (Input::getInstance()->getKeyDown(Input::Right) || Input::getInstance()->getKeyHeld(Input::Right)) {
            moveCaretRight();
        }
    }

    onClick();
}

int counter = 0;
bool flag = false;

void Textarea::render(Font *font) {
    if(inFocus) {
        if (counter % 6 == 0) {
            flag = !flag;
        }

        Graphics::drawString(font, (char *) (flag ? "\u0007" : "\u0000"), Vector2(caretColumn * fontWidth + bounds->position.x, caretLine * fontSize + bounds->position.y), Color::WHITE);
        counter++;
    }

    for (int i = 0; i < MAX_LINES; i++) {
        std::string string = lines[i];
        std::string::size_type pos = 0;

        while ((pos = string.find("\n", pos)) != std::string::npos) {
            string.replace(pos, 1, ""); // Replace \n with an empty string
        }

        int x = (i / cols) * fontWidth + bounds->position.x;
        int y = (i / rows) + (i * fontSize + bounds->position.y);

        Graphics::drawString(font, (char *) string.c_str(), Vector2(x, y), textColor);
    }

    update();
}

void Textarea::onClick() {
    if (Input::getInstance()->getMouseButtonDown(Input::LEFT) && Input::getInstance()->mouseInBounds(*bounds)) {
        inFocus = true;

        //caretLine = (int) ((bounds->position.y + bounds->size.y) - Input::getInstance()->mousePosition.y) / fontSize;
        //caretColumn = (int) ((bounds->position.x + bounds->size.x) - Input::getInstance()->mousePosition.x) / fontWidth;

        //caretLine = std::min(caretLine, lineCount);
        //caretColumn = std::min(caretColumn, (int) lines[caretLine].length());
    } else if (Input::getInstance()->getMouseButtonDown(Input::LEFT) && !Input::getInstance()->mouseInBounds(*bounds)) {
        inFocus = false;

        caretLine = 0;
        caretColumn = 0;
    }
}

std::string Textarea::getTextOfCurrentLine() {
    return lines[caretLine];
}

std::string *Textarea::getLines() {
    return lines;
}

void Textarea::moveCaretUp() {
    int nextCaretMove = caretLine - 1;

    caretLine = std::max(0, nextCaretMove);
}

void Textarea::moveCaretDown() {
    int nextCaretMove = caretLine + 1;

    caretLine = std::min(9, nextCaretMove);
    caretColumn = std::min((int) getTextOfCurrentLine().length(), caretColumn);
}

void Textarea::moveCaretLeft() {
    int nextCaretMove = caretColumn - 1;

    if (nextCaretMove < 0 && caretLine > 0) {
        moveCaretUp();
        caretColumn = (int) getTextOfCurrentLine().length();
        return;
    }

    caretColumn = std::max(0, nextCaretMove);
}

void Textarea::moveCaretRight() {
    int nextCaretMove = caretColumn + 1;

    std::cout << getTextOfCurrentLine().length() << std::endl;
    std::cout << getTextOfCurrentLine() << std::endl;

    caretColumn = std::min((int) getTextOfCurrentLine().length(), nextCaretMove);
}
