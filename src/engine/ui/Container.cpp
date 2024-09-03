#include "Container.h"
#include "../Graphics.h"
#include "../utility/Asset.h"

Container::Container(Container *parentContainer, Bounds2 bounds, const Texture *texture, Color color) : parentContainer(parentContainer), bounds(bounds), texture(texture), color(color) {
	this->bounds.position = getRelativePositionWithParentContainer();

	font = Asset::loadFont("assets/Roboto-Regular.ttf", 12);
}

void Container::render(bool drawBounds) {
	if (texture != nullptr) {
		Graphics::drawTexture(const_cast<Texture *>(texture), bounds.position, color, bounds.size);
	}

	if (drawBounds) {
		Graphics::drawRectEmpty(bounds, Color::RED);
		Graphics::drawString(font, const_cast<char *>(bounds.toString().c_str()), bounds.position, Color::RED);
	}
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