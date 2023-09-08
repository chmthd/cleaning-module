#include <config.h>
#include <AFMotor.h>
#include <NewPing.h>

// Motor pins
AF_DCMotor motor1(1); // Motor 1
AF_DCMotor motor2(2); // Motor 2

// Ultrasonic sensor pins
#define TRIGGER_PIN triggerPin 
#define ECHO_PIN echoPin     
#define MAX_DISTANCE 200

// Bumper switch pins
#define BUMPER_FRONT_PIN bumperFrontPin  
#define BUMPER_LEFT_PIN bumperLeftPin    
#define BUMPER_RIGHT_PIN bumperRightPin  

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  motor1.setSpeed(255); // Set motor speed (0-255)
  motor2.setSpeed(255);

  pinMode(BUMPER_FRONT_PIN, INPUT_PULLUP);
  pinMode(BUMPER_LEFT_PIN, INPUT_PULLUP);
  pinMode(BUMPER_RIGHT_PIN, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  int distance = sonar.ping_cm();

  bool frontBumper = digitalRead(BUMPER_FRONT_PIN) == LOW;
  bool leftBumper = digitalRead(BUMPER_LEFT_PIN) == LOW;
  bool rightBumper = digitalRead(BUMPER_RIGHT_PIN) == LOW;

  if (distance < 20 || frontBumper || leftBumper || rightBumper) {
    stop();
    turnRight(); 
  } else {
    moveForward();
  }
}

void moveForward() {
  motor1.run(FORWARD); 
  motor2.run(FORWARD); 
}

void stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE); 
}

void turnRight() {
  motor1.run(FORWARD); 
  motor2.run(BACKWARD);
  delay(1000); 
  stop();
}
