#ifndef Delay_h
#define Delay_h

class Delay {
    public:
        Delay(unsigned long length);
        void check(void(*callback)());
    private:
        unsigned long _length = 0;
        unsigned long _lastChecked = 0;
};

#endif
