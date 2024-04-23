//
// Created by acoulombe on 4/22/24.
//

#ifndef ASM_GAMETEXTAREA_H
#define ASM_GAMETEXTAREA_H

#include "../../../engine/ui/Textarea.h"
#include "../../../engine/Graphics.h"

class GameTextarea : public Textarea {
public:
    GameTextarea(uint8_t id, Bounds2 bounds, Color backgroundColor, Color textColor, Color currentLineColor);

    void render() override;
    void onHover() override;
};


#endif //ASM_GAMETEXTAREA_H
