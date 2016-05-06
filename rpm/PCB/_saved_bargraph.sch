EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:w_logic
LIBS:ch340-usb-serial-isolated-cache
LIBS:bargraph-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 74HC4094 #U1
U 1 1 572B8CA6
P 5200 3750
F 0 "#U1" H 5350 4250 60  0001 C CNN
F 1 "74HC4094" V 5300 3750 60  0000 C CNN
F 2 "" H 5200 3750 60  0000 C CNN
F 3 "" H 5200 3750 60  0000 C CNN
	1    5200 3750
	1    0    0    -1  
$EndComp
$Comp
L AP1117 U1
U 1 1 572B9139
P 2200 1100
F 0 "U1" H 2300 850 50  0000 C CNN
F 1 "AP1117" H 2200 1350 50  0000 C CNN
F 2 "" H 2200 1100 50  0000 C CNN
F 3 "" H 2200 1100 50  0000 C CNN
	1    2200 1100
	1    0    0    -1  
$EndComp
$Comp
L 74HC4094 #U2
U 1 1 572B961F
P 6800 3750
F 0 "#U2" H 6950 4250 60  0001 C CNN
F 1 "74HC4094" V 6900 3750 60  0000 C CNN
F 2 "" H 6800 3750 60  0000 C CNN
F 3 "" H 6800 3750 60  0000 C CNN
	1    6800 3750
	1    0    0    -1  
$EndComp
$Comp
L 74HC4094 #U3
U 1 1 572B964A
P 8250 3750
F 0 "#U3" H 8400 4250 60  0001 C CNN
F 1 "74HC4094" V 8350 3750 60  0000 C CNN
F 2 "" H 8250 3750 60  0000 C CNN
F 3 "" H 8250 3750 60  0000 C CNN
	1    8250 3750
	1    0    0    -1  
$EndComp
$Comp
L ATMEGA328-P IC1
U 1 1 572B9A8A
P 1550 3150
F 0 "IC1" H 800 4400 50  0000 L BNN
F 1 "ATMEGA328-P" H 1950 1750 50  0000 L BNN
F 2 "DIL28" H 1550 3150 50  0000 C CIN
F 3 "" H 1550 3150 50  0000 C CNN
	1    1550 3150
	1    0    0    -1  
$EndComp
Text Label 2500 1100 0    60   ~ 0
Vcc
Text Label 650  2050 2    60   ~ 0
Vcc
Text Label 650  2350 2    60   ~ 0
Vcc
Text Label 650  2650 2    60   ~ 0
Vcc
Text Label 550  4250 2    60   ~ 0
gnd
Text Label 5200 4300 0    60   ~ 0
gnd
Text Label 6800 4300 0    60   ~ 0
gnd
Text Label 8250 4300 0    60   ~ 0
gnd
Text Label 4900 3200 2    60   ~ 0
Vcc
Text Label 6800 3200 2    60   ~ 0
Vcc
Text Label 8250 3200 2    60   ~ 0
Vcc
Text Label 4800 3800 2    60   ~ 0
Vcc
Text Label 4800 3700 2    60   ~ 0
Vcc
Text Label 6400 3700 2    60   ~ 0
Vcc
Text Label 6400 3800 2    60   ~ 0
Vcc
Text Label 7850 3700 2    60   ~ 0
Vcc
Text Label 7850 3800 2    60   ~ 0
Vcc
$Comp
L DOT-BAR2 bar_green1
U 1 1 572BB828
P 3750 5900
F 0 "bar_green1" H 3650 7350 50  0000 C CNN
F 1 "DOT-BAR2" H 3750 7200 50  0000 C CNN
F 2 "" H 3750 5900 50  0000 C CNN
F 3 "" H 3750 5900 50  0000 C CNN
	1    3750 5900
	0    -1   1    0   
$EndComp
$Comp
L DOT-BAR2 bar_ylw1
U 1 1 572BB97B
P 6750 5900
F 0 "bar_ylw1" H 6650 7350 50  0000 C CNN
F 1 "DOT-BAR2" H 6750 7200 50  0000 C CNN
F 2 "" H 6750 5900 50  0000 C CNN
F 3 "" H 6750 5900 50  0000 C CNN
	1    6750 5900
	0    -1   1    0   
$EndComp
$Comp
L DOT-BAR2 bar_red1
U 1 1 572BB9E4
P 9800 5900
F 0 "bar_red1" H 9700 7350 50  0000 C CNN
F 1 "DOT-BAR2" H 9800 7200 50  0000 C CNN
F 2 "" H 9800 5900 50  0000 C CNN
F 3 "" H 9800 5900 50  0000 C CNN
	1    9800 5900
	0    -1   1    0   
$EndComp
Text Label 2300 6650 0    60   ~ 0
gnd
Entry Wire Line
	7500 3400 7600 3500
Entry Wire Line
	7500 3500 7600 3600
Entry Wire Line
	7500 3600 7600 3700
Entry Wire Line
	7500 3700 7600 3800
Entry Wire Line
	7500 3800 7600 3900
Entry Wire Line
	7500 3900 7600 4000
Entry Wire Line
	7500 4000 7600 4100
Entry Wire Line
	7500 4100 7600 4200
Entry Wire Line
	8950 3400 9050 3500
Entry Wire Line
	8950 3500 9050 3600
Entry Wire Line
	8950 3600 9050 3700
Entry Wire Line
	8950 3700 9050 3800
Entry Wire Line
	8950 3800 9050 3900
Entry Wire Line
	8950 3900 9050 4000
Entry Wire Line
	8950 4000 9050 4100
Entry Wire Line
	8950 4100 9050 4200
NoConn ~ 4800 4100
NoConn ~ 6400 4100
NoConn ~ 7850 4100
NoConn ~ 7850 4000
NoConn ~ 1450 4650
Entry Wire Line
	5900 3400 6000 3500
Entry Wire Line
	5900 3500 6000 3600
Entry Wire Line
	5900 3600 6000 3700
Entry Wire Line
	5900 3700 6000 3800
Entry Wire Line
	5900 3800 6000 3900
Entry Wire Line
	5900 3900 6000 4000
Entry Wire Line
	5900 4000 6000 4100
Entry Wire Line
	5900 4100 6000 4200
Text Label 5650 3400 0    60   ~ 0
U1_0
Text Label 5650 3500 0    60   ~ 0
U1_1
Text Label 5650 3600 0    60   ~ 0
U1_2
Text Label 5650 3700 0    60   ~ 0
U1_3
Text Label 5650 3800 0    60   ~ 0
U1_4
Text Label 5650 3900 0    60   ~ 0
U1_5
Text Label 5650 4000 0    60   ~ 0
U1_6
Text Label 5650 4100 0    60   ~ 0
U1_7
Text Label 7250 3400 0    60   ~ 0
U2_0
Text Label 7250 3600 0    60   ~ 0
U2_2
Text Label 7250 3700 0    60   ~ 0
U2_3
Text Label 7250 3800 0    60   ~ 0
U2_4
Text Label 7250 3900 0    60   ~ 0
U2_5
Text Label 7250 4000 0    60   ~ 0
U2_6
Text Label 7250 4100 0    60   ~ 0
U2_7
Text Label 8700 3400 0    60   ~ 0
U3_0
Text Label 8700 3500 0    60   ~ 0
U3_1
Text Label 8700 3600 0    60   ~ 0
U3_2
Text Label 8700 3700 0    60   ~ 0
U3_3
Text Label 8700 3800 0    60   ~ 0
U3_4
Text Label 8700 3900 0    60   ~ 0
U3_5
Text Label 8700 4000 0    60   ~ 0
U3_6
Text Label 8700 4100 0    60   ~ 0
U3_7
Entry Wire Line
	2550 5050 2650 5150
Entry Wire Line
	2800 5050 2900 5150
Entry Wire Line
	3050 5050 3150 5150
Entry Wire Line
	3300 5050 3400 5150
Entry Wire Line
	3550 5050 3650 5150
Entry Wire Line
	3800 5050 3900 5150
Entry Wire Line
	4050 5050 4150 5150
Entry Wire Line
	4300 5050 4400 5150
Entry Wire Line
	4550 5050 4650 5150
Wire Wire Line
	4800 4000 4600 4000
Wire Wire Line
	4600 4000 4600 4500
Wire Wire Line
	4600 4500 6150 4500
Wire Wire Line
	6150 4500 6150 3400
Wire Wire Line
	6150 3400 6400 3400
Wire Wire Line
	6400 4000 6300 4000
Wire Wire Line
	6300 4000 6300 4500
Wire Wire Line
	6300 4500 7700 4500
Wire Wire Line
	7700 4500 7700 3400
Wire Wire Line
	7700 3400 7850 3400
Wire Wire Line
	7850 3500 7800 3500
Wire Wire Line
	7800 3500 7800 2950
Wire Wire Line
	7800 2950 4600 2950
Wire Wire Line
	6300 2950 6300 3500
Wire Wire Line
	6300 3500 6400 3500
Wire Wire Line
	4600 2950 4600 3500
Wire Wire Line
	4400 3500 4800 3500
Connection ~ 6300 2950
Wire Wire Line
	650  4350 550  4350
Wire Wire Line
	550  4350 550  4250
Wire Wire Line
	550  4250 650  4250
Wire Bus Line
	2500 5050 11100 5050
Wire Wire Line
	2300 6300 2300 6650
Wire Wire Line
	2300 6300 10950 6300
Connection ~ 10700 6300
Connection ~ 10450 6300
Connection ~ 10200 6300
Connection ~ 9950 6300
Connection ~ 9700 6300
Connection ~ 9450 6300
Connection ~ 9200 6300
Connection ~ 8950 6300
Connection ~ 8700 6300
Connection ~ 7900 6300
Connection ~ 7650 6300
Connection ~ 7400 6300
Connection ~ 7150 6300
Connection ~ 6900 6300
Connection ~ 6650 6300
Connection ~ 6400 6300
Connection ~ 6150 6300
Connection ~ 5900 6300
Connection ~ 5650 6300
Connection ~ 4900 6300
Connection ~ 4650 6300
Connection ~ 4400 6300
Connection ~ 4150 6300
Connection ~ 3900 6300
Connection ~ 3650 6300
Connection ~ 3400 6300
Connection ~ 3150 6300
Connection ~ 2900 6300
Connection ~ 2650 6300
Wire Bus Line
	7600 3100 7600 5050
Wire Bus Line
	9050 3100 9050 5050
Wire Bus Line
	6000 3100 6000 5050
Wire Wire Line
	5600 3400 5900 3400
Wire Wire Line
	5600 3500 5900 3500
Wire Wire Line
	5600 3600 5900 3600
Wire Wire Line
	5600 3700 5900 3700
Wire Wire Line
	5600 3800 5900 3800
Wire Wire Line
	5600 3900 5900 3900
Wire Wire Line
	5600 4000 5900 4000
Wire Wire Line
	5600 4100 5900 4100
Wire Wire Line
	7200 3400 7500 3400
Wire Wire Line
	7200 3500 7500 3500
Wire Wire Line
	7200 3600 7500 3600
Wire Wire Line
	7200 3700 7500 3700
Wire Wire Line
	7200 3800 7500 3800
Wire Wire Line
	7200 3900 7500 3900
Wire Wire Line
	7200 4000 7500 4000
Wire Wire Line
	7200 4100 7500 4100
Wire Wire Line
	8650 3400 8950 3400
Wire Wire Line
	8650 3500 8950 3500
Wire Wire Line
	8650 3600 8950 3600
Wire Wire Line
	8650 3700 8950 3700
Wire Wire Line
	8650 3800 8950 3800
Wire Wire Line
	8650 3900 8950 3900
Wire Wire Line
	8650 4000 8950 4000
Wire Wire Line
	8650 4100 8950 4100
Wire Wire Line
	3150 5500 3150 5150
Wire Wire Line
	3400 5500 3400 5150
Wire Wire Line
	2650 5500 2650 5150
Wire Wire Line
	2900 5150 2900 5500
Wire Wire Line
	3650 5500 3650 5150
Wire Wire Line
	3900 5150 3900 5500
Wire Wire Line
	4150 5150 4150 5500
Wire Wire Line
	4400 5150 4400 5500
Wire Wire Line
	4650 5150 4650 5500
Wire Wire Line
	4900 5150 4900 5500
Entry Wire Line
	4800 5050 4900 5150
Entry Wire Line
	5550 5050 5650 5150
Entry Wire Line
	5800 5050 5900 5150
Entry Wire Line
	6050 5050 6150 5150
Entry Wire Line
	6300 5050 6400 5150
Entry Wire Line
	6550 5050 6650 5150
Entry Wire Line
	6800 5050 6900 5150
Entry Wire Line
	7050 5050 7150 5150
Entry Wire Line
	7300 5050 7400 5150
Entry Wire Line
	7550 5050 7650 5150
Wire Wire Line
	6150 5500 6150 5150
Wire Wire Line
	6400 5500 6400 5150
Wire Wire Line
	5650 5500 5650 5150
Wire Wire Line
	5900 5150 5900 5500
Wire Wire Line
	6650 5500 6650 5150
Wire Wire Line
	6900 5150 6900 5500
Wire Wire Line
	7150 5150 7150 5500
Wire Wire Line
	7400 5150 7400 5500
Wire Wire Line
	7650 5150 7650 5500
Wire Wire Line
	7900 5150 7900 5500
Entry Wire Line
	7800 5050 7900 5150
Entry Wire Line
	8600 5050 8700 5150
Entry Wire Line
	8850 5050 8950 5150
Entry Wire Line
	9100 5050 9200 5150
Entry Wire Line
	9350 5050 9450 5150
Wire Wire Line
	9200 5500 9200 5150
Wire Wire Line
	9450 5500 9450 5150
Wire Wire Line
	8700 5500 8700 5150
Wire Wire Line
	8950 5150 8950 5500
Text Label 2650 5400 0    60   ~ 0
U1_0
Text Label 2900 5400 0    60   ~ 0
U1_1
Text Label 3150 5400 0    60   ~ 0
U1_2
Text Label 3400 5400 0    60   ~ 0
U1_3
Text Label 3650 5400 0    60   ~ 0
U1_4
Text Label 3900 5400 0    60   ~ 0
U1_5
Text Label 4150 5400 0    60   ~ 0
U1_6
Text Label 4400 5400 0    60   ~ 0
U1_7
Text Label 4650 5400 0    60   ~ 0
U2_0
Text Label 7250 3500 0    60   ~ 0
U2_1
Text Label 4900 5400 0    60   ~ 0
U2_1
Text Label 5650 5400 0    60   ~ 0
U2_2
Text Label 5900 5400 0    60   ~ 0
U2_3
Text Label 6150 5400 0    60   ~ 0
U2_4
Text Label 6400 5400 0    60   ~ 0
U2_5
Text Label 6650 5400 0    60   ~ 0
U2_6
Text Label 6900 5400 0    60   ~ 0
U2_7
Text Label 7150 5400 0    60   ~ 0
U3_0
Text Label 7400 5400 0    60   ~ 0
U3_1
Text Label 7650 5400 0    60   ~ 0
U3_2
Text Label 7900 5400 0    60   ~ 0
U3_3
Text Label 8700 5400 0    60   ~ 0
U3_4
Text Label 8950 5400 0    60   ~ 0
U3_5
Text Label 9200 5400 0    60   ~ 0
U3_6
Text Label 9450 5400 0    60   ~ 0
U3_7
Wire Wire Line
	2550 3950 4300 3950
Wire Wire Line
	4300 3950 4300 3400
Wire Wire Line
	4300 3400 4800 3400
Wire Wire Line
	2550 4050 4400 4050
Wire Wire Line
	4400 4050 4400 3500
Connection ~ 4600 3500
$Comp
L CH340G U2
U 1 1 572C1E81
P 9300 1300
F 0 "U2" H 9300 800 60  0000 C CNN
F 1 "CH340G" H 9300 1800 60  0000 C CNN
F 2 "" H 9300 1300 60  0000 C CNN
F 3 "" H 9300 1300 60  0000 C CNN
	1    9300 1300
	-1   0    0    -1  
$EndComp
$Comp
L USB_OTG P1
U 1 1 572C1F1F
P 10600 1300
F 0 "P1" H 10925 1175 50  0000 C CNN
F 1 "USB_OTG" H 10600 1500 50  0000 C CNN
F 2 "" V 10550 1200 50  0000 C CNN
F 3 "" V 10550 1200 50  0000 C CNN
	1    10600 1300
	0    1    1    0   
$EndComp
Text Label 10300 1100 2    60   ~ 0
vcc
Text Label 10300 1500 2    60   ~ 0
gnd
Text Label 10700 1700 2    60   ~ 0
gnd
Text Label 9850 950  0    60   ~ 0
gnd
Text Label 9850 1150 0    60   ~ 0
tx
Wire Wire Line
	10100 1450 10100 1200
Wire Wire Line
	10100 1200 10300 1200
Connection ~ 9850 1450
Wire Wire Line
	9850 1450 10100 1450
Wire Wire Line
	9850 1350 10150 1350
Wire Wire Line
	10150 1350 10150 1300
Wire Wire Line
	10150 1300 10300 1300
Text Label 9850 1050 0    60   ~ 0
rx
$Comp
L C C4
U 1 1 572C261A
P 10000 1950
F 0 "C4" H 10025 2050 50  0000 L CNN
F 1 "C" H 10025 1850 50  0000 L CNN
F 2 "" H 10038 1800 50  0000 C CNN
F 3 "" H 10000 1950 50  0000 C CNN
	1    10000 1950
	1    0    0    -1  
$EndComp
Text Label 10000 2100 2    60   ~ 0
gnd
Wire Wire Line
	9850 1250 10000 1250
Wire Wire Line
	10000 1250 10000 1800
$Comp
L Crystal_Small Y1
U 1 1 572C2825
P 9500 2100
F 0 "Y1" H 9500 2200 50  0000 C CNN
F 1 "12MHz" H 9500 2000 50  0000 C CNN
F 2 "" H 9500 2100 50  0000 C CNN
F 3 "" H 9500 2100 50  0000 C CNN
	1    9500 2100
	-1   0    0    1   
$EndComp
Wire Wire Line
	9850 1650 9850 1850
Wire Wire Line
	9850 1850 9300 1850
Wire Wire Line
	9300 1850 9300 2100
Wire Wire Line
	9300 2100 9400 2100
Wire Wire Line
	9850 1550 9900 1550
Wire Wire Line
	9900 1550 9900 2100
Wire Wire Line
	9900 2100 9600 2100
$Comp
L C C2
U 1 1 572C2A13
P 9300 2250
F 0 "C2" H 9325 2350 50  0000 L CNN
F 1 "22pf" H 9325 2150 50  0000 L CNN
F 2 "" H 9338 2100 50  0000 C CNN
F 3 "" H 9300 2250 50  0000 C CNN
	1    9300 2250
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 572C2A87
P 9700 2250
F 0 "C3" H 9725 2350 50  0000 L CNN
F 1 "22pf" H 9725 2150 50  0000 L CNN
F 2 "" H 9738 2100 50  0000 C CNN
F 3 "" H 9700 2250 50  0000 C CNN
	1    9700 2250
	1    0    0    -1  
$EndComp
Text Label 9300 2400 2    60   ~ 0
gnd
Text Label 9700 2400 2    60   ~ 0
gnd
Text Label 8750 950  2    60   ~ 0
vcc
Text Label 8750 1050 2    60   ~ 0
vcc
$Comp
L C C1
U 1 1 572C2D95
P 8200 1100
F 0 "C1" H 8225 1200 50  0000 L CNN
F 1 "100n" H 8225 1000 50  0000 L CNN
F 2 "" H 8238 950 50  0000 C CNN
F 3 "" H 8200 1100 50  0000 C CNN
	1    8200 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 950  8200 950 
Text Label 8200 1250 2    60   ~ 0
gnd
$Comp
L R R?
U 1 1 572C3792
P 2700 3650
F 0 "R?" V 2780 3650 50  0000 C CNN
F 1 "1k" V 2700 3650 50  0000 C CNN
F 2 "" V 2630 3650 50  0000 C CNN
F 3 "" H 2700 3650 50  0000 C CNN
	1    2700 3650
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 572C3809
P 2700 3750
F 0 "R?" V 2780 3750 50  0000 C CNN
F 1 "1k" V 2700 3750 50  0000 C CNN
F 2 "" V 2630 3750 50  0000 C CNN
F 3 "" H 2700 3750 50  0000 C CNN
	1    2700 3750
	0    1    1    0   
$EndComp
Text Label 2850 3650 0    60   ~ 0
rx
Text Label 2850 3750 0    60   ~ 0
tx
Text Label 2200 1400 0    60   ~ 0
gnd
Wire Wire Line
	3200 3850 2550 3850
Wire Wire Line
	3200 2250 3200 3850
Text Label 3200 3700 0    60   ~ 0
sgn
$Comp
L D D?
U 1 1 572C74E6
P 1100 1150
F 0 "D?" H 1100 1250 50  0000 C CNN
F 1 "1n4007" H 1100 1050 50  0000 C CNN
F 2 "" H 1100 1150 50  0000 C CNN
F 3 "" H 1100 1150 50  0000 C CNN
	1    1100 1150
	-1   0    0    1   
$EndComp
$Comp
L ZENER D?
U 1 1 572C7609
P 1700 1300
F 0 "D?" H 1700 1400 50  0000 C CNN
F 1 "ZENER" H 1700 1200 50  0000 C CNN
F 2 "" H 1700 1300 50  0000 C CNN
F 3 "" H 1700 1300 50  0000 C CNN
	1    1700 1300
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 572C7756
P 1400 1150
F 0 "R?" V 1480 1150 50  0000 C CNN
F 1 "R" V 1400 1150 50  0000 C CNN
F 2 "" V 1330 1150 50  0000 C CNN
F 3 "" H 1400 1150 50  0000 C CNN
	1    1400 1150
	0    1    1    0   
$EndComp
Wire Wire Line
	1550 1150 1850 1150
Wire Wire Line
	3200 2250 3600 2250
$Comp
L R R?
U 1 1 572C7BE8
P 3750 2250
F 0 "R?" V 3830 2250 50  0000 C CNN
F 1 "R" V 3750 2250 50  0000 C CNN
F 2 "" V 3680 2250 50  0000 C CNN
F 3 "" H 3750 2250 50  0000 C CNN
	1    3750 2250
	0    1    1    0   
$EndComp
$Comp
L ZENER D?
U 1 1 572C7C85
P 4050 2450
F 0 "D?" H 4050 2550 50  0000 C CNN
F 1 "5.1V" H 4050 2350 50  0000 C CNN
F 2 "" H 4050 2450 50  0000 C CNN
F 3 "" H 4050 2450 50  0000 C CNN
	1    4050 2450
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 572C7D23
P 3500 2400
F 0 "C?" H 3525 2500 50  0000 L CNN
F 1 "C" H 3525 2300 50  0000 L CNN
F 2 "" H 3538 2250 50  0000 C CNN
F 3 "" H 3500 2400 50  0000 C CNN
	1    3500 2400
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 572C80F8
P 9900 3350
F 0 "C?" H 9925 3450 50  0000 L CNN
F 1 "100n" H 9925 3250 50  0000 L CNN
F 2 "" H 9938 3200 50  0000 C CNN
F 3 "" H 9900 3350 50  0000 C CNN
	1    9900 3350
	1    0    0    -1  
$EndComp
Text Label 9900 3500 2    60   ~ 0
gnd
Text Label 9900 3200 2    60   ~ 0
Vcc
$Comp
L C C?
U 1 1 572C8372
P 10300 3350
F 0 "C?" H 10325 3450 50  0000 L CNN
F 1 "100n" H 10325 3250 50  0000 L CNN
F 2 "" H 10338 3200 50  0000 C CNN
F 3 "" H 10300 3350 50  0000 C CNN
	1    10300 3350
	1    0    0    -1  
$EndComp
Text Label 10300 3500 2    60   ~ 0
gnd
Text Label 10300 3200 2    60   ~ 0
Vcc
$Comp
L C C?
U 1 1 572C83DB
P 10700 3350
F 0 "C?" H 10725 3450 50  0000 L CNN
F 1 "100n" H 10725 3250 50  0000 L CNN
F 2 "" H 10738 3200 50  0000 C CNN
F 3 "" H 10700 3350 50  0000 C CNN
	1    10700 3350
	1    0    0    -1  
$EndComp
Text Label 10700 3500 2    60   ~ 0
gnd
Text Label 10700 3200 2    60   ~ 0
Vcc
$Comp
L C C?
U 1 1 572C8432
P 11050 3350
F 0 "C?" H 11075 3450 50  0000 L CNN
F 1 "100n" H 11075 3250 50  0000 L CNN
F 2 "" H 11088 3200 50  0000 C CNN
F 3 "" H 11050 3350 50  0000 C CNN
	1    11050 3350
	1    0    0    -1  
$EndComp
Text Label 11050 3500 2    60   ~ 0
gnd
Text Label 11050 3200 2    60   ~ 0
Vcc
Text Label 3500 2550 0    60   ~ 0
gnd
Connection ~ 3500 2250
Wire Wire Line
	3900 2250 4050 2250
Text Label 4050 2650 0    60   ~ 0
gnd
$EndSCHEMATC
