#ifndef ASM_SCREEN_H
#define ASM_SCREEN_H

class GenericScreen {
public:
  GenericScreen();

  virtual void init() = 0;
  virtual void render() = 0;
  virtual void onWindowResized() = 0;
};

#endif //ASM_SCREEN_H