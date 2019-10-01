#ifndef Button_h
#define Button_h

class Button {
    public:
        Button(int pin);
        int read();
        bool wasPressed();
        bool isPressed();
        bool wasReleased();
        bool isReleased();
    private:
        int _pin;
        int _state;
        int _prevState;
        unsigned long _delay;
        unsigned long _lastChecked;
};

#endif
