#include <Servo.h>
Servo steeringServo;
int servoPin = 9;
int zeroSteerAngle = 97; // Calibrated zero-steer angle

int speedPin = 6;
int dirxnPin = 7;
int brakePin = 8;

boolean dirxnValue = 0;
int speedValue = 0;
boolean brakeValue = 0;

void setup()
{
  Serial.begin(115200); // Initialize the serial port
  steeringInit(); // Initialize steering actuator
  driveInit(); // Initialize drive actuators
}

void loop()
{
  Serial.println("Drive Forward");
  dirxnValue = 0;
  speedValue = 200;
  brakeValue = 0;
  digitalWrite(dirxnPin, dirxnValue);
  analogWrite(speedPin, speedValue);
  digitalWrite(brakePin, brakeValue);
  
  Serial.println("Zero Steer");
  steeringServo.write(zeroSteerAngle);
  delay(1000);
  Serial.println("Steer Left");
  steeringServo.write(zeroSteerAngle-30);
  delay(1000);
  Serial.println("Zero Steer");
  steeringServo.write(zeroSteerAngle);
  delay(1000);
  Serial.println("Steer Right");
  steeringServo.write(zeroSteerAngle+30);
  delay(1000);
  Serial.println("Zero Steer");
  steeringServo.write(zeroSteerAngle);
  delay(1000);

  Serial.println("Brake");
  speedValue = 0;
  brakeValue = 1;
  analogWrite(speedPin, speedValue);
  digitalWrite(brakePin, brakeValue);

  delay(1000);
  
  Serial.println("Drive Reverse");
  dirxnValue = 1;
  speedValue = 200;
  brakeValue = 0;
  digitalWrite(dirxnPin, dirxnValue);
  analogWrite(speedPin, speedValue);
  digitalWrite(brakePin, brakeValue);

  Serial.println("Zero Steer");
  steeringServo.write(zeroSteerAngle);
  delay(1000);
  Serial.println("Steer Left");
  steeringServo.write(zeroSteerAngle-30);
  delay(1000);
  Serial.println("Zero Steer");
  steeringServo.write(zeroSteerAngle);
  delay(1000);
  Serial.println("Steer Right");
  steeringServo.write(zeroSteerAngle+30);
  delay(1000);
  Serial.println("Zero Steer");
  steeringServo.write(zeroSteerAngle);
  delay(1000);

  Serial.println("Brake");
  speedValue = 0;
  brakeValue = 1;
  analogWrite(speedPin, speedValue);
  digitalWrite(brakePin, brakeValue);

  delay(1000);
}

void steeringInit()
{
  steeringServo.write(zeroSteerAngle); // Initialize servo on power-up to zero-steer angle
  steeringServo.attach(servoPin); // Initialize the steering actuator
}

void driveInit()
{ 
  pinMode(speedPin, OUTPUT); // Declare speed pin
  pinMode(brakePin, OUTPUT); // Declare brake pin
  pinMode(dirxnPin, OUTPUT); // Declare direction pin
}
