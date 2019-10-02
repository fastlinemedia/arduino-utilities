#ifndef Timer_h
#define Timer_h

#ifndef TIMER_ARRAY_SIZE
#define TIMER_ARRAY_SIZE 100
#endif

class Timer {
    public:
        Timer();
        void delay(unsigned long length, void(*callback)());
        void loop();
    private:
        unsigned long _starts[TIMER_ARRAY_SIZE];
        unsigned long _lengths[TIMER_ARRAY_SIZE];
        void (*_callbacks[TIMER_ARRAY_SIZE])();
};

#endif
