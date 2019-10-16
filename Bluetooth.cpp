#include "Bluetooth.h"

Bluetooth::Bluetooth(int rxPin, int txPin)
: _rxPin(rxPin)
, _txPin(txPin)
, _serial(rxPin, txPin) {}

void Bluetooth::begin(int baud) {
    _serial = SoftwareSerial(_rxPin, _txPin);
    _serial.begin( baud );
}

void Bluetooth::listen(void (*handleMessage)(String)) {
    if (_serial.available()) {
        while (_serial.available()) {
            char c = _serial.read();
            if ( c == '\n' ) {
                handleMessage(_message);
                _message = "";
            } else {
                _message += c;
            }
        }
    }
}
