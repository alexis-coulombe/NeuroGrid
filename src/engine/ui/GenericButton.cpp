#include "GenericButton.h"
#include "Container.h"

GenericButton::GenericButton(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color, uint8_t zLevel = 0) : bounds(bounds), texture(texture), color(color), zLevel(zLevel) {
	this->parentContainer = parentContainer;
	this->bounds.position = getRelativePositionWithParentContainer();
}

Vector2 GenericButton::getRelativePositionWithParentContainer() {
	if (parentContainer == nullptr) {
		return bounds.position;
	}

	return bounds.position + parentContainer->bounds.position;
}

void GenericButton::setBounds(Bounds2 newBounds) {
	this->bounds = newBounds;
	this->bounds.position = getRelativePositionWithParentContainer();
}