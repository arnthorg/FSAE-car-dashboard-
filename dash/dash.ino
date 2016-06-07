

#include "stdbool.h"
#include <avr/wdt.h> // watchdog
#include <EEPROM.h>
#define interruptPin2 2
#define interruptPin3 3
#define Data 4 // D4
#define CP 5 //   D5
#define Data7 6 //D6
#define CP7 7
#define Latch7 8 //PORTB tekur við
#define gearUp 9
#define gearDown 10
#define neutral 11
#define shiftLight 12
#define oilP A0


const unsigned short SHIFT_RPM = 8000;
const unsigned short MAX_RPM = 9100;
const short BAR_SIZE = 24;
const byte digit[8] = { B00001010, B01100000, B00101010,         //r,1,n,2,3,4,5,E
                        B11011010, B11110010, B01100110,
                        B10110110, B10011110
                      };

volatile unsigned long g_lastInterrupt;
volatile unsigned long g_lastInterrupt2;
volatile unsigned short g_pos = 0;
double g_rpm[10] = { 0 };
bool g_barGraphArr[BAR_SIZE] = { 0 };
bool g_periodOn7SegDisp = 0;
volatile short g_selectedGear = 32;


void setup() {

  Serial.begin(9600);
  pinMode(interruptPin2, INPUT);
  pinMode(interruptPin3, INPUT); 
  pinMode(neutral, INPUT_PULLUP); 
  pinMode(Data, OUTPUT);
  pinMode(CP, OUTPUT);
  pinMode(CP7, OUTPUT);
  pinMode(Data7, OUTPUT);
  pinMode(Latch7, OUTPUT);
  pinMode(shiftLight, OUTPUT);
  pinMode(gearUp, INPUT_PULLUP);
  pinMode(gearDown, INPUT_PULLUP);
  digitalWrite(gearUp, 1);
  digitalWrite(gearDown, 1);
  digitalWrite(neutral, 1);
  //PORTD &= ~((1 << Data7) | (1 << CP7) | (1 << Latch7)); // unsetting bits, dno if needed
  PORTD = 0;
  PORTB = 0;
  delay(100); //maybe this delay is important?
  attachInterrupt(digitalPinToInterrupt(interruptPin2), blink, RISING);
  attachInterrupt(digitalPinToInterrupt(interruptPin3), setGear, FALLING);
  if ((PINB & (1 << neutral - 8))) sevenSeg(7); //display E on 7seg if n is high
  else {
    g_selectedGear = 2; // 2 being neutral
    sevenSeg(1);
  }
}
// todo:
// watchdog timer
// skjár
// lesa frá mælum
void loop() {
  //digitalWrite(shiftLight, 1);
  barGraph(calcRpmAvg());

  /*for (int iter = 2; iter < 7; iter++) {
    sevenSeg(iter);
    
    delay(500);
    for (int iter = 600; iter < 9100; iter++) {
      barGraph(iter);
      delay(0.1);
      
      
    }
    //
  Serial.println("lol");
  
  }*/
  /*for(int iter = 0; iter <7; iter++) {
    sevenSeg(iter);
    Serial.print(iter);
    Serial.println(": wub");
    delay(1000);
    }*/
  //Serial.println(g_selectedGear);
  delay(2);
}
void setGear() { //int 1
  //Serial.println("gearchange");
  /*if (!(PINB & (1 << (neutral - 8)))) {          //
    g_selectedGear = 2;           //2 being neutral
    return;
  }*/
  bool gearUpState = (PINB & (1 << (gearUp - 8)));
  bool gearDownState = (PINB & (1 << (gearDown - 8)));
  unsigned long currentInterrupt = micros();
  if ((currentInterrupt - g_lastInterrupt2) > 1.5e5) { //debounce 150ms
    if (!(PINB & (1 << (neutral - 8)))) {          // ef neutral er low
    g_selectedGear = 2;           //2 being neutral
    return;
     }
    if (!gearUpState && g_selectedGear < 6) {
      g_selectedGear++;
      //Serial.println("gearUp");
    }
    else if (!gearDownState && g_selectedGear > 1) {
      g_selectedGear--;
      //Serial.println("gearDown");
    }
    sevenSeg(g_selectedGear);
    g_lastInterrupt2 = currentInterrupt;
  }
}

void barGraph(int rpm) {
  num2array(rpm);
  for (int iter = 0; iter < BAR_SIZE; iter++) {
    bool x = g_barGraphArr[BAR_SIZE - iter - 1];
    PORTD ^= (-x ^ PORTD) & (1 << Data);
    PORTD |= (1 << CP);
    PORTD &= ~(1 << CP);
  }
}

unsigned int calcRpmAvg() {
  double sum = 0;
  for (int iter = 0; iter < 10; iter++) {
    sum += g_rpm[iter];
  }
  return sum / 10;
}

void blink() { // int0
  unsigned long currentInterrupt = micros();
  if ((currentInterrupt - g_lastInterrupt) > 5 * 1000) { //debounce
    calculateRpm(currentInterrupt);
    g_lastInterrupt = currentInterrupt;
  }
  if(g_rpm[g_pos] >= SHIFT_RPM) {
    PORTB |= (1<<shiftLight-8);
  }
  else 
    PORTB &= ~(1<<shiftLight-8);
}

void calculateRpm(unsigned long currentInterrupt) { //calculates RPM from deltaT
  float deltaT;
  deltaT = currentInterrupt - g_lastInterrupt;
  deltaT = 1e6 / deltaT;
  deltaT *= 60;
  g_rpm[g_pos] = deltaT;
  g_pos++;
  if (g_pos > 9) g_pos = 0;
}

void num2array(double rpm) { // converts rpm to an array of bits to bang into shift registers
  int range = MAX_RPM / BAR_SIZE;
  for (int iter = 0; iter < BAR_SIZE; iter++) {
    if (rpm > range * iter) {
      g_barGraphArr[iter] = 1;
    }
    else g_barGraphArr[iter] = 0;
  }
}
void sevenSeg(short symbol) {
  byte digitTmp = 0;
  if (symbol > 6)
    digitTmp = digit[7]; //if symbol is greater than 6 display E
  else {
    digitTmp = digit[symbol];
  }
  digitTmp ^= (-g_periodOn7SegDisp ^ digitTmp) & 1;

  shiftOut(Data7, CP7, LSBFIRST, ~digitTmp);
  PORTB |= 1; //(1<<Latch7-8);
  delayMicroseconds(10); //datasheet segir 200ns min en þarf alveg 10µs t_w
  PORTB &= ~1; //(1<<Latch7-8);
}
