#include "GenericButton.h"
#include "Container.h"

GenericButton::GenericButton(Container *parentContainer, Bounds2 bounds, Color color, uint8_t zLevel = 0) : bounds(bounds), color(color), zLevel(zLevel) {
	this->parentContainer = parentContainer;
	this->bounds.position = getRelativePositionWithParentContainer();
}

void GenericButton::render() {
	onRender();
	
	if (zLevel != Input::getInstance()->getMouseZLevel()) {
		return;
	}

	if (!disabled && Input::getInstance()->mouseInBounds(bounds)) {
		onHover();

		if (Input::getInstance()->getMouseButtonHeld(Input::MouseButton::LEFT)) {
			isPressed = true;
			onPress();
		}

		if(isPressed && Input::getInstance()->getMouseButtonUp(Input::MouseButton::LEFT)) {
			onClick();
		}
	} else {
		isPressed = false;
	}

	if(disabled) {
		Graphics::drawRectSolid(bounds, Color(Color::BLACK, 0xFF / 2));
	}
}

Vector2f GenericButton::getRelativePositionWithParentContainer() {
	if (parentContainer == nullptr) {
		return bounds.position;
	}

	return bounds.position + parentContainer->bounds.position;
}

void GenericButton::setBounds(Bounds2 newBounds) {
	this->bounds = newBounds;
	this->bounds.position = getRelativePositionWithParentContainer();
}

void GenericButton::click() {
	if (zLevel != Input::getInstance()->getMouseZLevel()) {
		return;
	}

	if(disabled) {
		return;
	}

	onClick();
}