#ifndef ASM_SRC_ENGINE_UI_CONTAINER_H_
#define ASM_SRC_ENGINE_UI_CONTAINER_H_

#include "../utility/Bounds2.h"

class Container {
 public:
  Bounds2 bounds;

  Container(Bounds2 bounds);
  void render();
  void setBounds(Bounds2 bounds);
};

#endif //ASM_SRC_ENGINE_UI_CONTAINER_H_
