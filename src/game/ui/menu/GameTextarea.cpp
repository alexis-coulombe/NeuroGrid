//
// Created by acoulombe on 4/22/24.
//

#include "GameTextarea.h"

GameTextarea::GameTextarea(uint8_t id, Bounds2 bounds, Color backgroundColor, Color textColor, Color currentLineColor) : Textarea(id, bounds, backgroundColor, textColor, currentLineColor) {


}

void GameTextarea::render() {
    Graphics::drawRectSolid(bounds, Color::GREEN);

    Textarea::update();
}

void GameTextarea::onHover() {

}
