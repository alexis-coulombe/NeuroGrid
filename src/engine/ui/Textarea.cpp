//
// Created by acoulombe on 4/14/24.
//

#include "Textarea.h"

Textarea::Textarea(uint8_t id, Bounds2 bounds, Color backgroundColor, Color textColor, Color currentLineColor) : id(id), bounds(bounds), backgroundColor(backgroundColor), textColor(textColor), currentLineColor(currentLineColor) {
}

void Textarea::update() {
    if (inFocus) {
        if (Input::getInstance()->getKeyDown(Input::Backspace)) {
            if (!text.empty()) {
                text.pop_back();
            }

            parseLines();
        }

        if (Input::getInstance()->getKeyDown(Input::Return)) {
            text += '\n';

            parseLines();
        }

        if (!Input::getInstance()->typedText.empty() /*&& lines[caretLine].length() < bounds.size.x / fontWidth*/) {
            text += (Input::getInstance()->typedText[0] ^= 0x20); // Toggle uppercase

            parseLines();
        }
    }

    onClick();
}

void Textarea::onClick() {
    if (Input::getInstance()->getMouseButtonDown(Input::LEFT) && Input::getInstance()->mouseInBounds(bounds)) {
        Input::getInstance()->textareaFocusId = id;
        inFocus = true;

        caretLine = (int) (Input::getInstance()->mousePosition.y - (bounds.position.y + bounds.size.y)) / fontSize;
        caretColumn = (int) (Input::getInstance()->mousePosition.x - (bounds.position.x + bounds.size.x)) / fontWidth;

        caretLine = std::min(caretLine, lineCount);
        caretColumn = std::min(caretColumn, (int) lines[caretLine].length());
    } else if (Input::getInstance()->getMouseButtonDown(Input::LEFT) && !Input::getInstance()->mouseInBounds(bounds)) {
        inFocus = false;

        caretLine = -1;
        caretColumn = -1;
    }
}

void Textarea::parseLines() {
    std::cout << text << std::endl;
    std::string::size_type start = 0;
    std::string::size_type end;

    lineCount = 0;

    while ((end = text.find('\n', start)) != std::string::npos) {
        if (lineCount >= MAX_LINES) break; // Avoid overflow
        lines[lineCount++] = text.substr(start, end - start);
        start = end + 1;
    }

    if (lineCount < MAX_LINES) { // Check there's still room for the last line
        lines[lineCount++] = text.substr(start);
    }

    if (caretLine >= lineCount) {
        caretLine = lineCount - 1;
    }

    if (caretColumn > lines[caretLine].length()) {
        caretColumn = lines[caretLine].length();
    }
}

std::string Textarea::getTextByLine(int line) {
    if (line < lineCount) {
        return lines[line];
    }

    return "";
}

std::string *Textarea::getLines() {
    return lines;
}
