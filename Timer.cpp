#include "Timer.h"
#include <Arduino.h>

Timer::Timer() {}

int Timer::delay(unsigned long length, void(*callback)()) {
    for (int i = 0; i < TIMER_ARRAY_SIZE; i++) {
        if (_lengths[i] == 0) {
            _starts[i] = millis();
            _lengths[i] = length;
            _callbacks[i] = callback;
            return i;
        }
    }
}

int Timer::interval(unsigned long length, void(*callback)()) {
    int id = delay(length, callback);
    _intervals[id] = true;
}

void Timer::off(int id) {
    _starts[id] = 0;
    _lengths[id] = 0;
    _callbacks[id] = [](){};
    _intervals[id] = false;
}

void Timer::loop() {
    unsigned long now = millis();
    for (int i = 0; i < TIMER_ARRAY_SIZE; i++) {
        if (_lengths[i] > 0 && now - _starts[i] > _lengths[i]) {
            _callbacks[i]();
            if (_intervals[i]) {
                _starts[i] = now;
            } else {
                off(i);
            }
        }
    }
}
