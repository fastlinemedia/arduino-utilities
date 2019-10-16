#ifndef QueryString_h
#define QueryString_h

#include <Arduino.h>

class QueryString {
    public:
        static void parse(String query, void (*handleVar)(String, String));
};

#endif
