int forceAnalogInPin = A3; 
int forceIs;
const int forceOffset = 7; 
 void setup(){ 
 Serial.begin(9600); 
 delay(1000); } 
 void loop(){ 
 forceIs = sqrt(analogRead(forceAnalogInPin)/8); 
 forceIs -= forceOffset;
 Serial.print("Force: "); 
 Serial.println(forceIs); 
 delay(100); 
 }
