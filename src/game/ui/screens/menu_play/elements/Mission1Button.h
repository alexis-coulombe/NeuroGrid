#ifndef ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_ELEMENTS_MISSION1BUTTON_H_
#define ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_ELEMENTS_MISSION1BUTTON_H_

#include <vector>
#include "../../../../../engine/ui/GenericButton.h"

class Mission1Button : public GenericButton {
 private:
	std::vector<std::string> *missionDescription = new std::vector<std::string>{""};
 public:
	Mission1Button(Container *parentContainer, Bounds2 bounds, Color color = Color::WHITE, uint8_t zLevel = 0);

	void onRender() override;
	void onPress() override;
	void onClick() override;
	void onHover() override;
	using GenericButton::setBounds;

	void linkMissionDescription(std::vector<std::string> *missionDescription);
};

#endif //ASM_SRC_GAME_UI_SCREENS_MENU_PLAY_ELEMENTS_MISSION1BUTTON_H_
