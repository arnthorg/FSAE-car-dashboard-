#define interruptPin2 2
#define interruptPin3 3
#define Data 4 // D3
#define CP 5 //   D4
#define Data7 6 //D5
#define CP7 7 
#define Latch7 8
#define gearUp 9
#define gearDown 10
#define neutral 11

const unsigned short MAX_RPM = 9100;
const short BAR_SIZE = 10;
const byte digit[8] = { 0b00101010,  0b01100000,
                  0b11011010, 0b11110010, 0b01100110, 
                  0b10110110, 0b00001010, 0b10011110};

unsigned long g_lastInterrupt;
unsigned short g_pos =0;
double g_rpm[10] = {0};
bool g_barGraphArr[BAR_SIZE] = {0};
bool g_periodOn7SegDisp = 0;
short g_selectedGear = 32;


void setup() {
  
  Serial.begin(9600);
  pinMode(interruptPin2, INPUT);
  pinMode(interruptPin3, INPUT); //external pulldown
  pinMode(Data, OUTPUT);
  pinMode(CP, OUTPUT);  
  pinMode(CP7, OUTPUT); 
  pinMode(Data7, OUTPUT); 
  pinMode(Latch7, OUTPUT); 
  PORTD &= ~((1<<Data7) | (1<<CP7) | (1<<Latch7)); // unsetting bits 5-7
  //delay(100); //maybe this delay is important?
  attachInterrupt(digitalPinToInterrupt(interruptPin2), blink, RISING);
  attachInterrupt(digitalPinToInterrupt(interruptPin3), setGear, RISING);
  if(!neutral) sevenSeg(7); //display E on 7seg
  else { 
    g_selectedGear = 1; // 1 being neutral
    sevenSeg(1);
  }
}
//todo watchdog timer
/*static volatile int shared_variable ; // er að reyna að fækka global breytum

int getShared(){ return shared_variable ; }

static void isr_handler()
{
    shared_variable++ ;
}*/ 
void loop() {
  barGraph(calcRpmAvg());
  sevenSeg(g_selectedGear); // refresh display periodically
  /*Serial.print("rpm: ");
  Serial.println(rpmAvg);
  
  Serial.println("");*/
  /*for(int iter = 0;iter<8;iter++) {
    sevenSeg(iter);
    //shiftOut(Data7, CP7, MSBFIRST, 1<<iter);
    delay(500);
  }
  periodOn7SegDisp = !periodOn7SegDisp;*/
  
  delay(200);
}
void setGear() {
  if(neutral && g_selectedGear >6) g_selectedGear = 1;
  else if(gearUp && g_selectedGear < 6) g_selectedGear++;
  else if(gearDown && g_selectedGear > 0) g_selectedGear--;
  sevenSeg(g_selectedGear);
}

void barGraph(int rpm) {
  num2array(rpm);
  for(int iter = 0; iter < BAR_SIZE; iter++ ) {
    bool x = g_barGraphArr[BAR_SIZE - iter - 1];
    PORTD ^= (-x ^ PORTD) & (1 << 3); 
    PORTD |= (1<<4);
    PORTD &= ~(1<<4);
  }
}

unsigned int calcRpmAvg() {
  double sum  = 0;
  for(int iter = 0; iter <10; iter++) {
    sum += g_rpm[iter];
  }
  return sum/10;
}

void blink() {
  unsigned long currentInterrupt = micros();
  if((currentInterrupt - g_lastInterrupt ) > 5*1000) { //debounce
    calculateRpm(currentInterrupt);
    g_lastInterrupt = currentInterrupt;
  }
}

void calculateRpm(unsigned long currentInterrupt) { //calculates RPM from deltaT 
  float deltaT;
  deltaT = currentInterrupt - g_lastInterrupt;
  deltaT = 1e6/deltaT;
  deltaT *= 60;
  g_rpm[g_pos] = deltaT;
  g_pos++;
  if(g_pos >9) g_pos = 0;
}

void num2array(double rpm) { // converts rpm to an array of bits to bang into shift registers
  int range = MAX_RPM/BAR_SIZE;
  for( int iter = 0; iter < BAR_SIZE; iter++) {
    if(rpm > range * iter) {
      g_barGraphArr[iter] = 1;
    }
    else g_barGraphArr[iter] = 0;
  }
}

void sevenSeg(short symbol) {
  byte digitTmp = 0;
  if(symbol >6) 
    digitTmp = digit[7]; //if symbol is greater than 6 display E
  else {
    digitTmp = digit[symbol];
  }
  digitTmp ^= (-g_periodOn7SegDisp ^ digitTmp) & 1;
  
  shiftOut(Data7, CP7, LSBFIRST, ~digitTmp);
  PORTD |= (1<<Latch7);
  delayMicroseconds(5); //datasheet segir 200ns min en þarf alveg 5µs t_w
  PORTD &= ~(1<<Latch7);
}
