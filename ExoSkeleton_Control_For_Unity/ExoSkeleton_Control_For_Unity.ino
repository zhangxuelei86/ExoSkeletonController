int servoAnalogInPin = A3;
int posIs;
//byte means to store an 8-bit unsigned number from 0 to 255
byte sendValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  posIs = analogRead(servoAnalogInPin);
  sendValue = map(posIs, 80, 350, 0, 255);
  Serial.flush();
  delay(20);
}
