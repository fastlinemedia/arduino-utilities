#include "Button.h"
#include <Arduino.h>

Button::Button(int pin) {
  _pin = pin;
  _state = 0;
  _prevState = 0;
  pinMode(pin, INPUT);
}

void Button::saveState() {
  _prevState = _state;
  _state = digitalRead(_pin);
}

bool Button::stateChangedHigh() {
  return _state > _prevState;
}

bool Button::stateIsHigh() {
  return _state == HIGH;
}

bool Button::stateChangedLow() {
  return _state < _prevState;
}

bool Button::stateIsLow() {
  return _state == LOW;
}
