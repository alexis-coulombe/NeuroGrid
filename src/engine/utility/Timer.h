#ifndef ASM_TIMER_H
#define ASM_TIMER_H

#include <cstdint>

typedef void (*Timer_callback)(void);

class Timer {
 public:
    uint32_t timerValue;
    uint32_t timeout;
    bool enabledByDefault;
    bool enabled;
    bool expired;
    Timer_callback callback;

    Timer(uint32_t timeout, bool enabledByDefault, Timer_callback callback);
    void tick();
    void enable();
    void disable();
		void reset();
};

#endif //ASM_TIMER_H