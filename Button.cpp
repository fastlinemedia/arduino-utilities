#include "Button.h"

Button::Button(int pin, bool invert, bool pullup) {
    _pin = pin;
    _invert = invert;
    _pullup = pullup;
    if (_invert) {
        _state = HIGH;
        _prevState = HIGH;
    }
    begin();
}

void Button::begin() {
    if (_pullup) {
        pinMode(_pin, INPUT_PULLUP);
    } else {
        pinMode(_pin, INPUT);
    }
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
    read();
    if (_changed) {
        if (_invert && _prevState > _state) {
            _changed = false;
            return true;
        } else if (!_invert && _prevState < _state) {
            _changed = false;
            return true;
        }
    }
    return false;
}

bool Button::isPressed() {
    if (_invert) {
        return read() == LOW;
    }
    return read() == HIGH;
}

bool Button::wasReleased() {
    read();
    if (_changed) {
        if (_invert && _prevState < _state) {
            _changed = false;
            return true;
        } else if (!_invert && _prevState > _state) {
            _changed = false;
            return true;
        }
    }
    return false;
}

bool Button::isReleased() {
    if (_invert) {
        return read() == HIGH;
    }
    return read() == LOW;
}
