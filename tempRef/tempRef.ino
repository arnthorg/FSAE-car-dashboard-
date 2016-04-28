


String input = "";
bool stringComplete = 0;
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    input += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
void setup() {
 Serial.begin(9600);
  input.reserve(10);
}

void loop() {
  while(!stringComplete ) {
    delay(1);
  }
  for(int iter = 0;iter <256;iter++) {
    Serial.print(iter);
    Serial.print("\t");
    Serial.println(255-iter);
    delay(50);
  }

}

