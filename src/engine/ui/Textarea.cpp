#include "Textarea.h"

Textarea::Textarea(Container *parentContainer, Vector2f position, Font *font, Color textColor, uint8_t zLevel) : parentContainer(parentContainer), font(font), textColor(textColor), zLevel(zLevel) {
	bounds = new Bounds2(position.x, position.y, (float)(MAX_TEXTAREA_LINE_LENGTH * font->textWidth), (float)(MAX_TEXTAREA_LINES * font->textHeight));
	bounds->position = getRelativePositionWithParentContainer();
	lines = new std::vector<std::string>(MAX_TEXTAREA_LINES);
	timer = new Timer(TARGET_FPS / 10, true, handleKeyPressed);
}

void Textarea::update() {
	onClick();

	timer->tick();

	if (!inFocus || readonly) {
		return;
	}

	if (caretLine != lastLine) {
		onLineExit(lastLine);
		onLineEnter(caretLine);
		lastLine = caretLine;
	}

	onKeyBackspace();
	onKeyDelete();
	onKeyUp();
	onKeyDown();
	onKeyLeft();
	onKeyRight();
	onKeyHome();
	onKeyEnd();
	onKeyPageUp();
	onKeyPageDown();
	onKeyEnter();

	if (!Input::getInstance()->typedText.empty() && getTextOfCurrentLine()->length() < MAX_TEXTAREA_LINE_LENGTH) {
		char c = Input::getInstance()->typedText[0];

		if (c >= 'a' && c <= 'z') {
			c ^= 0x20; // Toggle uppercase
		}

		if (!(c >= 'A' && c <= 'Z') && !(c >= '0' && c <= '9') && c != ' ' && c != '.' && c != '#') {
			return;
		}

		getTextOfCurrentLine()->insert(caretColumn, 1, c);
		onLineChange(caretLine);
		moveCaretRight();
	}

	if (resetTimer) {
		timer->reset();
		resetTimer = false;
	}
}

void Textarea::render() {
	//Graphics::drawRectEmpty(*bounds, Color::GREEN);
	//Graphics::drawString(font, bounds->size.toString(), bounds->position, Color::GREEN);

	for (size_t line = 0; line < MAX_TEXTAREA_LINES; line++) {
		std::string string = lines->at(line);

		if (string.empty()) {
			continue;
		}

		onBeforeRender(line);

		std::string::size_type pos = 0;
		while ((pos = string.find("\n", pos)) != std::string::npos) {
			string.replace(pos, 1, ""); // Replace \n with an empty string
		}

		float x = ((line / MAX_TEXTAREA_LINE_LENGTH) * font->textWidth) + bounds->position.x;
		float y = (line / MAX_TEXTAREA_LINES) + (line * font->textHeight) + bounds->position.y;

		if (highlightedLine == line) {
			Graphics::drawRectSolid(Bounds2(x, y, bounds->size.x, (float)font->textHeight), Color::WHITE);
			textColor = Color::BLACK;
		} else {
			textColor = Color::WHITE;
		}

		Graphics::drawString(font, string, Vector2f(x, y), textColor);

		onAfterRender(line);
	}

	if (inFocus && !readonly) {
		if (caretAnimation % 4 == 0) {
			showCaret = !showCaret;
		}

		float x = ((caretColumn / MAX_TEXTAREA_LINE_LENGTH) * font->textWidth) + bounds->position.x;
		float y = (caretLine / MAX_TEXTAREA_LINES) + (caretLine * font->textHeight + bounds->position.y);

		for (uint8_t i = 0; i < caretColumn; i++) {
			x += font->textWidth;
		}

		if (showCaret) {
			Graphics::drawRectSolid(Bounds2(x, y, (float)font->textWidth, (float)font->textHeight), Color::WHITE);
		}
		caretAnimation++;
	}

	update();
}

void Textarea::onClick() {
	if(zLevel != Input::getInstance()->getMouseZLevel()) {
		return;
	}

	if (Input::getInstance()->getMouseButtonDown(Input::LEFT)) {
		inFocus = Input::getInstance()->mouseInBounds(*bounds);

		if (inFocus) {
			Vector2f mousePosition = Input::getInstance()->mousePosition;
			uint8_t line = (uint8_t)((mousePosition.y - bounds->position.y) / font->textHeight);
			uint8_t column = (uint8_t)((mousePosition.x - bounds->position.x) / font->textWidth);

			if (line >= MAX_TEXTAREA_LINES) {
				line = MAX_TEXTAREA_LINES - 1;
			}

			if (column > lines->at(line).length()) {
				column = (uint8_t)lines->at(line).length();
			}

			caretLine = line;
			caretColumn = column;
		}
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

uint8_t Textarea::getNonEmptyLines() {
	uint8_t count = 0;

	for (size_t i = 0; i < lines->size(); i++) {
		if (!lines->at(i).empty()) {
			count++;
		}
	}

	return count;
}

void Textarea::setText(uint8_t line, std::string text) {
	lines->at(line) = text;
}

void Textarea::moveCaretUp() {
	if (caretLine == 0) {
		caretColumn = 0;
		return;
	}

	if (caretColumn > lines->at(caretLine - 1).length()) {
		caretColumn = (uint8_t)lines->at(caretLine - 1).length();
	}

	caretLine--;
}

void Textarea::moveCaretDown() {
	if (caretLine == MAX_TEXTAREA_LINES - 1) {
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
	if (caretColumn == lines->at(caretLine).length() && caretColumn == MAX_TEXTAREA_LINES) {
		return;
	}

	if (caretColumn == lines->at(caretLine).length() && caretLine < MAX_TEXTAREA_LINES) {
		moveCaretDown();
		caretColumn = 0;
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

uint8_t Textarea::getLineOfLabel(std::string label) {
	uint8_t lineFound = NOT_FOUND;
	for (size_t i = 0; i < lines->size(); i++) {
		if (lines->at(i) == std::string("." + label)) {
			lineFound = i;
		}
	}

	// check if another label with the same name exists
	for (size_t i = 0; i < lines->size(); i++) {
		if (lines->at(i) == std::string("." + label) && i != lineFound) {
			return DUPLICATE;
		}
	}

	return lineFound;
}

void Textarea::onKeyUp() {
	if (Input::getInstance()->getKeyDown(Input::Up) || (Input::getInstance()->getKeyHeld(Input::Up) && timer->expired)) {
		moveCaretUp();
	}
}

void Textarea::onKeyDown() {
	if (Input::getInstance()->getKeyDown(Input::Down) || (Input::getInstance()->getKeyHeld(Input::Down) && timer->expired)) {
		moveCaretDown();
	}
}

void Textarea::onKeyLeft() {
	if (Input::getInstance()->getKeyDown(Input::Left) || (Input::getInstance()->getKeyHeld(Input::Left) && timer->expired)) {
		moveCaretLeft();
	}
}

void Textarea::onKeyRight() {
	if (Input::getInstance()->getKeyDown(Input::Right) || (Input::getInstance()->getKeyHeld(Input::Right) && timer->expired)) {
		moveCaretRight();
	}
}

void Textarea::onKeyEnter() {
	if (Input::getInstance()->getKeyDown(Input::Return)) {
		if (caretLine == MAX_TEXTAREA_LINES - 1) {
			return;
		}

		if(!lines->at(MAX_TEXTAREA_LINES - 1).empty()) {
			return;
		}

		std::string text = lines->at(caretLine).substr(caretColumn, lines->at(caretLine).length() - caretColumn);
		lines->at(caretLine) = lines->at(caretLine).substr(0, caretColumn);

		for (size_t i = MAX_TEXTAREA_LINES - 1; i > caretLine; i--) {
			lines->at(i) = lines->at(i - 1);
		}

		lines->at(caretLine + 1) = text;
		moveCaretDown();
		caretColumn = 0;
		onLineChange(caretLine);
	}
}

void Textarea::onKeyBackspace() {
	if (Input::getInstance()->getKeyDown(Input::Backspace) || (Input::getInstance()->getKeyHeld(Input::Backspace) && timer->expired)) {
		if (caretColumn == 0 && caretLine == 0) {
			return;
		}

		if (!getTextOfCurrentLine()->empty() && caretColumn != 0) {
			getTextOfCurrentLine()->erase(caretColumn - 1, 1);
			moveCaretLeft();
			onLineChange(caretLine);
		} else if (getTextOfCurrentLine()->empty()) {
			for (size_t i = caretLine; i < MAX_TEXTAREA_LINES - 1; i++) {
				lines->at(i) = lines->at(i + 1);
			}

			lines->at(MAX_TEXTAREA_LINES - 1) = "";
			moveCaretLeft();
			onLineChange(caretLine);
		} else if (caretColumn == 0 && !getTextOfCurrentLine()->empty() && lines->at(caretLine - 1).length() + getTextOfCurrentLine()->length() < MAX_TEXTAREA_LINE_LENGTH) {
			uint8_t lengthOfLineAbove = (uint8_t)lines->at(caretLine - 1).length();

			lines->at(caretLine - 1) += lines->at(caretLine);
			for (size_t i = caretLine; i < MAX_TEXTAREA_LINES - 1; i++) {
				lines->at(i) = lines->at(i + 1);
			}

			lines->at(MAX_TEXTAREA_LINES - 1) = "";
			moveCaretUp();
			caretColumn = lengthOfLineAbove;
			onLineChange(caretLine);
		}
	}
}

void Textarea::onKeyDelete() {
 	if (Input::getInstance()->getKeyDown(Input::Delete) || (Input::getInstance()->getKeyHeld(Input::Delete) && timer->expired)) {
		if (!getTextOfCurrentLine()->empty() && caretColumn != getTextOfCurrentLine()->length()) {
			getTextOfCurrentLine()->erase(caretColumn, 1);
			onLineChange(caretLine);
		}
	}
}

void Textarea::onKeyHome() {
	if (Input::getInstance()->getKeyDown(Input::Home)) {
		caretColumn = 0;
	}
}

void Textarea::onKeyEnd() {
	if (Input::getInstance()->getKeyDown(Input::End)) {
		caretColumn = (uint8_t)getTextOfCurrentLine()->length();
	}
}

void Textarea::onKeyPageUp() {
	if (Input::getInstance()->getKeyDown(Input::PageUp)) {
		caretLine = 0;
		moveCaretUp(); // move caret to the beginning of the first line
	}
}

void Textarea::onKeyPageDown() {
	if (Input::getInstance()->getKeyDown(Input::PageDown)) {
		caretLine = MAX_TEXTAREA_LINES;
		moveCaretDown(); // move caret to end of the last line
	}
}

void Textarea::handleKeyPressed() {
	resetTimer = true;
}