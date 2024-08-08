#ifndef ASM_ANIMATION_H
#define ASM_ANIMATION_H

#include <cstdint>

typedef void (*Animation_callback)(uint32_t);

class Animation {
 public:
    uint32_t stateIndex;
    uint32_t stateCount;
    bool enabledByDefault;
    bool enabled;
    Animation_callback callback;

    Animation(uint32_t stateCount, bool enabledByDefault, Animation_callback callback);
    void tick();
    void enable();
    void disable();
};

#endif //ASM_ANIMATION_H