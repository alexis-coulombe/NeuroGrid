#include "Textarea.h"

Textarea::Textarea(Container *parentContainer, Vector2 position, uint8_t cols, uint8_t rows, Color backgroundColor, Color textColor, Color currentLineColor) : parentContainer(parentContainer), cols(cols), rows(rows), backgroundColor(backgroundColor), textColor(textColor), currentLineColor(currentLineColor) {
	bounds = new Bounds2(position.x, position.y, (float)(cols * fontWidth), (float)(rows * fontSize));
	bounds->position = getRelativePositionWithParentContainer();
	id = rand() * rand();
	lines = new std::vector<std::string>(rows);
}

void Textarea::update() {
	onClick();

	if (!inFocus) {
		return;
	}

	Input *input = Input::getInstance();

	if (caretLine != lastLine) {
		onLineExit(lastLine);
		onLineEnter(caretLine);
		lastLine = caretLine;
	}

	if (input->getKeyDown(Input::Backspace)) {
		if (!getTextOfCurrentLine()->empty() && caretColumn != 0) {
			getTextOfCurrentLine()->erase(caretColumn - 1, 1);
			moveCaretLeft();
		}
	}

	if (input->getKeyDown(Input::Delete)) {
		if (!getTextOfCurrentLine()->empty() && caretColumn != getTextOfCurrentLine()->length()) {
			getTextOfCurrentLine()->erase(caretColumn, 1);
		}
	}

	if (input->getKeyDown(Input::Home)) {
		caretColumn = 0;
	}

	if (input->getKeyDown(Input::End)) {
		caretColumn = (uint8_t)getTextOfCurrentLine()->length();
	}

	if (input->getKeyDown(Input::PageUp)) {
		caretLine = 0;
		moveCaretUp(); // move caret to the beginning of the first line
	}

	if (input->getKeyDown(Input::PageDown)) {
		caretLine = rows;
		moveCaretDown(); // move caret to end of the last line
	}

	if (!input->typedText.empty() && getTextOfCurrentLine()->length() < cols) {
		char c = input->typedText[0];

		if (c >= 'a' && c <= 'z') {
			c ^= 0x20; // Toggle uppercase
		}

		if (!(c >= 'A' && c <= 'Z') && !(c >= '0' && c <= '9') && c != ' ' && c != ':' && c != '#') {
			return;
		}

		getTextOfCurrentLine()->insert(caretColumn, 1, c);
		onLineChange(caretLine);
		moveCaretRight();
	}

	if (input->getKeyDown(Input::Up)) {
		moveCaretUp();
	}

	if (input->getKeyDown(Input::Down)) {
		moveCaretDown();
	}

	if (input->getKeyDown(Input::Left)) {
		moveCaretLeft();
	}

	if (input->getKeyDown(Input::Right)) {
		moveCaretRight();
	}
}

void Textarea::render(Font *font) {
	if (inFocus) {
		fontSize = font->pointsize * 1.33;
		if (caretAnimation % 4 == 0) {
			showCaret = !showCaret;
		}

		std::string caretString = "";
		for (uint8_t i = 0; i < caretColumn; i++) {
			caretString.append(" ");
		}

		float x = ((caretColumn / cols) * fontWidth) + bounds->position.x;
		float y = (caretLine / rows) + (caretLine * fontSize + bounds->position.y);

		Graphics::drawString(font, (char *)(showCaret ? caretString.append("\u0007").c_str() : caretString.append("\u0000").c_str()), Vector2(x, y), Color::WHITE);
		caretAnimation++;
	}

	for (uint8_t i = 0; i < rows; i++) {
		std::string string = lines->at(i);

		if(string.empty()){
			continue;
		}

		std::string::size_type pos = 0;
		while ((pos = string.find("\n", pos)) != std::string::npos) {
			string.replace(pos, 1, ""); // Replace \n with an empty string
		}

		float x = ((i / cols) * fontWidth) + bounds->position.x;
		float y = (i / rows) + (i * fontSize) + bounds->position.y;

		if (lineError == i) {
			Graphics::drawString(font, (char *)string.c_str(), Vector2(x, y), Color::RED);
		} else {
			Graphics::drawString(font, (char *)string.c_str(), Vector2(x, y), textColor);
		}
	}

	update();
}

void Textarea::onClick() {
	if (Input::getInstance()->getMouseButtonDown(Input::LEFT) && Input::getInstance()->mouseInBounds(*bounds)) {
		inFocus = true;
	} else if (Input::getInstance()->getMouseButtonDown(Input::LEFT) && !Input::getInstance()->mouseInBounds(*bounds)) {
		inFocus = false;
		caretLine = 0;
		caretColumn = 0;
	}
}

std::string *Textarea::getTextOfCurrentLine() {
	return &lines->at(caretLine);
}

std::vector<std::string> *Textarea::getLines() {
	return lines;
}

std::string Textarea::getFullText() {
	std::string fullText;

	for (const std::string &line : *lines) {
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
	if (caretLine == rows - 1) {
		caretColumn = (uint8_t)getTextOfCurrentLine()->length();
		return;
	}

	if (caretColumn > lines->at(caretLine + 1).length()) {
		caretColumn = (uint8_t)lines->at(caretLine + 1).length();
	}

	caretLine++;
}

void Textarea::moveCaretLeft() {
	if (caretColumn == 0 && caretLine == 0) {
		return;
	}

	if (caretColumn == 0 && caretLine > 0) {
		moveCaretUp();
		caretColumn = (int)getTextOfCurrentLine()->length();
		return;
	}

	caretColumn--;
}

void Textarea::moveCaretRight() {
	if (caretColumn == lines->at(caretLine).length() || caretColumn == cols) {
		return;
	}

	if (caretColumn == lines->at(caretLine).length()) {
		moveCaretDown();
		caretColumn = 0;
		return;
	}

	caretColumn++;
}

Vector2 Textarea::getRelativePositionWithParentContainer() {
	if(parentContainer == nullptr) {
		return bounds->position;
	}

	return bounds->position + parentContainer->bounds.position;
}