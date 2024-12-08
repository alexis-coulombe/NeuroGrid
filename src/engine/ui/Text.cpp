#include "Text.h"
#include "../Graphics.h"
#include "../utility/Asset.h"

uint8_t animationCounter = 0;
uint8_t animationTextCounter = 0;

Text::Text(Container *parentContainer, Vector2f position, std::string line, Font *font, Color color) : parentContainer(parentContainer), position(position), font(font), color(color) {
	this->lines = std::vector<std::string>{line};
	this->position = getRelativePositionWithParentContainer();
}

Text::Text(Container *parentContainer, Vector2f position, std::vector<std::string> lines, Font *font, Color color) : parentContainer(parentContainer), position(position), lines(lines), font(font), color(color) {
	this->position = getRelativePositionWithParentContainer();
}

Text::Text(Container *parentContainer, Vector2f position, std::vector<uint8_t> lines, Font *font, Color color) : parentContainer(parentContainer), position(position), font(font), color(color) {
	this->position = getRelativePositionWithParentContainer();

	for (size_t i = 0; i < lines.size(); i++) {
		this->lines.push_back((lines[i] < 10 ? "00" : lines[i] < 100 ? "0" : "") + std::to_string(lines[i]));
	}
}

void Text::render(Graphics::TextAlignement alignement) {
	for (size_t i = 0; i < lines.size(); i++) {
		if (highlightedLine != NOT_FOUND && i == highlightedLine) {
			Graphics::drawRectSolid(Bounds2(position.x, position.y + (font->textHeight + MARGIN) * i, (float)font->textWidth * lines.at(i).length(), (float)font->textHeight), Color(Color::ORANGE));
		}

		float y = position.y + (font->textHeight + MARGIN) * i;

		if (highlightedLine == i) {
			Graphics::drawString(font, lines.at(i), Vector2f(position.x, y), Color::BLACK, alignement, false);
		} else {
			Graphics::drawString(font, lines.at(i), Vector2f(position.x, y), color, alignement, false);
		}
	}
}

void Text::renderAnimateScrolling() {
	if (animationCounter++ >= ANIMATION_SPEED) {
		animationCounter = 0;
		if (animationTextCounter < lines.size()) {
			animationTextCounter++;
		}
	}

	for (size_t i = 0; i < animationTextCounter; i++) {
		float y = position.y + (font->textHeight + MARGIN) * i;
		Graphics::drawString(font, lines.at(i), Vector2f(position.x, y), color, Graphics::LEFT, false);
	}
}

void Text::updateText(std::string line) {
	this->lines = std::vector<std::string>{line};
}

void Text::updateText(std::vector<std::string> lines) {
	this->lines = lines;
}

Vector2f Text::getRelativePositionWithParentContainer() {
	if (parentContainer == nullptr) {
		return position;
	}

	return position + parentContainer->bounds.position;
}

void Text::setParentContainer(Container *container) {
	this->parentContainer = container;
	this->position = getRelativePositionWithParentContainer();
}

void Text::setPosition(Vector2f newPosition) {
	this->position = newPosition;
	this->position = getRelativePositionWithParentContainer();
}