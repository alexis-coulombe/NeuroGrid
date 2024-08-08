#include "Animation.h"

Animation::Animation(uint32_t stateCount, bool enabledByDefault, Animation_callback callback) : stateCount(stateCount), enabledByDefault(enabledByDefault), callback(callback) {
    this->stateIndex = 0;
    this->enabled = enabledByDefault;
    callback(stateIndex);
}

void Animation::tick() {
    if (!enabled) {
        return;
    }

    stateIndex++;
    stateIndex %= stateCount;
    callback(stateIndex);
}

void Animation::enable() {
    enabled = true;
}

void Animation::disable() {
    enabled = false;
}
