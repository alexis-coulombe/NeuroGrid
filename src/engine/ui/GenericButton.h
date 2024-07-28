#ifndef ASM_BUTTON_H
#define ASM_BUTTON_H

#include "../utility/Bounds2.h"
#include "../Texture.h"
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

	GenericButton(Container *parentContainer, Bounds2 bounds, Texture *texture, Color color, uint8_t zLevel);
	virtual void render() = 0;
	virtual void onClick() = 0;
	virtual void onHover() = 0;

	Vector2 getRelativePositionWithParentContainer();
	void setBounds(Bounds2 bounds);
};

#endif //ASM_BUTTON_H
