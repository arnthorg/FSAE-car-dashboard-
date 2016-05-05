const byte interruptPin = 2;
const short BAR_SIZE = 16;
volatile byte state = LOW;
unsigned long lastInterrupt;
unsigned long currentInterrupt;
//unsigned int deltaT;
float deltaT;
unsigned short pos =0;
double rpm[10] = {0};
double sum;
bool barGraphArr[BAR_SIZE] = {0};



void setup() {
  
  Serial.begin(9600);
  pinMode(interruptPin, INPUT_PULLUP);
  delay(100);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, RISING);
}

void loop() {
  sum  = 0;
  for(int iter = 0; iter <10; iter++) {
    sum += rpm[iter];
  }
  sum = sum/10;
  Serial.print("rpm: ");
  Serial.println(sum);
  delay(200);
}

void blink() {
  currentInterrupt = micros();
  if((currentInterrupt - lastInterrupt ) > 5*1000) { //debounce
    calculateRpm();
    lastInterrupt = currentInterrupt;
    
  }
}
void calculateRpm() {
  deltaT = currentInterrupt - lastInterrupt;
  deltaT = deltaT /1e6;
  deltaT = 1/deltaT;
  deltaT *= 60;
  rpm[pos] = deltaT;
  pos++;
  if(pos >9) pos = 0;
}
void num2array(double rpm) {
  // I want a range from 0-6000RPM divided into 16
  int range = 6000/16;
  for( int iter = 0; iter < BAR_SIZE; iter++) {
    if(rpm > range * iter) {
      barGraphArr[iter] = 1;
    }
    else barGraphArr[iter] = 0;
  }
}

