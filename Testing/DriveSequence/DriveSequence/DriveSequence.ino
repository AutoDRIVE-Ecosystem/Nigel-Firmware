#include <SparkFun_TB6612.h>

#define FAIN1 A5
#define FBIN1 A3
#define FAIN2 A6
#define FBIN2 A2
#define FPWMA 10
#define FPWMB 11
#define FSTBY A4

#define RAIN1 A10
#define RBIN1 A8
#define RAIN2 A11
#define RBIN2 A7
#define RPWMA 8
#define RPWMB 9
#define RSTBY A9

const int FOffsetA = 1; // Direction offset for A channel
const int FOffsetB = -1; // Direction offset for B channel
const int ROffsetA = -1; // Direction offset for A channel
const int ROffsetB = 1; // Direction offset for B channel
Motor motorFR = Motor(FAIN1, FAIN2, FPWMA, FOffsetA, FSTBY);
Motor motorFL = Motor(FBIN1, FBIN2, FPWMB, FOffsetB, FSTBY);
Motor motorRR = Motor(RAIN1, RAIN2, RPWMA, ROffsetA, RSTBY);
Motor motorRL = Motor(RBIN1, RBIN2, RPWMB, ROffsetB, RSTBY);

void setup()
{
}


void loop()
{
  // Brake
  brake(motorFL, motorFR);
  brake(motorRL, motorRR);
  delay(1000);

  // Drive forward
  forward(motorFL, motorFR, 255);
  forward(motorRL, motorRR, 255);
  delay(2000);

  // Brake
  brake(motorFL, motorFR);
  brake(motorRL, motorRR);
  delay(1000);

  // Drive reverse
  forward(motorFL, motorFR, -255);
  forward(motorRL, motorRR, -255);
  delay(2000);
}