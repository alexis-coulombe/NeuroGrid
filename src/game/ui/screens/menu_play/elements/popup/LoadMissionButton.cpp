#include "LoadMissionButton.h"

LoadMissionButton::LoadMissionButton(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, texture, color, zLevel) {

}

void LoadMissionButton::onRender() {
  Graphics::drawTexture(texture, bounds.position, color, bounds.size);
}

void LoadMissionButton::onClick() {
		printf("NewMissionButton clicked\n");
}

void LoadMissionButton::onHover() {
	Graphics::drawRectSolid(bounds, Color::RED);
}

