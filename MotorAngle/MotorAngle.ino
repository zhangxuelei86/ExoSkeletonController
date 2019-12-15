int servoAnalogPin = A0;
int posIs;
float posIsDeg;

void setup() {
  //put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  //put your main code here, to run repeatedly:
  posIs = analogRead(servoAnalogPin);
  posIsDeg = (90.0/(255.0-80.0))*(posIs-80);
  Serial.print("Position (in degree):");
  Serial.println(posIsDeg);
  delay(10);
}
