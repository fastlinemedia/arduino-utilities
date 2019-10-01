#ifndef RgbLed_h
#define RgbLed_h

class RgbLed {
    public:
        RgbLed(int redPin, int greenPin, int bluePin);
        void begin();
        void on();
        void off();
        void write(int red, int green, int blue);
        void writeSpectrum(int from, int to);
    private:
        int _redPin;
        int _greenPin;
        int _bluePin;
        int _spectrumColor = 0;
        bool _spectrumReversed = false;
        unsigned long _spectrumMillis = 0;
};

#endif
