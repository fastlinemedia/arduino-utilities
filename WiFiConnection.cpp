#include "WiFiConnection.h"

WiFiConnection::WiFiConnection()
: _server(80) {}

void WiFiConnection::checkStatus() {
    if (WiFi.status() == WL_NO_MODULE) {
        Serial.println("Communication with WiFi module failed!");
        while (true);
    }
    if (WiFi.firmwareVersion() < WIFI_FIRMWARE_LATEST_VERSION) {
        Serial.println("Please upgrade the WiFi firmware!");
    }
}

void WiFiConnection::broadcast(char ssid[]) {
    checkStatus();

    if (WiFi.beginAP( ssid ) != WL_AP_LISTENING) {
        Serial.println("Creating access point failed!");
        while (true);
    }

    _server.begin();
    Serial.print("Access point connected at: http://");
    Serial.println(WiFi.localIP());
}

void WiFiConnection::connect(char ssid[], char pass[]) {
    checkStatus();
    int status = WL_IDLE_STATUS;

    while (status != WL_CONNECTED) {
        Serial.print("Connecting to: ");
        Serial.print(ssid);
        status = WiFi.begin(ssid, pass);
    }

    _server.begin();
    Serial.print("Connected at: http://");
    Serial.println(WiFi.localIP());
}

void WiFiConnection::listen(void (*handleRequest)(String)) {
    WiFiClient client = _server.available();

    if (client) {
        String currentLine = "";
        while (client.connected()) {
            if (client.available()) {
                char c = client.read();
                if (c == '\n') {
                    if (currentLine.length() == 0) {
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-type:text/html");
                        client.println();
                        break;
                    } else {
                        handleRequest(currentLine);
                        currentLine = "";
                    }
                } else if (c != '\r') {
                    currentLine += c;
                }
            }
        }

        client.stop();
    }
}
