#ifndef ASM_BUTTONHEAD_H
#define ASM_BUTTONHEAD_H

#include "../../../../../engine/ui/GenericButton.h"

class Button : public GenericButton {
public:
    Button(Bounds2 bounds, Texture *texture, Color color = Color::WHITE);

    void render() override;
    void onClick() override;
    void onHover() override;
};


#endif //ASM_BUTTONHEAD_H
