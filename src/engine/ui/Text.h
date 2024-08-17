#ifndef ASM_SRC_ENGINE_UI_TEXT_H_
#define ASM_SRC_ENGINE_UI_TEXT_H_

#include <vector>
#include "Container.h"
#include "../utility/Color.h"
#include "../Font.h"
#include "../../Config.h"

class Text {
 private:
	static const uint8_t MARGIN = 0;
	static const uint8_t ANIMATION_SPEED = TARGET_FPS / 6;
 public:
	Container *parentContainer;
	Vector2f position;
	std::vector<std::string> lines;
	Font *font;
	Color color;

	Text(Container *parentContainer, Vector2f position, std::vector<std::string> lines, Font *font, Color color = Color::WHITE);
	Text(Container *parentContainer, Vector2f position, std::vector<uint8_t> lines, Font *font, Color color = Color::WHITE);

	void render();
	void renderAnimateScrolling();
	void updateText(std::vector<std::string> lines);
	Vector2f getRelativePositionWithParentContainer();
};

#endif //ASM_SRC_ENGINE_UI_TEXT_H_
