#include "stdbool.h"
#include <avr/wdt.h> // watchdog
#include <EEPROM.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <PinChangeInterruptBoards.h>
#include <YetAnotherPcInt.h>

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
//fyrir skjá
#define OLED_RESET A3
Adafruit_SSD1306 display(OLED_RESET);


const unsigned short SHIFT_RPM = 8500;
const unsigned short MAX_RPM = 9100;
const char BAR_SIZE = 24;
const byte digit[8] = { B00001010, B01100000, B00101010,         //r,1,n,2,3,4,5,E
                        B11011010, B11110010, B01100110,
                        B10110110, B10011110
                      };
const float FINAL_DRIVE = 32.0/14.0 * 2.88;
const float GEAR_RATIO[8] = {10000, 2.36, 10000, 1.87, 1.53, 1.24, 0.96, 10000 }; //deila með stórri tölu til að fá 0 þegar n eða E er valið
const float PI_OVER_30_TIMES_R = 50*3.14/60/1000;

volatile unsigned long g_lastInterrupt;
volatile unsigned long g_lastInterrupt2;
volatile unsigned char g_pos = 0;
volatile unsigned long g_menuLastInterrupt;
volatile unsigned short g_rpm[10] = { 0 };
volatile unsigned char g_menu = 0;
volatile bool g_barGraphArr[BAR_SIZE] = { 0 };
volatile bool g_periodOn7SegDisp = 0;
volatile char g_selectedGear = 7;
volatile bool g_menuChanged = true;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  //Serial.begin(9600);
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
  pinMode(A0, INPUT); // AFR
  pinMode(A1, INPUT_PULLUP); // mode rofi
  analogReference(DEFAULT);
  PORTD = 0;
  PORTB = 0;
  delay(100); //maybe this delay is important?
  attachInterrupt(digitalPinToInterrupt(interruptPin2), blink, RISING);
  attachInterrupt(digitalPinToInterrupt(interruptPin3), setGear, FALLING);
  PcInt::attachInterrupt(A1, nextMenu, "", FALLING);   //set interrupt A1;
  PcInt::attachInterrupt(gearUp, gearUpRising, "", CHANGE);
  PcInt::attachInterrupt(gearDown, gearDownRising, "", CHANGE);
  //if ((PINB & (1 << neutral - 8))) sevenSeg(7); //display E on 7seg if n is high
  if( (PINB & (1<<gearUp - 8)) && (PINB & (1<<gearDown - 8))) sevenSeg(7); //display E on 7seg if gearUp && gearDown are high
  else {
    g_selectedGear = 2; // 2 being neutral
    sevenSeg(1);
  }
  //fyrir skjá
}

void loop() {
  //delay(250);
  short rpm = calcRpmAvg();
  barGraph(rpm);
  displayUpdate(rpm);
  sevenSeg(g_selectedGear);
  /*bool gearUpState = (PINB & (1 << (gearUp - 8)));
  bool gearDownState = (PINB & (1 << (gearDown - 8)));
  if( !gearUpState && !gearDownState) {
      g_selectedGear = 2;           //2 being neutral
  } */ 
  delay(10);
}
void gearUpRising(const char* message, bool pinstate) {
  bool gearUpState = (PINB & (1 << (gearUp - 8)));
  bool gearDownState = (PINB & (1 << (gearDown - 8)));
  if(gearUpState && !gearDownState && g_selectedGear == 2) { //þá er neutral rofinn líklega að detta út og það er verið að skipta úr n í 1
    g_selectedGear--;
  }
  unsigned long g_lastInterrupt2 = micros(); // til að það skiptist ekki um gír þegar rofinn opnar síðan
}
void gearDownRising(const char* message, bool pinstate) {
  bool gearUpState = (PINB & (1 << (gearUp - 8)));
  bool gearDownState = (PINB & (1 << (gearDown - 8)));
  if(!gearUpState && gearDownState && g_selectedGear == 2) {
    g_selectedGear++;
  }
  unsigned long g_lastInterrupt2 = micros()- 100000; // til að það skiptist ekki um gír þegar rofinn opnar síðan, bæti við 100ms
}
void nextMenu(const char* message, bool pinstate) {
  unsigned long currentInterrupt = micros();
  if ((currentInterrupt - g_menuLastInterrupt) > 5e4) { //debounce 5.0ms
    g_menu++;
    if(g_menu > 1) 
      g_menu = 0;
  }
  g_menuLastInterrupt = currentInterrupt;
  g_menuChanged = true;
}
void displayUpdate(short rpm) {
    if(g_menuChanged) {
      display.clearDisplay();
  }
  switch(g_menu) {
    case 0: { //hraði
      displayPrintThreeNums(rpm * PI_OVER_30_TIMES_R / (FINAL_DRIVE * GEAR_RATIO[g_selectedGear]), 0, 0);
    }
    break;
    case 1: {
       float volts = analogRead(A0)*5.0/102.4;
       displayPrintThreeNums(volts*2.006+49, 0, true);
    }
    break;
    
  }
  if(g_menuChanged) {
      displayPrintVertical(g_menu);
      if(g_menu == 1) {
        display.setCursor(63,45);
        display.write(0x2C);
      }
      g_menuChanged = false;
  }
  display.display();
}
void displayPrintVertical(char choice) {
  switch (choice) {
    case 0: {
      display.setTextSize(3);
      display.setCursor(108,0);
      display.print("K");
      display.setCursor(108,18);
      display.print("m");
      display.setCursor(108,42);
      display.print("h");
      //display.display();
    }
    break;
    case 1: {
      display.setTextSize(2);
      display.setCursor(108,7);
      display.print("A");
      display.setCursor(108,23);
      display.print("F");
      display.setCursor(108,39);
      display.print("R");
      //display.display();
    }
    break;
  }
}
void displayPrintThreeNums(float input, short decimals, bool period) {
  display.setTextSize(6);
  display.setTextColor(BLACK);
  display.setCursor(0,10);
  for(int i = 0; i<3;i++) {
    display.write(0xDA);
  }
  display.setCursor(0,10);
  if(int(input)/10 ==0) display.print(" ");
  if(int(input)/100 ==0) display.print(" ");
  
  display.setTextColor(WHITE);
  display.print(input, decimals);
  //display.display();
}


void setGear() { 
  bool gearUpState = (PINB & (1 << (gearUp - 8)));
  bool gearDownState = (PINB & (1 << (gearDown - 8)));
  unsigned long currentInterrupt = micros();
  if ((currentInterrupt - g_lastInterrupt2) > 20e4) { //debounce 7ms = 7000µs
    //if (!(PINB & (1 << (neutral - 8)))) {          // ef neutral er low
    if( !gearUpState && !gearDownState) {
      g_selectedGear = 2;           //2 being neutral
      return;
    }
    if (!gearUpState && g_selectedGear < 6) {
      g_selectedGear++;
    }
    else if (!gearDownState && g_selectedGear > 1 && g_selectedGear < 7) {
      g_selectedGear--;
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
  float sum = 0;
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

void num2array(short rpm) { // converts rpm to an array of bits to bang into shift registers
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
