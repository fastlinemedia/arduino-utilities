#ifndef Event_h
#define Event_h
#define EVENT_ARRAY_SIZE 100

class Event {
    public:
        Event();
        void on(int event, void(*callback)());
        void once(int event, void(*callback)());
        void off(int event);
        void trigger(int event);
};

#endif
