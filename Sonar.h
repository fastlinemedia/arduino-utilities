#ifndef Sonar_h
#define Sonar_h

#include <Arduino.h>

class Sonar {
    public:
        Sonar(int trigPin, int echoPin);
        void begin();
        unsigned long read();
    private:
        int _trigPin;
        int _echoPin;
        unsigned long _readDelay = 50;
        unsigned long _readMillis = 0;
        unsigned long _pulseDelay = 10000;
};

#endif
