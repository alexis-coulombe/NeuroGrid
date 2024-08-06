#ifndef ASM_SRC_ENGINE_UI_CONTAINER_H_
#define ASM_SRC_ENGINE_UI_CONTAINER_H_

#include "../utility/Bounds2.h"
#include "../utility/Color.h"
#include "../utility/Texture.h"

class Container {
 protected:
	Vector2f getRelativePositionWithParentContainer();

 public:
	Container *parentContainer;
	Bounds2 bounds;
	Texture *texture;
	Color color;

	Container(Container *parentContainer, Bounds2 bounds, Texture *texture = nullptr, Color color = Color::WHITE);
	void render();
	void setBounds(Bounds2 bounds);
};

#endif //ASM_SRC_ENGINE_UI_CONTAINER_H_
