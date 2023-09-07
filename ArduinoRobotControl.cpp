#include <AFMotor.h>
#include <NewPing.h>

// Motor pins
AF_DCMotor motor1(1); // Motor 1
AF_DCMotor motor2(2); // Motor 2

// Ultrasonic sensor pins
#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define MAX_DISTANCE 200

// Bumper switch pins
#define BUMPER_FRONT_PIN 2
#define BUMPER_LEFT_PIN 3
#define BUMPER_RIGHT_PIN 4

// Create an Ultrasonic sensor object
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  // Initialize motors
  motor1.setSpeed(255); // Set motor speed (0-255)
  motor2.setSpeed(255);

  // Set bumper switch pins as inputs
  pinMode(BUMPER_FRONT_PIN, INPUT_PULLUP);
  pinMode(BUMPER_LEFT_PIN, INPUT_PULLUP);
  pinMode(BUMPER_RIGHT_PIN, INPUT_PULLUP);

  // Initialize Serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read ultrasonic sensor for obstacle detection
  int distance = sonar.ping_cm();

  // Read bumper switches
  bool frontBumper = digitalRead(BUMPER_FRONT_PIN) == LOW;
  bool leftBumper = digitalRead(BUMPER_LEFT_PIN) == LOW;
  bool rightBumper = digitalRead(BUMPER_RIGHT_PIN) == LOW;

  // If an obstacle is detected or a bumper is hit, stop and turn
  if (distance < 20 || frontBumper || leftBumper || rightBumper) {
    stop();
    turnRight(); // You can change the turn direction based on your robot's design
  } else {
    moveForward();
  }
}

void moveForward() {
  motor1.run(FORWARD); // Motor 1 forward
  motor2.run(FORWARD); // Motor 2 forward
}

void stop() {
  motor1.run(RELEASE); // Release motor 1
  motor2.run(RELEASE); // Release motor 2
}

void turnRight() {
  motor1.run(FORWARD); // Motor 1 forward
  motor2.run(BACKWARD); // Motor 2 backward
  delay(1000); // Adjust the delay for the desired turn duration
  stop();
}
