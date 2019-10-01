#ifndef RgbLed_h
#define RgbLed_h

class RgbLed {
    public:
        RgbLed(int redPin, int greenPin, int bluePin);
        void on();
        void off();
        void write(int red, int green, int blue);
        void writeSpectrum(int from, int to);
    private:
        int _redPin;
        int _greenPin;
        int _bluePin;
        int _spectrumColor;
        bool _spectrumReversed;
        unsigned long _spectrumMillis;
};

#endif
