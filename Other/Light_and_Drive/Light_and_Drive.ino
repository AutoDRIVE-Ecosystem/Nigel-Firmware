#include <Servo.h>
int servoPin = 9;
Servo steeringServo;
int zeroSteerAngle = 97; // Calibrated zero-steer angle

int speedPin = 6;
int dirxnPin = 7;
int brakePin = 8;

int tailLights = 10;
int headLightsLB = 11;
int headLightsHB = 12;

void setup()
{
  SteeringServoInit(); // Initialize the steering servo
  MotorDriverInit(); // Initialize the motor driver
  pinMode(tailLights, OUTPUT);
  pinMode(headLightsLB, OUTPUT);
  pinMode(headLightsHB, OUTPUT);

  digitalWrite(dirxnPin, 0);
  analogWrite(speedPin, 0);
  digitalWrite(brakePin, 0);
  steeringServo.write(zeroSteerAngle);
  delay(10000);
  digitalWrite(headLightsLB, 1);
  digitalWrite(headLightsHB, 1);
  analogWrite(tailLights, 255);
  delay(1000);
  digitalWrite(dirxnPin, 0);
  analogWrite(speedPin, 200);
  digitalWrite(brakePin, 0);
  delay(4000);
  digitalWrite(dirxnPin, 0);
  analogWrite(speedPin, 0);
  digitalWrite(brakePin, 0);
  delay(1000);
  digitalWrite(headLightsLB, 0);
  digitalWrite(headLightsHB, 0);
  analogWrite(tailLights, 0);
}

void loop()
{ 
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
