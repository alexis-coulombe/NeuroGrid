#include "LoadMissionButton.h"
#include "../../../../../AssetLibrary.h"

LoadMissionButton::LoadMissionButton(Container *parentContainer, Bounds2 bounds, Color color, uint8_t zLevel) : GenericButton(parentContainer, bounds, color, zLevel) {

}

void LoadMissionButton::onRender() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_LOAD_GAME_IDLE), bounds.position, color, bounds.size);
}

void LoadMissionButton::onPress() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_LOAD_GAME_PRESS), bounds.position, color, bounds.size);
}

void LoadMissionButton::onClick() {
		printf("NewMissionButton clicked\n");
}

void LoadMissionButton::onHover() {
	Graphics::drawTexture(const_cast<Texture *>(AssetLibrary::BUTTON_LOAD_GAME_HOVER), bounds.position, color, bounds.size);
}

