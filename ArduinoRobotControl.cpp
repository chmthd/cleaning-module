#include <AFMotor.h>

// Define motor pins
AF_DCMotor motor1(1); // Motor 1
AF_DCMotor motor2(2); // Motor 2

void setup() {
  // Initialize motors
  motor1.setSpeed(255); // Set the motor speed (0-255)
  motor2.setSpeed(255);
}

void loop() {
  // Move the robot forward
  motor1.run(FORWARD); // Motor 1 forward
  motor2.run(FORWARD); // Motor 2 forward
  
  delay(1000); // Move forward for 1 second
  
  // Stop the robot
  motor1.run(RELEASE); // Release motor 1
  motor2.run(RELEASE); // Release motor 2
  
  delay(1000); // Pause for 1 second
  
  // Turn the robot left
  motor1.run(BACKWARD); // Motor 1 backward
  motor2.run(FORWARD);  // Motor 2 forward
  
  delay(1000); // Turn left for 1 second
  
  // Stop the robot
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  
  delay(1000); // Pause for 1 second
}
