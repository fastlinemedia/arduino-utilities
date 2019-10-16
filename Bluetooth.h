#ifndef Bluetooth_h
#define Bluetooth_h

#include <Arduino.h>
#include <SoftwareSerial.h>

class Bluetooth {
    public:
        Bluetooth(int rxPin, int txPin);
        void begin(int baud);
        void listen(void (*handleMessage)(String));
    private:
        int _rxPin;
        int _txPin;
        SoftwareSerial _serial;
        String _message = "";
};

#endif
