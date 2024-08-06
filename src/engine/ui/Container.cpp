#include "Container.h"
#include "../Graphics.h"

Container::Container(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color) : parentContainer(parentContainer), bounds(bounds), texture(texture), color(color) {
	this->bounds.position = getRelativePositionWithParentContainer();
}

void Container::render() {
	if (texture != nullptr) {
		Graphics::drawTexture(texture, bounds.position, color, bounds.size);
	}

	Graphics::drawRectEmpty(bounds, Color::RED);
}

void Container::setBounds(Bounds2 newBounds) {
	this->bounds = newBounds;
	this->bounds.position = getRelativePositionWithParentContainer();
}

Vector2f Container::getRelativePositionWithParentContainer() {
	if (parentContainer == nullptr) {
		return bounds.position;
	}

	return bounds.position + parentContainer->bounds.position;
}