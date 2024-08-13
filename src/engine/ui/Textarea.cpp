#include "Textarea.h"

Textarea::Textarea(Container *parentContainer, Vector2f position, uint8_t cols, uint8_t rows, Font *font, Color textColor) : parentContainer(parentContainer), cols(cols), rows(rows), font(font), textColor(textColor) {
	bounds = new Bounds2(position.x, position.y, (float)(cols * font->pxSize), (float)(rows * font->pxSize));
	bounds->position = getRelativePositionWithParentContainer();
	lines = new std::vector<std::string>(rows);
	*input = Input::getInstance();
}

void Textarea::update() {
	onClick();

	if (!inFocus || readonly) {
		return;
	}

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

void Textarea::render() {
	if(highlightedLine != 0xFF) {
		Graphics::drawRectSolid(*bounds, Color(Color::WHITE, 0.5));
		// draw highlight
	}

	if (inFocus && !readonly) {
		if (caretAnimation % 4 == 0) {
			showCaret = !showCaret;
		}

		std::string caretString;
		for (uint8_t i = 0; i < caretColumn; i++) {
			caretString.append(" ");
		}

		float x = ((caretColumn / cols) * font->pxSize) + bounds->position.x;
		float y = (caretLine / rows) + (caretLine * font->pxSize + bounds->position.y);

		Graphics::drawString(font, (char *)(showCaret ? caretString.append("\u0007").c_str() : caretString.append("\u0000").c_str()), Vector2f(x, y), Color::WHITE);
		caretAnimation++;
	}

	for (size_t line = 0; i < rows; line++) {
		std::string string = lines->at(line);

		if (string.empty()) {
			continue;
		}

		std::string::size_type pos = 0;
		while ((pos = string.find("\n", pos)) != std::string::npos) {
			string.replace(pos, 1, ""); // Replace \n with an empty string
		}

		float x = ((line / cols) * font->pxSize) + bounds->position.x;
		float y = (line / rows) + (line * font->pxSize) + bounds->position.y;

		Graphics::drawString(font, (char *)string.c_str(), Vector2f(x, y), textColor);
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

void Textarea::setParentContainer(Container *container) {
	parentContainer = container;
	bounds->position = getRelativePositionWithParentContainer();
}

std::string *Textarea::getTextOfCurrentLine() {
	return &lines->at(caretLine);
}

std::vector<std::string> *Textarea::getLines() {
	return lines;
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

Vector2f Textarea::getRelativePositionWithParentContainer() {
	if (parentContainer == nullptr) {
		return bounds->position;
	}

	return bounds->position + parentContainer->bounds.position;
}