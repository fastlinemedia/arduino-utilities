#include "Led.h"

Led::Led(int pin) {
    _pin = pin;
    begin();
}

void Led::begin() {
    pinMode(_pin, OUTPUT);
}

void Led::on() {
    digitalWrite(_pin, HIGH);
}

void Led::off() {
    digitalWrite(_pin, LOW);
}

void Led::blink(unsigned long length) {
    unsigned long currentMillis = millis();
    if (currentMillis - _blinkMillis >= length) {
        _blinkMillis = currentMillis;
        if (_blinkState == 0) {
            _blinkState = 1;
            digitalWrite(_pin, HIGH);
        } else {
            _blinkState = 0;
            digitalWrite(_pin, LOW);
        }
    }
}
