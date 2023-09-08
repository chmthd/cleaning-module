#include "server_header.h"
#include "config.h"
#include "ArduinoRobotControl.ino"

void setupServer() {
    server.on("/", HTTP_GET, handleRoot);
    server.on("/forward", HTTP_GET, handleForward);
    server.on("/left", HTTP_GET, handleLeft);
    server.on("/right", HTTP_GET, handleRight);
    server.on("/stop", HTTP_GET, handleStop);
  
    WiFi.begin(ssid, password); // Use Wi-Fi credentials from config.h
  
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Connecting to WiFi...");
    }
  
    Serial.println("Connected to WiFi");
    server.begin();
  }
  
  void handleRoot() {
    server.send(200, "text/plain", "Welcome to Robot Control");
  }
  
  void handleForward() {
    // Implement forward movement logic here
    server.send(200, "text/plain", "Moving forward");
  }
  
  void handleLeft() {
    // Implement left turn logic here
    server.send(200, "text/plain", "Turning left");
  }
  
  void handleRight() {
    // Implement right turn logic here
    server.send(200, "text/plain", "Turning right");
  }
  
  void handleStop() {
    // Implement stop logic here
    server.send(200, "text/plain", "Stopped");
  }
  