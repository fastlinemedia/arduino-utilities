#include "Button.h"
#include <Arduino.h>

Button::Button(int pin) {
    _pin = pin;
    _state = 0;
    _prevState = 0;
    _delay = 100;
    _lastChecked = 0;
    pinMode(pin, INPUT);
}

int Button::read() {
    unsigned long currentMillis = millis();
    if (currentMillis - _lastChecked > _delay) {
        _lastChecked = currentMillis;
        _prevState = _state;
        _state = digitalRead(_pin);
    }
    return _state;
}

bool Button::wasPressed() {
    return read() > _prevState;
}

bool Button::isPressed() {
    return read() == HIGH;
}

bool Button::wasReleased() {
    return read() < _prevState;
}

bool Button::isReleased() {
    return read() == LOW;
}
