/*
  ReadAnalogVoltage
  Reads an analog input on pin 0, converts it to voltage, and prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

 This example code is in the public domain.
 */

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
}

// the loop routine runs over and over again forever:
void loop() {
  //while(Serial.available() ==0 /* && !Serial.find('R')*/);
  /*delay(100);
  //int num = Serial.read();
  //for(int i = 0; i<256;i++) {
    Serial.print(12345);
 // }
  //delay(10);
  for(int iter=0;iter<256;iter++){
    Serial.print(iter);
    Serial.print("\t");
    Serial.println(255-iter);
  }*/
}
void serialEvent() {
  delay(100);
  for(int iter=0;iter<256;iter++){
    Serial.print(iter);
    Serial.print(" ");
    Serial.println(255-iter);
    delay(10);
  }  
}

