#ifndef Button_h
#define Button_h

#include <Arduino.h>

class Button {
    public:
        Button(int pin, bool invert = false, bool pullup = false);
        void begin();
        int read();
        bool wasPressed();
        bool isPressed();
        bool wasReleased();
        bool isReleased();
    private:
        int _pin;
        int _invert = false;
        int _pullup = false;
        int _state = 0;
        int _prevState = 0;
        unsigned long _delay = 100;
        unsigned long _lastChecked = 0;
        bool _changed = false;
};

#endif
