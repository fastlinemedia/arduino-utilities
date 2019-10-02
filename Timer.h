#ifndef Timer_h
#define Timer_h

#ifndef TIMER_ARRAY_SIZE
#define TIMER_ARRAY_SIZE 50
#endif

class Timer {
    public:
        Timer();
        int delay(unsigned long length, void(*callback)());
        int interval(unsigned long length, void(*callback)());
        void off(int id);
        void loop();
    private:
        unsigned long _starts[TIMER_ARRAY_SIZE];
        unsigned long _lengths[TIMER_ARRAY_SIZE];
        void (*_callbacks[TIMER_ARRAY_SIZE])();
        bool _intervals[TIMER_ARRAY_SIZE];
};

#endif
