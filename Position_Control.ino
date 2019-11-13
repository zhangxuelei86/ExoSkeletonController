#include <Servo.h> 
Servo myservo; 
int positionDesired; 
int counter = 0; 
int reps = 6;  
void setup() { 
  Serial.begin(9600); 
  myservo.attach(3); 
 } 
 void loop() { 
 positionDesired = 60; 
 myservo.write(positionDesired); 
 delay(2000); 
 positionDesired = 150; 
 myservo.write(positionDesired); 
 delay(2000); 
 counter++; 
 if(counter == reps) 
 { 
 exit(0); 
 } 

}
