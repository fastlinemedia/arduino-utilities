#ifndef Timer_h
#define Timer_h

#ifndef TIMER_ARRAY_SIZE
#define TIMER_ARRAY_SIZE 50
#endif

class Timer {
    public:
        static int delay(unsigned long length, void(*callback)());
        static int interval(unsigned long length, void(*callback)());
        static void off(int id);
        static void loop();
    private:
        static unsigned long _starts[TIMER_ARRAY_SIZE];
        static unsigned long _lengths[TIMER_ARRAY_SIZE];
        static void (*_callbacks[TIMER_ARRAY_SIZE])();
        static bool _intervals[TIMER_ARRAY_SIZE];
};

#endif
