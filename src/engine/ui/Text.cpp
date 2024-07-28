#include "Text.h"
#include "../Graphics.h"

Vector2 tmpTextPosition = {0, 0};
uint8_t animationCounter = 0;
uint8_t animationTextCounter = 0;

Text::Text(Container *parentContainer, Vector2 position, std::vector<char *> *texts, Font *font, Color color) : parentContainer(parentContainer), position(position), texts(texts), font(font), color(color) {
	this->position = getRelativePositionWithParentContainer();
	tmpTextPosition = position;
}

void Text::render(bool animate) {
	tmpTextPosition = position;

	if (animate && animationCounter++ >= ANIMATION_SPEED) {
		animationCounter = 0;
		if (animationTextCounter < texts->size()) {
			animationTextCounter++;
		}
	} else if (!animate) {
		animationTextCounter = texts->size();
	}

	for (int i = 0; i < animationTextCounter; i++) {
		Graphics::drawString(font, texts->at(i), tmpTextPosition, color, Graphics::LEFT, false);
		tmpTextPosition.y += font->pointsize + MARGIN;
	}
}

Vector2 Text::getRelativePositionWithParentContainer() {
	if(parentContainer == nullptr) {
		return position;
	}

	return position + parentContainer->bounds.position;
}