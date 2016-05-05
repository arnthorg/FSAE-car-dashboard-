#define Data 3 // D3
#define CP 4 //   D4
const byte interruptPin = 2;
const short BAR_SIZE = 10;
volatile byte state = LOW;
unsigned long lastInterrupt;
unsigned long currentInterrupt;
//unsigned int deltaT;
float deltaT;
unsigned short pos =0;
double rpm[10] = {0};
unsigned int rpmAvg;
double sum;
bool barGraphArr[BAR_SIZE] = {0};



void setup() {
  
  Serial.begin(9600);
  pinMode(interruptPin, INPUT_PULLUP);
  pinMode(Data, OUTPUT);
  pinMode(CP, OUTPUT);  
  delay(100);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, RISING);
}

void loop() {
  calcRpmAvg();
  Serial.print("rpm: ");
  Serial.println(rpmAvg);
  barGraph(rpmAvg);
  for(int iter = 0; iter < BAR_SIZE; iter++){
    Serial.print(barGraphArr[BAR_SIZE - iter - 1]); // inverting the output
    
  }
  Serial.println("");
  delay(200);
}
void barGraph(int rpm) {
  num2array(rpm);
  for(int iter = 0; iter < BAR_SIZE; iter++ ) {
    digitalWrite(Data, barGraphArr[BAR_SIZE - iter - 1]); // inverting the output
    digitalWrite(CP, 1);
    digitalWrite(CP, 0);
  }
}
void calcRpmAvg() {
    sum  = 0;
  for(int iter = 0; iter <10; iter++) {
    sum += rpm[iter];
  }
  rpmAvg = sum/10;
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
  int range = 6000/BAR_SIZE;
  for( int iter = 0; iter < BAR_SIZE; iter++) {
    if(rpm > range * iter) {
      barGraphArr[iter] = 1;
    }
    else barGraphArr[iter] = 0;
  }
}

