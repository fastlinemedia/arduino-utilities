#include "Delay.h"
#include <Arduino.h>

Delay::Delay(unsigned long length): _length(length) {}

void Delay::check(void(*callback)()) {
    unsigned long now = millis();
    if (now - _lastChecked > _length) {
        _lastChecked = now;
        callback();
    }
}
