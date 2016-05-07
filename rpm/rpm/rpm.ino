#define Data 4 // D3
#define CP 5 //   D4
#define Data7 6 //D5
#define CP7 7 
#define Latch7 8
const unsigned short MAX_RPM = 9100;
const byte interruptPin = 2;
const short BAR_SIZE = 10;
unsigned long lastInterrupt;
unsigned long currentInterrupt;
float deltaT;
unsigned short pos =0;
double rpm[10] = {0};
unsigned int rpmAvg;
double sum;
bool barGraphArr[BAR_SIZE] = {0};
bool periodOn7SegDisp = 0;
byte digit[8] = { 0b00101010,  0b01100000,
                  0b11011010, 0b11110010, 0b01100110, 
                  0b10110110, 0b00001010, 0b10011110};



void setup() {
  
  Serial.begin(9600);
  pinMode(interruptPin, INPUT_PULLUP);
  pinMode(Data, OUTPUT);
  pinMode(CP, OUTPUT);  
  pinMode(CP7, OUTPUT); 
  pinMode(Data7, OUTPUT); 
  pinMode(Latch7, OUTPUT); 
  digitalWrite(Latch7, 0);
  //PORTD &= ~((1<<5) | (1<<6) | (1<<7)); // unsetting bits 5-7
  delay(100);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, RISING);
}

void loop() {
  calcRpmAvg();
  Serial.print("rpm: ");
  Serial.println(rpmAvg);
  barGraph(rpmAvg);
  Serial.println("");
  for(int iter = 0;iter<8;iter++) {
    sevenSeg(iter);
    //shiftOut(Data7, CP7, MSBFIRST, 1<<iter);
    delay(500);
  }
  periodOn7SegDisp = !periodOn7SegDisp;
  delay(200);
}
void barGraph(int rpm) {
  num2array(rpm);
  for(int iter = 0; iter < BAR_SIZE; iter++ ) {
    bool x = barGraphArr[BAR_SIZE - iter - 1];
    PORTD ^= (-x ^ PORTD) & (1 << Data); 
    PORTD |= (1<<CP);
    PORTD &= ~(1<<CP);
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
  int range = MAX_RPM/BAR_SIZE;
  for( int iter = 0; iter < BAR_SIZE; iter++) {
    if(rpm > range * iter) {
      barGraphArr[iter] = 1;
    }
    else barGraphArr[iter] = 0;
  }
}
void sevenSeg(short symbol) {
  byte digitTmp = digit[symbol];
  digitTmp ^= (-periodOn7SegDisp ^ digitTmp) & 1;
  
  shiftOut(Data7, CP7, LSBFIRST, ~digitTmp);
  //digitalWrite(Latch7, 1);
  //digitalWrite(Latch7, 0);
  PORTD |= (1<<Latch7);
  delayMicroseconds(5); //datasheet segir 200ns min en þarf alveg 5µs t_w
  PORTD &= ~(1<<Latch7);
}

