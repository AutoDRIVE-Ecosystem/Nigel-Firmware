#include <Servo.h>

int servoLeftPin = 5;
int servoRightPin = 6;
Servo servoLeft;
Servo servoRight;
int zeroSteerLeft = 90; // Calibrated zero-steer angle
int zeroSteerRight = 90; // Calibrated zero-steer angle

void setup()
{
  servoLeft.write(zeroSteerLeft); // Initialize servo on power-up to zero-steer angle
  servoRight.write(zeroSteerRight); // Initialize servo on power-up to zero-steer angle
  servoLeft.attach(servoLeftPin); // Initialize the steering actuator
  servoRight.attach(servoRightPin); // Initialize the steering actuator
}

void loop()
{
  servoLeft.write(zeroSteerLeft);
  servoRight.write(zeroSteerRight);
  delay(1000);
  servoLeft.write(zeroSteerLeft-90);
  servoRight.write(zeroSteerRight-90);
  delay(1000);
  servoLeft.write(zeroSteerLeft);
  servoRight.write(zeroSteerRight);
  delay(1000);
  servoLeft.write(zeroSteerLeft+90);
  servoRight.write(zeroSteerRight+90);
  delay(1000);
}