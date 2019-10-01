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
    return _didChange() && isPressed();
}

bool Button::isPressed() {
    return read() == HIGH;
}

bool Button::wasReleased() {
    return _didChange() && isReleased();
}

bool Button::isReleased() {
    return read() == LOW;
}

bool Button::_didChange() {
    read();
    if (_changed) {
        _changed = false;
        return true;
    }
    return false;
}
