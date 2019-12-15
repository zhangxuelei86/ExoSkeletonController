int forceAnalogInPin = A3;
int forceIs;
const int forceOffset = 439;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  forceIs = analogRead(forceAnalogInPin);
  forceIs -= forceOffset;
  Serial.print("Force: ");
  Serial.println(forceIs);
  delay(10);
}
