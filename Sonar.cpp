#include "Sonar.h"

Sonar::Sonar(int trigPin, int echoPin)
: _trigPin(trigPin)
, _echoPin(echoPin) {}

void Sonar::begin() {
    pinMode(_trigPin, OUTPUT);
    pinMode(_echoPin, INPUT);
}

unsigned long Sonar::read() {
    unsigned long currentMillis = millis();
    unsigned long reading = 0;

    if (currentMillis - _readMillis >= _readDelay) {
        _readMillis = currentMillis;
        digitalWrite(_trigPin, LOW);
        delayMicroseconds(5);
        digitalWrite(_trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(_trigPin, LOW);
        reading = pulseInLong(_echoPin, HIGH, _pulseDelay);
    }

    return reading;
}
