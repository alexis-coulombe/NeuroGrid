#ifndef ASM_PLAYNEWGAMEBUTTON_H
#define ASM_PLAYNEWGAMEBUTTON_H

#include "../../../../../engine/ui/GenericButton.h"
#include "../../../../../engine/fileIO/SaveFileManager.h"

class PlayNewGameButton : public GenericButton {
 public:
  PlayNewGameButton(Container *parentContainer, Bounds2 bounds, Color color = Color::WHITE, uint8_t zLevel = 0);

  void onRender() override;
	void onPress() override;
  void onClick() override;
  void onHover() override;
 private:
	SaveFileManager saveFileManager;
};

#endif //ASM_PLAYNEWGAMEBUTTON_H
