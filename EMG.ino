#include <Servo.h>
Servo myservo;
const int threshhold = 250;


void setup() {
  myservo.attach(3);
  
}

void loop() {
int value = analogRead(A3);

if (value<threshhold){

  myservo.writeMicroseconds(800);
}
else{
  myservo.writeMicroseconds(2250);
}
}
