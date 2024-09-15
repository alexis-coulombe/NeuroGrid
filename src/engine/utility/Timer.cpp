#include <cstdio>
#include "Timer.h"

Timer::Timer(uint32_t timeout, bool enabledByDefault, Timer_callback callback) : timeout(timeout), enabledByDefault(enabledByDefault), callback(callback) {
    this->timerValue = 0;
    this->enabled = enabledByDefault;
    this->expired = false;
}

void Timer::tick() {
    if (!enabled) {
        return;
    }

    timerValue++;
    if (timerValue >= timeout) {
        timerValue = 0;
        expired = true;
        callback();
    }
}

void Timer::enable() {
    enabled = true;
}

void Timer::disable() {
    enabled = false;
}

void Timer::reset() {
		timerValue = 0;
		expired = false;
}