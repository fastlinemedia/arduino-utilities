#include "RgbLed.h"

RgbLed::RgbLed(int redPin, int greenPin, int bluePin) {
    _redPin = redPin;
    _greenPin = greenPin;
    _bluePin = bluePin;
    begin();
}

void RgbLed::begin() {
    pinMode(_redPin, OUTPUT);
    pinMode(_greenPin, OUTPUT);
    pinMode(_bluePin, OUTPUT);
}

void RgbLed::on() {
    write(255, 255, 255);
}

void RgbLed::off() {
    write(0, 0, 0);
}

void RgbLed::write(int red, int green, int blue) {
    analogWrite(_redPin, red);
    analogWrite(_greenPin, green);
    analogWrite(_bluePin, blue);
}

void RgbLed::writeSpectrum(int from, int to) {
    unsigned long currentMillis = millis();

    if (currentMillis - _spectrumMillis > 10) {
        _spectrumMillis = currentMillis;

        if (_spectrumColor <= from) {
            _spectrumColor = from;
            _spectrumReversed = false;
        } else if (_spectrumColor >= to) {
            _spectrumColor = to;
            _spectrumReversed = true;
        }

        if(_spectrumReversed) {
            _spectrumColor--;
        } else {
            _spectrumColor++;
        }

        if (_spectrumColor <= 255) {
            write(255 - _spectrumColor, _spectrumColor, 0);
        } else if (_spectrumColor <= 510) {
            write(0, 510 - _spectrumColor, _spectrumColor - 255);
        } else {
            write(_spectrumColor - 510, 0, 765 - _spectrumColor);
        }
    }
}
