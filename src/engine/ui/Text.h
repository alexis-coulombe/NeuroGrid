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
	static const uint8_t NOT_FOUND = 0xFF;

	Container *parentContainer;
	Vector2f position;
	std::vector<std::string> lines;
	Font *font;
	Color color;
	uint8_t highlightedLine = NOT_FOUND;

	Text(Container *parentContainer, Vector2f position, std::string line, Font *font, Color color = Color::WHITE);
	Text(Container *parentContainer, Vector2f position, std::vector<std::string> lines, Font *font, Color color = Color::WHITE);
	Text(Container *parentContainer, Vector2f position, std::vector<uint8_t> lines, Font *font, Color color = Color::WHITE);

	void render();
	void renderAnimateScrolling();
	void updateText(std::string line);
	void updateText(std::vector<std::string> lines);
	Vector2f getRelativePositionWithParentContainer();
	void setParentContainer(Container *container);
};

#endif //ASM_SRC_ENGINE_UI_TEXT_H_
