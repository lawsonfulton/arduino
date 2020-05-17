opconst int ledPin = 13; // LED on the Arduino
const int hrPin = A0; // Pin used for Heartrate input

void setup ()
{
  pinMode (ledPin, OUTPUT);
  Serial.begin (115200);
}

int curVal = 500; // Stores the current value on the heartrate pin 
int prevVal = 500; // Stores the value read in the last loop
int dt = 1; // Timestep in milliseconds
void loop()
{
  prevVal = curVal;
  curVal = analogRead(hrPin);

  const int dVdt = prevVal - curVal / dt; // TODO(lawson) Can we use only integer math here?

  Serial.print(curVal);
  Serial.print(dVdt);
  
  delay(dt);
}
