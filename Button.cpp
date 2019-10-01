#include "Button.h"
#include <Arduino.h>

Button::Button(int pin) {
    _pin = pin;
    begin();
}

void Button::begin() {
    pinMode(_pin, INPUT);
}

int Button::read() {
    unsigned long currentMillis = millis();
    if (currentMillis - _lastChecked > _delay) {
        _lastChecked = currentMillis;
        _prevState = _state;
        _state = digitalRead(_pin);
        _changed = _prevState != _state;
    }
    return _state;
}

bool Button::wasPressed() {
    if (_changed && isPressed()) {
        _changed = false;
        return true;
    }
    return false;
}

bool Button::isPressed() {
    return read() == HIGH;
}

bool Button::wasReleased() {
    if (_changed && isReleased()) {
        _changed = false;
        return true;
    }
    return false;
}

bool Button::isReleased() {
    return read() == LOW;
}
