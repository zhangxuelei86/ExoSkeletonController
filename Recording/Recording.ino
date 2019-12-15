#include <Servo.h>
//library that provides functions to access memory
#include <EEPROM.h>

//every 25 milliseconds we record new trajectory point
#define SAMPLE_DELAY 25
//defines number of trajectory point
#define SAMPLES 200

Servo myservo;
int servoPin = 3;
int servoAnalogInPin = A0;

void setup() {
  // put your setup code here, to run once:
     Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
     Serial.println("Trajectory recording starts in 3 seconds");
     delay(3000);
     recordTrajectory();
     //control algorithm
     delay(3000);
     //set new desired position to the position controller of the servomotor
     replayTrajectory();
}


void recordTrajectory() {
  Serial.println();
  for (int addr=0; addr<SAMPLES; addr++) {
    int posIs = analogRead(servoAnalogInPin);
    byte posIsServo = map(posIs, 119, 332, 0, 100);
    EEPROM.write(addr, posIsServo);
    delay(SAMPLE_DELAY);
    }
    Serial.println("Done recording");
}

//records trajectory sample by sample, and sends it to the motor at deﬁned time intervals.
void replayTrajectory() {
  myservo.attach(servoPin);
  Serial.println("Playing");
    for (int addr=0; addr<SAMPLES; addr++) {
        byte positionDesired = EEPROM.read(addr);
        myservo.write(positionDesired);
        delay(SAMPLE_DELAY);
    }
    Serial.println("Done replaying");
    myservo.detach();
}
