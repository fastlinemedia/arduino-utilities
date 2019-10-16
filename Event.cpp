#include "Event.h"

int Event::_events[EVENT_ARRAY_SIZE] = {};
void (*Event::_callbacks[EVENT_ARRAY_SIZE])() = {};
bool Event::_once[EVENT_ARRAY_SIZE] = {};

int Event::on(int event, void(*callback)(), bool once) {
    for (int i = 0; i < EVENT_ARRAY_SIZE; i++) {
        if (_events[i] == 0) {
            _events[i] = event;
            _callbacks[i] = callback;
            _once[i] = once;
            return i;
        }
    }
}

int Event::on(int event, void(*callback)()) {
    return on(event, callback, false);
}

int Event::once(int event, void(*callback)()) {
    return on(event, callback, true);
}

void Event::off(int event, int id) {
    _events[id] = 0;
    _callbacks[id] = [](){};
    _once[id] = false;
}

void Event::off(int event) {
    for (int i = 0; i < EVENT_ARRAY_SIZE; i++) {
        if (_events[i] == event) {
            off(event, i);
        }
    }
}

void Event::trigger(int event) {
    for (int i = 0; i < EVENT_ARRAY_SIZE; i++) {
        if (_events[i] == event) {
            _callbacks[i]();
            if (_once[i]) {
                _events[i] = 0;
                _callbacks[i] = [](){};
                _once[i] = false;
            }
        }
    }
}
