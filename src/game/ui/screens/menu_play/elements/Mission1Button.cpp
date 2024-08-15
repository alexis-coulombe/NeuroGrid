#include "Mission1Button.h"
#include "../../../../mission/Mission1.h"

Mission1Button::Mission1Button(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, texture, color, zLevel) {
}

void Mission1Button::onRender() {
	Graphics::drawTexture(texture, bounds.position, color, bounds.size);
}

void Mission1Button::onClick() {
	*missionDescription = Mission1::description;
}

void Mission1Button::onHover() {
	Graphics::drawRectSolid(bounds, Color::RED);
}

void Mission1Button::linkMissionDescription(std::vector<std::string> *missionDescription) {
	this->missionDescription = missionDescription;
}
