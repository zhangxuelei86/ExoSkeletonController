#include <Servo.h>
#include <EEPROM.h>

#define SAMPLE_DELAY 25
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
     delay(3000);
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
