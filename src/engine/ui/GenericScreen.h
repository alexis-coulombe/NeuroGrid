#ifndef ASM_SCREEN_H
#define ASM_SCREEN_H

#include "Container.h"

class GenericScreen {
 public:
	Container *screenContainer;

	GenericScreen();
	~GenericScreen();

	void setBackgroundTexture(Texture *texture);

	virtual void init() = 0;
	virtual void render() = 0;
	virtual void onWindowResized() = 0;
};

#endif //ASM_SCREEN_H