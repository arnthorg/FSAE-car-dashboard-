#include <avr/wdt.h> // for watchdog timer
#include <EEPROM.h> 
volatile int counter;      // Count number of times ISR is called.
volatile int countmax = 1; // Arbitrarily selected 3 for this example.
                          // Timer expires after about 24 secs if
                          // 8 sec interval is selected below.
volatile short g_counter=0;
void setup()
{  
 Serial.begin(9600);
 
  if(EEPROM.read(0)) { Serial.println("WDT reset"); }
  EEPROM.update(0,0);
}

void loop()
{
 Serial.println("**** starting loop ****");  // should see this approx every xx secs
  Serial.println(EEPROM.read(0));
 watchdogEnable(); // set up watchdog timer in interrupt-only mode

 while (true); // Whoops...in an infinite loop!  For testing only.
               // For production, this would be useful
               // code that normally takes less than xx sec to process
               // but occasionally hangs.

 wdt_disable();

}

void watchdogEnable()
{
 counter=0;
 cli();                              // disable interrupts

 MCUSR = 0;                          // reset status register flags

                                     // Put timer in interrupt-only mode:                                        
 WDTCSR |= 0b00011000;               // Set WDCE (5th from left) and WDE (4th from left) to enter config mode,
                                     // using bitwise OR assignment (leaves other bits unchanged).
 WDTCSR =  0b01000000 | 0b100001;    // set WDIE (interrupt enable...7th from left, on left side of bar)
                                    // clr WDE (reset enable...4th from left)
                                     // and set delay interval (right side of bar) to 8 seconds,
                                     // using bitwise OR operator.

 sei();                              // re-enable interrupts
 wdt_reset();                      // this is not needed...timer starts without it

 // delay interval patterns:
 //  16 ms:     0b000000
 //  500 ms:    0b000101
 //  1 second:  0b000110
 //  2 seconds: 0b000111
 //  4 seconds: 0b100000
 //  8 seconds: 0b100001

}

ISR(WDT_vect) // watchdog timer interrupt service routine
{
  EEPROM.update(0,1);
  delay(3.3);
   asm volatile ("  jmp 0");
 counter+=1;

 if (counter < countmax)
 {
   wdt_reset(); // start timer again (still in interrupt-only mode)
   Serial.println("shit2");
 }
 else             // then change timer to reset-only mode with short (16 ms) fuse
 {
   Serial.println("shi3");
   MCUSR = 0;                          // reset flags

                                       // Put timer in reset-only mode:
   //WDTCSR |= 0b00011000;               // Enter config mode.
   
 }
}
