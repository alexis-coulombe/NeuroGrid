#ifndef ASM_SRC_ENGINE_UI_TEXT_H_
#define ASM_SRC_ENGINE_UI_TEXT_H_

#include <vector>
#include "Container.h"
#include "../utility/Color.h"
#include "../Font.h"
class Text {
 private:
	static const uint8_t MARGIN = 10;
	static const uint8_t ANIMATION_SPEED = 1;
 public:
	Container *parentContainer;
	Vector2 position;
	std::vector<char *> *texts;
	Font *font;
	Color color;

	Text(Container *parentContainer, Vector2 position, std::vector<char *> *texts, Font *font, Color color = Color::WHITE);

	void render(bool animate);
	Vector2 getRelativePositionWithParentContainer();
};

#endif //ASM_SRC_ENGINE_UI_TEXT_H_
