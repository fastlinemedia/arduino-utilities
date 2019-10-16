#ifndef Led_h
#define Led_h

#include <Arduino.h>

class Led {
    public:
        Led(int pin);
        void begin();
        void on();
        void off();
        void blink(unsigned long length = 1000);
    private:
        int _pin;
        int _blinkState = 0;
        unsigned long _blinkMillis = 0;
};

#endif
