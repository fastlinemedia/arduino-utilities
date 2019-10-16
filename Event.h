#ifndef Event_h
#define Event_h

#include <Arduino.h>

#ifndef EVENT_ARRAY_SIZE
#define EVENT_ARRAY_SIZE 50
#endif

class Event {
    public:
        static int on(int event, void(*callback)(), bool once);
        static int on(int event, void(*callback)());
        static int once(int event, void(*callback)());
        static void off(int event, int id);
        static void off(int event);
        static void trigger(int event);
    private:
        static int _events[EVENT_ARRAY_SIZE];
        static void (*_callbacks[EVENT_ARRAY_SIZE])();
        static bool _once[EVENT_ARRAY_SIZE];
};

#endif
