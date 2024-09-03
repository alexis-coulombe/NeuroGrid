#include "Textarea.h"

Textarea::Textarea(Container *parentContainer, Vector2f position, uint8_t cols, uint8_t rows, Font *font, Color textColor) : parentContainer(parentContainer), cols(cols), rows(rows), font(font), textColor(textColor) {
	bounds = new Bounds2(position.x, position.y, (float)(cols * font->textWidth), (float)(rows * font->textHeight));
	bounds->position = getRelativePositionWithParentContainer();
	lines = new std::vector<std::string>(rows);
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

	if (Input::getInstance()->getKeyDown(Input::Backspace)) {
		if(caretColumn == 0 && caretLine == 0) {
			return;
		}

		if (!getTextOfCurrentLine()->empty() && caretColumn != 0) {
			getTextOfCurrentLine()->erase(caretColumn - 1, 1);
			moveCaretLeft();
		}
	}

//	if (Input::getInstance()->getKeyDown(Input::Return)) {
//		if (caretLine == rows) {
//			return;
//		}
//
//		if (!lines->at(rows - 1).empty()) {
//			return;
//		}
//
//		std::string newLine = getTextOfCurrentLine()->substr(caretColumn, getTextOfCurrentLine()->length());
//		getTextOfCurrentLine()->erase(caretColumn, getTextOfCurrentLine()->length());
//		lines->insert(lines->begin() + caretLine, newLine);
//
//		caretLine++;
//		caretColumn = 0;
//	}

	if (Input::getInstance()->getKeyDown(Input::Delete)) {
		if (!getTextOfCurrentLine()->empty() && caretColumn != getTextOfCurrentLine()->length()) {
			getTextOfCurrentLine()->erase(caretColumn, 1);
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

		if (!(c >= 'A' && c <= 'Z') && !(c >= '0' && c <= '9') && c != ' ' && c != ':' && c != '#') {
			return;
		}

		getTextOfCurrentLine()->insert(caretColumn, 1, c);
		onLineChange(caretLine);
		moveCaretRight();
	}

	if (Input::getInstance()->getKeyDown(Input::Up)) {
		moveCaretUp();
	}

	if (Input::getInstance()->getKeyDown(Input::Down)) {
		moveCaretDown();
	}

	if (Input::getInstance()->getKeyDown(Input::Left)) {
		moveCaretLeft();
	}

	if (Input::getInstance()->getKeyDown(Input::Right)) {
		moveCaretRight();
	}
}

void Textarea::render() {
	Graphics::drawRectEmpty(*bounds, Color::GREEN);

	if (inFocus && !readonly) {
		if (caretAnimation % 4 == 0) {
			showCaret = !showCaret;
		}

		std::string caretString;
		for (uint8_t i = 0; i < caretColumn; i++) {
			caretString.append(" ");
		}

		float x = ((caretColumn / cols) * font->textWidth) + bounds->position.x;
		float y = (caretLine / rows) + (caretLine * font->textHeight + bounds->position.y);

		Graphics::drawString(font, (showCaret ? caretString.append("\u0007") : caretString.append("\u0000")), Vector2f(x, y), Color::WHITE);
		caretAnimation++;
	}

	for (size_t line = 0; line < rows; line++) {
		std::string string = lines->at(line);

		if (string.empty()) {
			continue;
		}

		std::string::size_type pos = 0;
		while ((pos = string.find("\n", pos)) != std::string::npos) {
			string.replace(pos, 1, ""); // Replace \n with an empty string
		}

		float x = ((line / cols) * font->textWidth) + bounds->position.x;
		float y = (line / rows) + (line * font->textHeight) + bounds->position.y;

		if (highlightedLine == line) {
			Graphics::drawRectSolid(Bounds2(x, y, bounds->size.x, (float) font->textHeight), Color::WHITE);
			textColor = Color::BLACK;
		} else {
			textColor = Color::WHITE;
		}

		Graphics::drawString(font, string, Vector2f(x, y), textColor);

		onRender(line);
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