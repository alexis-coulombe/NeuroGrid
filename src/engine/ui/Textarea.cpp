//
// Created by acoulombe on 4/14/24.
//

#include "Textarea.h"

Textarea::Textarea(Container *parentContainer, Vector2 position, uint8_t cols, uint8_t rows, Color backgroundColor, Color textColor, Color currentLineColor) : parentContainer(parentContainer), cols(cols), rows(rows), backgroundColor(backgroundColor), textColor(textColor), currentLineColor(currentLineColor) {
	bounds = new Bounds2(position.x, position.y, (float)(cols * fontWidth), (float)(rows * fontSize));
	id = rand() * rand();
	lines = new std::vector<std::string>(rows);
}

void Textarea::update() {
	if (inFocus) {
		if (Input::getInstance()->getKeyDown(Input::Backspace) || Input::getInstance()->getKeyHeld(Input::Backspace)) {
			if (!getTextOfCurrentLine()->empty() && caretColumn != 0) {
				getTextOfCurrentLine()->erase(caretColumn - 1, 1);
				moveCaretLeft();
			}
		}

		if (Input::getInstance()->getKeyDown(Input::Home)) {
			caretColumn = 0;
		}

		if (Input::getInstance()->getKeyDown(Input::End)) {
			caretColumn = (uint8_t)getTextOfCurrentLine()->length();
		}

		if (Input::getInstance()->getKeyDown(Input::PageUp)) {
			caretLine = 0;
			moveCaretUp(); // move caret to the beginning of the first line
		}

		if (Input::getInstance()->getKeyDown(Input::PageDown)) {
			caretLine = rows;
			moveCaretDown(); // move caret to end of the last line
		}

		if (!Input::getInstance()->typedText.empty() && getTextOfCurrentLine()->length() < cols) {
			char c = Input::getInstance()->typedText[0];

			if (c >= 'a' && c <= 'z') {
				c ^= 0x20; // Toggle uppercase
			}

			if (!(c >= 'A' && c <= 'Z') && !(c >= '0' && c <= '9') && c != ' ' && c != ':') {
				return;
			}

			getTextOfCurrentLine()->push_back(' ');
			getTextOfCurrentLine()->insert(caretColumn, 1, c);
			printf("Current line: \"%s\"\n", getTextOfCurrentLine()->c_str());
			printf("Current column: %d\n", caretColumn);
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

void Textarea::render(Font *font) {
	if (inFocus) {
		if (caretAnimation % 4 == 0) {
			showCaret = !showCaret;
		}

		Graphics::drawString(font, (char *)(showCaret ? "\u0007" : "\u0000"), Vector2(caretColumn * fontWidth + bounds->position.x, caretLine * fontSize + bounds->position.y), Color::WHITE);
		caretAnimation++;
	}

	for (uint8_t i = 0; i < rows; i++) {
		std::string string = lines->at(i);
		std::string::size_type pos = 0;

		while ((pos = string.find("\n", pos)) != std::string::npos) {
			string.replace(pos, 1, ""); // Replace \n with an empty string
		}

		uint8_t x = (i / cols) * fontWidth + bounds->position.x;
		uint8_t y = (i / rows) + (i * fontSize + bounds->position.y);

		Graphics::drawString(font, (char *)string.c_str(), Vector2(x, y), textColor);
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

std::string* Textarea::getTextOfCurrentLine() {
	return &lines->at(caretLine);
}

std::vector<std::string> *Textarea::getLines() {
	return lines;
}

std::string Textarea::getFullText() {
	std::string fullText;

	for (const std::string& line : *lines) {
		fullText.append(line).append("\n");
	}

	return fullText;
}

void Textarea::moveCaretUp() {
	if (caretLine == 0) {
		caretColumn = 0;
		return;
	}

	caretLine--;
}

void Textarea::moveCaretDown() {
	if (caretLine == rows) {
		// a revoir ca en bas
		caretColumn = (uint8_t)getTextOfCurrentLine()->length();
		return;
	}

	caretLine++;
}

void Textarea::moveCaretLeft() {
	if (caretColumn == 0 && caretLine == 0) {
		return;
	}

	if (caretColumn == 0 && caretLine > 0) {
		moveCaretUp();
		// a revoir ca en bas
		caretColumn = (int)getTextOfCurrentLine()->length();
	} else {
		caretColumn--;
	}
}

void Textarea::moveCaretRight() {
	if (caretColumn == cols) {
		return;
	}

	caretColumn++;
}
