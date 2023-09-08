#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

extern ESP8266WebServer server;

void setupServer();
void handleRoot();
void handleForward();
void handleLeft();
void handleRight();
void handleStop();

#endif
