//
// Created by acoulombe on 4/13/24.
//

#ifndef ASM_BUTTONHEAD_H
#define ASM_BUTTONHEAD_H

#include "../../../engine/ui/Button.h"

class ButtonHead : public Button {
public:
    ButtonHead(Bounds2 bounds, Texture *texture, Color color = Color::WHITE);

    void render() override;
    void onClick() override;
    void onHover() override;
};


#endif //ASM_BUTTONHEAD_H
