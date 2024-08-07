#include "Text.h"
#include "../Graphics.h"

uint8_t animationCounter = 0;
uint8_t animationTextCounter = 0;

Text::Text(Container *parentContainer, Vector2f position, std::vector<std::string> lines, Font *font, Color color) : parentContainer(parentContainer), position(position), lines(lines), font(font), color(color) {
	this->position = getRelativePositionWithParentContainer();
}

void Text::render() {
	for (size_t i = 0; i < lines.size(); i++) {
		float y = position.y + (font->pxSize + MARGIN) * i;
		Graphics::drawString(font, (char*)lines.at(i).c_str(), Vector2f(position.x, y), color, Graphics::LEFT, false);
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
		float y = position.y + (font->pxSize + MARGIN) * i;
		Graphics::drawString(font, (char*) lines.at(i).c_str(), Vector2f(position.x, y), color, Graphics::LEFT, false);
	}
}

Vector2f Text::getRelativePositionWithParentContainer() {
	if (parentContainer == nullptr) {
		return position;
	}

	return position + parentContainer->bounds.position;
}