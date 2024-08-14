#ifndef ASM_BUTTON_H
#define ASM_BUTTON_H

#include "../utility/Bounds2.h"
#include "../utility/Texture.h"
#include "../Graphics.h"
#include "../utility/Color.h"
#include "../Input.h"
#include "Container.h"

class GenericButton {
 public:
	Bounds2 bounds;
	Texture *texture;
	Color color;
	uint8_t zLevel;
	Container *parentContainer;
	bool disabled = false;

	GenericButton(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color, uint8_t zLevel);
	Vector2f getRelativePositionWithParentContainer();
	void setBounds(Bounds2 bounds);

	virtual void onRender() = 0;
	virtual void onClick() = 0;
	virtual void onHover() = 0;
	void render();
};

#endif //ASM_BUTTON_H
