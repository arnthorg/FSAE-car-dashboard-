
#include <OneWire.h>
#include <DallasTemperature.h>




const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to
uint8_t a;
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
static const  uint8_t TMAPref[256] = {
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,138,135,133,131,128,126,124,123,121,120,118,118,117,
  115,114,113,112,111,110,110,109,108,107,107,106,105,104,
  104,103,102,102,101,101,100,99,99,98,98,97,97,96,96,95,95,
  94,93,93,92,92,91,91,90,90,89,89,88,88,87,87,86,86,85,85,
  85,84,84,83,83,82,82,81,81,80,80,80,79,79,78,78,77,77,77,
  76,76,75,75,75,74,74,73,73,73,72,72,71,71,71,70,70,69,69,
  69,68,68,67,67,67,66,66,65,65,64,64,64,63,63,63,62,62,61,
  61,60,59,59,59,58,58,57,57,57,56,56,55,55,55,55,54,54,54,
  54,53,53,53,52,52,52,52,51,51,51,50,50,49,49,48,48,48,47,
  47,47,46,46,45,45,44,44,43,43,42,42,41,41,40,40,39,38,38,
  37,36,35,35,34,33,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  analogReference(EXTERNAL);
}

void loop() {
  sensorValue = analogRead(0);
  Serial.print("result from analogread");
  Serial.println(sensorValue);
  Serial.print("result from lookup: ");
  Serial.println(TMAPref[sensorValue/4]-30); //muna -30 til að leiðrétta gildið.
  delay(780);

  /*// read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // print the results to the serial monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.print(outputValue);
  Serial.print("\tresult from lookup: ");
  Serial.println(tempRef[outputValue/4]);
  delay(750);

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);*/
}

