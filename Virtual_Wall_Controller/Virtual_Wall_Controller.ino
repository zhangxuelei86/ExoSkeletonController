#include <Servo.h>

Servo myservo;
int forceAnalogInPin = A3;
const int forceOffset = 439;
int forceIs;
int forceDesired = 0;
int positionDesired = 40;
float gain = 0.2;
int maxAngle = 70;
int minAngle = 20;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(3);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  forceIs = analogRead(forceAnalogInPin)-forceOffset;
  delay(10);
  positionDesired -= gain*(forceIs-forceDesired);
  myservo.write(positionDesired);
  if(positionDesired > maxAngle) {
    positionDesired = maxAngle;
  }
  else if(positionDesired < minAngle){
    positionDesired = minAngle;
  }
}  
