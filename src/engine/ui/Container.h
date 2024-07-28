#ifndef ASM_SRC_ENGINE_UI_CONTAINER_H_
#define ASM_SRC_ENGINE_UI_CONTAINER_H_

#include "../utility/Bounds2.h"

class Container {
 public:
  Container *parentContainer;
  Bounds2 bounds;

  Container(Container *parentContainer, Bounds2 bounds);
  void render();
  void setBounds(Bounds2 bounds);

  Vector2 getRelativePositionWithParentContainer();
};

#endif //ASM_SRC_ENGINE_UI_CONTAINER_H_
