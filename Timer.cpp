#include "Timer.h"
#include <Arduino.h>

Timer::Timer() {}

void Timer::delay(unsigned long length, void(*callback)()) {
    for (int i = 0; i < TIMER_ARRAY_SIZE; i++) {
        if (_lengths[i] == 0) {
            _starts[i] = millis();
            _lengths[i] = length;
            _callbacks[i] = callback;
            break;
        }
    }
}

void Timer::loop() {
    unsigned long now = millis();
    for (int i = 0; i < TIMER_ARRAY_SIZE; i++) {
        if (_lengths[i] > 0 && now - _starts[i] > _lengths[i]) {
            _callbacks[i]();
            _starts[i] = 0;
            _lengths[i] = 0;
            _callbacks[i] = [](){};
        }
    }
}
