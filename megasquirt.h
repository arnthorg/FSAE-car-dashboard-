;****************************************************
;
; MegaSquirt.h Include File - V1.9999
;
; (C) Bruce A. Bowling / Al C. Grippo
;
; This header must appear on all derivatives
; of this file.
;****************************************************
; V2.0 Include File For megasquirt.asm
;****************************************************
;*
;* MegaSquirt Hardware Wiring
;*
;****************************************************
;
;
; Inputs [port name - function]
;  Coil - IRQ
;  PTB0/AD0 - MAP
;  PTB1/AD1 - MAT
;  PTB2/AD2 - CLT
;  PTB3/AD3 - TPS
;  PTB4/AD4 - BAT
;
; Outputs
;  PTD4/T1CH0 - Inj1
;  PTD5/T1CH1 - Inj2
;  PTA0 - FP
;  PTA1 - Idle
;  PTC0 - Squirt LED
;  PTC1 - Accel LED
;  PTC2 - Warmup LED



inject1:equ     4
inject2:equ     5
fuelp:  equ     0
iasc:   equ     1
sled:   equ     0
aled    equ     1
wled:   equ     2


;****************************************************
;*
;* MegaSquirt RAM Variables
;*
;* We have plenty of RAM to burn
;****************************************************

; RAM Variables - Ordered List for RS232 realtime download - delivered in one pack
secl:	ds	1	; low seconds - from 0 to 255, then rollover
squirt: ds      1       ; Event variable bit field for Injector Firing
engine: ds      1       ; Variable bit-field to hold engine current status
baro:	ds	1	; Barometer ADC Raw Reading - KPa (0 - 255)
map:	ds	1	; Manifold Absolute Pressure ADC Raw Reading - KPa (0 - 255)
mat:	ds	1	; Manifold Air Temp ADC Raw Reading - counts (0 - 255)
clt:	ds	1	; Coolant Temperature ADC Raw Reading - counts (0 - 255)
tps:	ds	1	; Throttle Position Sensor ADC Raw Reading - counts, represents 0 - 5 volts
batt:	ds	1	; Battery Voltage ADC Raw Reading - counts
ego:    ds      1       ; Exhaust Gas Oxygen ADC Raw Reading - counts
egocorr:ds      1       ; Oxygen Sensor Correction
aircor: ds      1       ; Air Density Correction lookup - percent
warmcor:ds      1       ; Total Warmup Correction - percent
rpm:    ds      1       ; Computed engine RPM - rpm/100
pw:     ds      1       ; injector squirt time in 1/10 millesec (0 to 25.5 millisec) - applied
tpsaccel:ds     1       ; Acceleration enrichment - percent
barocor:ds      1       ; Barometer Lookup Correction - percent
gammae: ds      1       ; Total Gamma Enrichments - percent
vecurr: ds      1       ; Current VE value from lookup table - percent
bspot1: ds      1       ; Blank Spot 1
bspot2: ds      1       ; Blank Spot 2
bspot3: ds      1       ; Blank Spot 3

;-------------------------


; Squirt Event Scheduling Variables - bit fields for "squirt" variable above
inj1:   equ     0       ; 0 = no squirt 1 = squirt
inj2:   equ     1       ; 0 = no squirt 1 = squirt
sched1: equ     2       ; 0 = nothing scheduled 1 = scheduled to squirt
firing1: equ     3       ; 0 = not squirting 1 = squirting
sched2: equ	4
firing2: equ	5


; Calculation Variable
pwcalc  ds      1       ; Computed pulse width - move into variable PW at pulse time
pwrun1  ds      1       ; Pulsewidth timing variable - from 0 to 25.5ms
pwrun2  ds	1
pw2     ds      1       ; the other pw omparison (injector #2)
kpa     ds      1       ; MAP value in units of KPa
coolant ds      1       ; Coolant temperature in Degrees F plus 40 (allows -40 degress to fit in integer)

; Engine Operating/Status variables - bit fields for "engine" variable above
running:equ     0       ; 0 = engine not running 1 = running
crank:  equ     1       ; 0 = engine not cranking 1 = engine cranking
startw: equ     2       ; 0 = not in startup warmup 1 = in warmup enrichment
warmup: equ     3       ; 0 = not in warmup 1 = in warmup
tpsaen: equ     4       ; 0 = not in TPS acceleration mode 1 = TPS acceleration mode
tpsden: equ     5       ; 0 = not in deacceleration mode 1 = in deacceleration mode
mapaen: equ     6       ; 0 = not in MAP acceleration mode 1 = MAP deaceeleration mode

; Engine RPM -> RPM = 12000/(ncyl * (rpmph - rpmpl))
rpmph:   ds      1       ; High part of RPM Period
rpmpl:   ds      1       ; Low part of RPM Period
rpmch:   ds      1       ; Counter for high part of RPM
rpmcl:   ds      1       ; Counter for low part of RPM

old_rpm1: ds     1       ; last rpm value (for odd-fire)

flocker: ds      1       ; Flash locker semaphore

; Previous ADC values for computing derivatives
lmap:	ds	1	; Manifold Absolute Pressure ADC last Reading
lmat:	ds	1	; Manifold Air Temp ADC last Reading
lclt:	ds	1	; Coolant Temperature ADC last Reading
ltps:	ds	1	; Throttle Position Sensor ADC last Reading
lbatt:	ds	1	; Battery Voltage ADC last Reading
lego:   ds      1       ; Last EGO ADC reading

;Global Time Clock
mms:	ds	1	; 0.0001 second update variable
ms:	ds	1	; 0.001  second increment
tenth:  ds      1       ; 1/10th second
sech:	ds	1	; high seconds - rollover at 65536 secs (1110.933 minutes, 18.51 hours)
tpsaclk:ds      1       ; TPS enrichment timer clock in 0.1 second resolution
egocount:ds     1       ; Counter value for EGO step - incremented every ignition pulse
asecount:ds     1       ; Counter value for after-start enrichment counter - every ignition pulse
igncount:ds     1       ; Ignition pulse counter
altcount:ds     1       ; Alternate count selector
tpsaclkcmp:ds   1       ; Comparison value for TPS acceleration time - from lookup table
tpsfuelcut: ds	1	; TPS Fuel Cut (percent)


;SCI parameters/variables
txcnt   ds      1       ; SCI transmitter count (incremented)
txgoal  ds      1       ; SCI number of bytes to transmit
txmode  ds      1       ; Transmit mode flag
rxoffset ds     1       ; offset placeholder when receiving VE/constants vis. SCI

adsel:	ds	1	; ADC Selector Variable
last_tps: ds    1       ; TPS reading updated every 0.1 seconds



;Timer Equates for real-time clock function
Timerstop  equ  %00110010     ;TSC
Timergo    equ  %01010010     ;TSC
T2SC0_No_PWM  equ  %00010000     ;TSC0

; These control Injector PWM mode for T1SC0 and T1SC1
Timergo_NO_INT    equ  %00000010     ;TSC without interrupts
;T1SCX_PWM  equ  %00011010       ; Unbuffered PWM enabled
T1SCX_PWM  equ  %00011110       ; Unbuffered PWM enabled - set high on compare, toggle on overflow

T1SCX_NO_PWM  equ  %00010000    ; No PWM

; Routines for integer math - storage variables
INTACC1	rmb	4
INTACC2	rmb	4
SPVAL	rmb	4

; Temporary variables
tmp1    ds      1
tmp2    ds      1
tmp3    ds      1
tmp4    ds      1
tmp5    ds      1
tmp6    ds      1
tmp7    ds      1
tmp8    ds      1
tmp9    ds      1
tmp10   ds      1
tmp11   ds      1
tmp12   ds      1
tmp13   ds      1
tmp14   ds      1
tmp15   ds      1
tmp16   ds      1
tmp17   ds      1
tmp18   ds      1
tmp19   ds      1


;**************************************************
; Flash Configuration Variables here - variables can be downloaded via serial link
; VETABLE and Constants
; "VE" is entry point, everything is offset from this point
;
VE      rmb     $40     ; 64 bytes for VE Table
CWU     rmb     1       ; Crank Enrichment at -40 F
CWH     rmb     1       ; Crank Enrichment at 170 F
AWEV    rmb     1       ; After-start Warmup Percent enrichment add-on value
AWC     rmb     1       ; After-start number of cycles
WWU     rmb     $0A     ; Warmup bins(fn temp)
TPSAQ   rmb     $04     ; TPS acceleration amount (fn TPSDOT) in 0.1 ms units
tpsacold rmb    1       ; Cold acceleration amount (at -40 degrees) in 0.1 ms units
tpsthresh rmb   1       ; Accel TPS DOT threshold
TPSASYNC   rmb  1       ; ***** TPS Acceleration clock value
TPSDQ   rmb     1       ; Deacceleration fuel cut
egotemp rmb     1       ; Coolant Temperature where EGO is active
egocountcmp rmb 1       ; Counter value where EGO step is to occur
egodelta rmb    1       ; EGO Percent step size for rich/lean
egolimit rmb    1       ; Upper/Lower EGO rail limit (egocorr is inside 100 +/- Limit)
REQ_FUEL rmb    1       ; Fuel COnstant
DIVIDER  rmb    1       ; IRQ divide factor for pulse
Alternate rmb   1       ; Alternate injector drivers
InjOpen rmb     1       ; Injector Open Time
InjOCFuel rmb   1       ; PW-correlated amount of fuel injected during injector open
INJPWM  rmb     1       ; Injector PWM duty cycle at current limit
INJPWMT rmb     1       ; Injector PWM mmillisec time at which to activate.
BATTFAC rmb     1       ; Battery Gamma Factor
rpmk    rmb     2       ; Constant for RPM = 12,000/ncyl - downloaded constant
RPMRANGEVE rmb  8       ; VE table RPM Bins for 2-D interpolation
KPARANGEVE rmb  8       ; VE Table MAP Pressure Bins for 2_D interp.
CONFIG11 rmb    1       ; Configuration for PC Configurator
CONFIG12 rmb    1	; Configuration for PC Configurator
CONFIG13  rmb   1	; Configuration for PC Configurator
PRIMEP rmb      1	; Priming pulses (0.1 millisec units)
RPMOXLIMIT rmb  1	; Minimum RPM where O2 Closed Loop is Active
FASTIDLE  rmb   1       ; Fast Idle Temperature
VOLTOXTARGET rmb 1	; O2 sensor flip target value
ACMULT    rmb   1       ; Acceleration cold multiplication factor (percent/100)
BLANK   rmb     4       ; Extra Slots to make up 64 bytes total


; Placeholder for FLASH programming code
BURNER  rmb     $FF     ; Flash programmer is copied here

; CONFIG11 Bit Definitions (this is used for PC Configurator Only - not used in embedded code)
; CONFIG11:
;  Bit 0-1 = MAP Type
;            00 = MPX4115AP
;            01 = MPX4250AP
;            10 = User-defined
;            11 = User-Defined
;  Bit 2   = Engine Stroke
;            0 = Four Stroke
;            1 = Two Stroke
;  Bit 3   = Injection Type
;            0 = Port Injection
;            1 = Throttle Body
;  Bit 4-7 = Number of Cylinders
;            0000 = 1 cylinder
;            0001 = 2 cylinders
;            0010 = 3 cylinders
;            0011 = 4 cylinders
;            0100 = 5 cylinder
;            0101 = 6 cylinders
;            0110 = 7 cylinders
;            0111 = 8 cylinders
;            1000 = 9 cylinders
;            1001 = 10 cylinders
;            1010 = 11 cylinders
;            1011 = 12 cylinders

; CONFIG12 Bit Definitions (this is used for PC Configurator Only - not used in embedded code)
; CONFIG12:
;  Bit 0-1 = COOL Sensor Type
;            00 = GM
;            01 = User-defined
;            10 = User-defined
;            11 = User-Defined
;  Bit 2-3 = MAT Sensor Type
;            00 = GM
;            01 = Undefined
;            10 = Undefined
;            11 = Undefined
;  Bit 4-7 = Number of Injectors
;            0000 = 1 Injector
;            0001 = 2 Injectors
;            0010 = 3 Injectors
;            0011 = 4 Injectors
;            0100 = 5 Injectors
;            0101 = 6 Injectors
;            0110 = 7 Injectors
;            0111 = 8 Injectors
;            1000 = 9 Injectors
;            1001 = 10 Injectors
;            1010 = 11 Injectors
;            1011 = 12 Injectors
;
; CONFIG13 Bit Definitions
; CONFIG13:
;  Bit 0   = Odd-fire averaging
;            0 = Normal
;            1 = Odd-Fire
;  Bit 1   = O2 Sensor Type
;            0 = Narrow-band (single wire 14.7 stoch)
;            1 = DIY-WB (Stoch = 2.5V, reverse slope)
;  Bit 2   = Control Stategy
;            0 = Speed-Density
;            1 = Alpha-N
;  Bit 3   = Barometer Correction
;            0 = Enrichment Off (set to 100%)
;            1 = Enrichment On



