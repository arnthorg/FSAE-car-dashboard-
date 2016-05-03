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

int8_t manifoldTempRef(int8_t value) {
static const int8_t lookup[256] = {
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0, 108, 103, 101,  99,  96,  95,  91,
  91,  89,  88,  87,  86,  85,  84,  83,  83,  81,  80,  79,
  79,  78,  78,  77,  76,  75,  75,  74,  74,  73,  72,  71,
  70,  69,  67,  67,  67,  66,  66,  65,  64,  64,  63,  62,
  61,  61,  61,  60,  60,  59,  59,  58,  58,  57,  56,  56,
  55,  55,  55,  55,  54,  53,  53,  52,  52,  51,  51,  50,
  50,  49,  49,  49,  48,  48,  47,  47,  46,  46,  46,  45,
  45,  44,  44,  43,  43,  43,  42,  42,  41,  41,  40,  40,
  40,  39,  39,  38,  38,  38,  37,  37,  36,  36,  36,  35,
  35,  34,  34,  34,  33,  33,  32,  32,  32,  31,  31,  31,
  30,  30,  29,  29,  29,  28,  28,  27,  27,  27,  26,  26,
  25,  25,  25,  24,  24,  23,  23,  23,  22,  22,  21,  21,
  21,  20,  20,  20,  19,  19,  18,  18,  18,  17,  17,  16,
  16,  15,  15,  15,  15,  14,  14,  13,  13,  13,  12,  12, 
  11,  11,  10,  10,  10,  -1,  -2,  -2,  -3,  -3,  -4,  -5,  
  -5,  -6,  -7,  -8,  -9, -10, -10,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 
   0,   0,   0,   0,   0,   0,   0,   0,   0};

return lookup[value];
}
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
   if (val == 't') {
    //þetta er til að mæla spennu og skila úr lookup töflu
    Serial.println( manifoldTempRef(analogRead(A0)/4)); 
   }
   if (val == 'V') {

    Serial.println(analogRead(A0)*5.0/1024.0, 5); //þetta er til að mæla spennuna
    
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


