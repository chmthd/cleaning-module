#ifndef CONFIG_H
#define CONFIG_H

// Wi-Fi Configuration
const char* ssid = "SSID";         // Replace with Wi-Fi SSID
const char* password = "PSWRD"; // Replace with Wi-Fi password

// Motor Pins
const int motor1Pin1 = 5; 
const int motor1Pin2 = 6;
const int motor2Pin1 = 7;
const int motor2Pin2 = 8;

// Ultrasonic Sensor Pins
const int triggerPin = 9; 
const int echoPin = 10;   

// Bumper Switch Pins
const int bumperFrontPin = 2; 
const int bumperLeftPin = 3;
const int bumperRightPin = 4;

#endif 
