#ifndef WiFiConnection_h
#define WiFiConnection_h

#include <Arduino.h>
#include <SPI.h>
#include <WiFiNINA.h>

class WiFiConnection {
    public:
        WiFiConnection();
        void broadcast(char ssid[]);
        void connect(char ssid[], char pass[]);
        void listen(void (*handleRequest)(String));
        void checkStatus();
    private:
        WiFiServer _server;
};

#endif
