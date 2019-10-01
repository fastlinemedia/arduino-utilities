#include "Led.h"
#include <Arduino.h>

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
