#ifndef ASM_SRC_ENGINE_UI_CONTAINER_H_
#define ASM_SRC_ENGINE_UI_CONTAINER_H_

#include "../utility/Bounds2.h"
#include "../utility/Color.h"
#include "../utility/Texture.h"
#include "../Font.h"

class Container {
 protected:
	Vector2f getRelativePositionWithParentContainer();

 public:
	Container *parentContainer;
	Bounds2 bounds;
	const Texture *texture;
	Color color;
	Font *font;

	Container(Container *parentContainer, Bounds2 bounds, const Texture *texture = nullptr, Color color = Color::WHITE);
	void render(bool drawBounds = false);
	void setBounds(Bounds2 bounds);
};

#endif //ASM_SRC_ENGINE_UI_CONTAINER_H_
