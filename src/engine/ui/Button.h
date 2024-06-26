//
// Created by acoulombe on 4/13/24.
//

#ifndef ASM_BUTTON_H
#define ASM_BUTTON_H

#include "../utility/Bounds2.h"
#include "../Texture.h"
#include "../Graphics.h"
#include "../utility/Color.h"
#include "../Input.h"

class Button {
public:
    Bounds2 bounds;
    Texture *texture;
    Color color;

    Button(Bounds2 bounds, Texture *texture, Color color = Color::WHITE);
    virtual void render() = 0;
    virtual void onClick() = 0;
    virtual void onHover() = 0;
};


#endif //ASM_BUTTON_H
