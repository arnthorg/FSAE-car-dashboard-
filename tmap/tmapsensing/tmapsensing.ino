// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
unsigned int count = 0;
char val  = 0;
bool toggle = 1;
/*
 * The setup function. We only start the sensors here
 */
void setup(void)
{
  // start serial port
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Serial.println('a');
  char a = 'b';
  while( a != 'a') {
    a = Serial.read();
    count++;
    if(count > 25000) {
      digitalWrite(13,toggle);
      toggle = !toggle;
      count = 0;
    }
  }
  digitalWrite(13,0);
  // Start up sensor lib
  sensors.begin();
  sensors.setResolution(TEMP_12_BIT);
}

/*
 * Main function, get and show the temperature
 */
void loop(void)
{ 
  while (Serial.available() == 0);
  val = Serial.read();
   if (val == 'T') {
     Serial.println(getTemp(0), 5);
   } 
   if (val == 'V') {
    Serial.println(analogRead(A0)*5.0/1024.0, 5);
   }
      count++;
    if(count > 2^16) {
      digitalWrite(13,toggle);
      toggle = !toggle;
      count = 0;
    }
  delay(20);
}

float getTemp( int index ) {
  sensors.requestTemperatures();
  return sensors.getTempCByIndex(index);
}


