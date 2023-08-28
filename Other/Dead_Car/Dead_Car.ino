#include <Servo.h>
int servoPin = 9;
Servo steeringServo;
int zeroSteerAngle = 97; // Calibrated zero-steer angle

int speedPin = 6;
int dirxnPin = 7;
int brakePin = 8;

boolean dirxnValue = 0;
int speedValue = 0;
boolean brakeValue = 0;

void setup()
{
  SteeringServoInit(); // Initialize the steering servo
  MotorDriverInit(); // Initialize the motor driver
}

void loop()
{
  dirxnValue = 0;
  speedValue = 0;
  brakeValue = 0;
  digitalWrite(dirxnPin, dirxnValue);
  analogWrite(speedPin, speedValue);
  digitalWrite(brakePin, brakeValue);
  steeringServo.write(zeroSteerAngle);
}

void SteeringServoInit()
{
  steeringServo.write(zeroSteerAngle); // Initialize servo on power-up to zero-steer angle
  steeringServo.attach(servoPin); // Initialize the steering actuator
}

void MotorDriverInit()
{
  pinMode(speedPin, OUTPUT); // Declare speed pin
  pinMode(brakePin, OUTPUT); // Declare brake pin
  pinMode(dirxnPin, OUTPUT); // Declare direction pin
}
