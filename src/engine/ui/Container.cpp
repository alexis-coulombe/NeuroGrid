#include "Container.h"
#include "../Graphics.h"

SDL_Rect rectToDraw;

Container::Container(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color): parentContainer(parentContainer), bounds(bounds), texture(texture), color(color){
	this->bounds.position = getRelativePositionWithParentContainer();

	rectToDraw = {(int)bounds.position.x, (int)bounds.position.y, (int)bounds.size.x, (int)bounds.size.y};
}

void Container::render() {
	rectToDraw = {(int)bounds.position.x, (int)bounds.position.y, (int)bounds.size.x, (int)bounds.size.y};

	SDL_SetRenderDrawColor(Window::renderer, 255, 0, 0, 255);
	SDL_RenderDrawRect(Window::renderer, &rectToDraw);

	if (texture != nullptr) {
		Graphics::drawTexture(texture, bounds.position, color, bounds.size);
	}
}

void Container::setBounds(Bounds2 newBounds) {
	this->bounds = newBounds;
	this->bounds.position = getRelativePositionWithParentContainer();
}

Vector2 Container::getRelativePositionWithParentContainer() {
	if (parentContainer == nullptr) {
		return bounds.position;
	}

	return bounds.position + parentContainer->bounds.position;
}