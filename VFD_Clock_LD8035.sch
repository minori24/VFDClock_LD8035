EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:vfd-watch-cache
LIBS:arduino
LIBS:switches
LIBS:MiscComponents
LIBS:VFD_Clock_LD8035-cache
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
L ld8035e V1
U 1 1 5AC35A05
P 8600 1300
F 0 "V1" H 9400 1175 60  0000 C CNN
F 1 "ld8035e" H 9225 1375 60  0000 C CNN
F 2 "VFD:LD8035E" H 8600 1350 60  0001 C CNN
F 3 "" H 8600 1350 60  0000 C CNN
	1    8600 1300
	1    0    0    1   
$EndComp
$Comp
L ld8035e V2
U 1 1 5AC35A81
P 8600 2500
F 0 "V2" H 9400 2375 60  0000 C CNN
F 1 "ld8035e" H 9225 2575 60  0000 C CNN
F 2 "VFD:LD8035E" H 8600 2550 60  0001 C CNN
F 3 "" H 8600 2550 60  0000 C CNN
	1    8600 2500
	1    0    0    1   
$EndComp
$Comp
L ld8035e V3
U 1 1 5AC35DA5
P 8600 3700
F 0 "V3" H 9400 3575 60  0000 C CNN
F 1 "ld8035e" H 9225 3775 60  0000 C CNN
F 2 "VFD:LD8035E" H 8600 3750 60  0001 C CNN
F 3 "" H 8600 3750 60  0000 C CNN
	1    8600 3700
	1    0    0    1   
$EndComp
$Comp
L ld8035e V4
U 1 1 5AC35DEE
P 8600 4950
F 0 "V4" H 9400 4825 60  0000 C CNN
F 1 "ld8035e" H 9225 5025 60  0000 C CNN
F 2 "VFD:LD8035E" H 8600 5000 60  0001 C CNN
F 3 "" H 8600 5000 60  0000 C CNN
	1    8600 4950
	1    0    0    1   
$EndComp
$Comp
L ld8035e V5
U 1 1 5AC36008
P 10450 1300
F 0 "V5" H 11250 1175 60  0000 C CNN
F 1 "ld8035e" H 11075 1375 60  0000 C CNN
F 2 "VFD:LD8035E" H 10450 1350 60  0001 C CNN
F 3 "" H 10450 1350 60  0000 C CNN
	1    10450 1300
	1    0    0    1   
$EndComp
$Comp
L ld8035e V6
U 1 1 5AC3600E
P 10450 2500
F 0 "V6" H 11250 2375 60  0000 C CNN
F 1 "ld8035e" H 11075 2575 60  0000 C CNN
F 2 "VFD:LD8035E" H 10450 2550 60  0001 C CNN
F 3 "" H 10450 2550 60  0000 C CNN
	1    10450 2500
	1    0    0    1   
$EndComp
$Comp
L ARDUINO_NANO ARDUINO1
U 1 1 5AC360CA
P 3600 4050
F 0 "ARDUINO1" H 3600 4900 70  0000 C CNN
F 1 "ARDUINO_NANO" V 3600 4050 70  0000 C CNN
F 2 "Modules:Arduino_Nano" H 3600 4050 60  0001 C CNN
F 3 "" H 3600 4050 60  0000 C CNN
	1    3600 4050
	1    0    0    -1  
$EndComp
$Comp
L TD62783 U2
U 1 1 5AC3624E
P 6000 1650
F 0 "U2" H 6000 1100 50  0000 C CNN
F 1 "TD62783" H 6000 2200 50  0000 C CNN
F 2 "Housings_DIP:DIP-18_W7.62mm_LongPads" H 6000 1650 60  0001 C CNN
F 3 "" H 6000 1650 60  0000 C CNN
	1    6000 1650
	1    0    0    -1  
$EndComp
$Comp
L TD62783 U3
U 1 1 5AC36303
P 6000 2950
F 0 "U3" H 6000 2400 50  0000 C CNN
F 1 "TD62783" H 6000 3500 50  0000 C CNN
F 2 "Housings_DIP:DIP-18_W7.62mm_LongPads" H 6000 2950 60  0001 C CNN
F 3 "" H 6000 2950 60  0000 C CNN
	1    6000 2950
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW1
U 1 1 5AC37212
P 1200 5550
F 0 "SW1" H 1250 5650 50  0000 L CNN
F 1 "SW_Push" H 1200 5490 50  0000 C CNN
F 2 "Buttons_Switches_THT:SW_PUSH_6mm_h4.3mm" H 1200 5750 50  0001 C CNN
F 3 "" H 1200 5750 50  0001 C CNN
	1    1200 5550
	0    -1   -1   0   
$EndComp
$Comp
L SW_Push SW2
U 1 1 5AC372B9
P 1600 5550
F 0 "SW2" H 1650 5650 50  0000 L CNN
F 1 "SW_Push" H 1600 5490 50  0000 C CNN
F 2 "Buttons_Switches_THT:SW_PUSH_6mm_h4.3mm" H 1600 5750 50  0001 C CNN
F 3 "" H 1600 5750 50  0001 C CNN
	1    1600 5550
	0    -1   -1   0   
$EndComp
$Comp
L R R1
U 1 1 5AC381BD
P 8850 800
F 0 "R1" V 8930 800 50  0000 C CNN
F 1 "R" V 8850 800 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P5.08mm_Vertical" V 8780 800 50  0001 C CNN
F 3 "" H 8850 800 50  0001 C CNN
	1    8850 800 
	0    -1   -1   0   
$EndComp
$Comp
L R R2
U 1 1 5AC38DB5
P 8850 2000
F 0 "R2" V 8930 2000 50  0000 C CNN
F 1 "R" V 8850 2000 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P5.08mm_Vertical" V 8780 2000 50  0001 C CNN
F 3 "" H 8850 2000 50  0001 C CNN
	1    8850 2000
	0    -1   -1   0   
$EndComp
$Comp
L R R3
U 1 1 5AC38E2B
P 8850 3200
F 0 "R3" V 8930 3200 50  0000 C CNN
F 1 "R" V 8850 3200 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P5.08mm_Vertical" V 8780 3200 50  0001 C CNN
F 3 "" H 8850 3200 50  0001 C CNN
	1    8850 3200
	0    -1   -1   0   
$EndComp
$Comp
L R R4
U 1 1 5AC3932E
P 8850 4450
F 0 "R4" V 8930 4450 50  0000 C CNN
F 1 "R" V 8850 4450 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P5.08mm_Vertical" V 8780 4450 50  0001 C CNN
F 3 "" H 8850 4450 50  0001 C CNN
	1    8850 4450
	0    -1   -1   0   
$EndComp
$Comp
L R R5
U 1 1 5AC393AE
P 10700 800
F 0 "R5" V 10780 800 50  0000 C CNN
F 1 "R" V 10700 800 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P5.08mm_Vertical" V 10630 800 50  0001 C CNN
F 3 "" H 10700 800 50  0001 C CNN
	1    10700 800 
	0    -1   1    0   
$EndComp
$Comp
L R R6
U 1 1 5AC397A4
P 10700 2000
F 0 "R6" V 10780 2000 50  0000 C CNN
F 1 "R" V 10700 2000 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P5.08mm_Vertical" V 10630 2000 50  0001 C CNN
F 3 "" H 10700 2000 50  0001 C CNN
	1    10700 2000
	0    -1   1    0   
$EndComp
$Comp
L CONN_01X05 J3
U 1 1 5AC3CB54
P 3800 6950
F 0 "J3" H 3800 7250 50  0000 C CNN
F 1 "CONN_01X05" V 3900 6950 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05_Pitch2.54mm" H 3800 6950 50  0001 C CNN
F 3 "" H 3800 6950 50  0001 C CNN
	1    3800 6950
	1    0    0    -1  
$EndComp
Text Notes 3550 6500 0    60   ~ 0
RTC Header
Wire Wire Line
	5300 1250 5600 1250
Wire Wire Line
	5600 1350 5300 1350
Wire Wire Line
	5300 1450 5600 1450
Wire Wire Line
	5600 1550 5300 1550
Wire Wire Line
	5300 1650 5600 1650
Wire Wire Line
	5600 1750 5300 1750
Wire Bus Line
	7700 2000 7700 5750
Wire Bus Line
	7700 5750 9700 5750
Wire Bus Line
	9700 5750 9700 2000
Entry Wire Line
	6500 2650 6600 2750
Entry Wire Line
	6500 2550 6600 2650
Entry Wire Line
	6500 2850 6600 2950
Entry Wire Line
	6500 2750 6600 2850
Wire Wire Line
	6500 2550 6400 2550
Wire Wire Line
	6400 2650 6500 2650
Wire Wire Line
	6500 2750 6400 2750
Wire Wire Line
	6400 2850 6500 2850
Entry Wire Line
	6500 3050 6600 3150
Entry Wire Line
	6500 2950 6600 3050
Wire Wire Line
	6500 2950 6400 2950
Wire Wire Line
	6400 3050 6500 3050
Wire Wire Line
	6500 3150 6400 3150
Entry Bus Bus
	7600 3350 7700 3450
Wire Bus Line
	6600 3350 7600 3350
Wire Bus Line
	6600 1950 6600 3350
Entry Wire Line
	8450 1800 8350 1900
Entry Wire Line
	8400 1800 8300 1900
Entry Wire Line
	8550 1800 8450 1900
Entry Wire Line
	8500 1800 8400 1900
Entry Wire Line
	8650 1800 8550 1900
Entry Wire Line
	8600 1800 8500 1900
Entry Wire Line
	8750 1800 8650 1900
Entry Wire Line
	8700 1800 8600 1900
Entry Wire Line
	8800 1800 8700 1900
Wire Bus Line
	7800 1900 8750 1900
Entry Bus Bus
	7800 1900 7700 2000
Wire Wire Line
	8800 1750 8800 1800
Wire Wire Line
	8750 1750 8750 1800
Wire Wire Line
	8700 1750 8700 1800
Wire Wire Line
	8650 1750 8650 1800
Wire Wire Line
	8600 1750 8600 1800
Wire Wire Line
	8550 1750 8550 1800
Wire Wire Line
	8500 1750 8500 1800
Wire Wire Line
	8450 1750 8450 1800
Wire Wire Line
	8400 1750 8400 1800
Text Label 8400 1800 0    60   ~ 0
a
Text Label 8450 1800 0    60   ~ 0
b
Text Label 8500 1800 0    60   ~ 0
c
Text Label 8550 1800 0    60   ~ 0
d
Text Label 8600 1800 0    60   ~ 0
e
Text Label 8650 1800 0    60   ~ 0
f
Text Label 8700 1800 0    60   ~ 0
g
Text Label 8750 1800 0    60   ~ 0
h
Entry Wire Line
	8450 3000 8350 3100
Entry Wire Line
	8400 3000 8300 3100
Entry Wire Line
	8550 3000 8450 3100
Entry Wire Line
	8500 3000 8400 3100
Entry Wire Line
	8650 3000 8550 3100
Entry Wire Line
	8600 3000 8500 3100
Entry Wire Line
	8750 3000 8650 3100
Entry Wire Line
	8700 3000 8600 3100
Entry Wire Line
	8800 3000 8700 3100
Wire Bus Line
	7800 3100 8700 3100
Entry Bus Bus
	7800 3100 7700 3200
Wire Wire Line
	8800 2950 8800 3000
Wire Wire Line
	8750 2950 8750 3000
Wire Wire Line
	8700 2950 8700 3000
Wire Wire Line
	8650 2950 8650 3000
Wire Wire Line
	8600 2950 8600 3000
Wire Wire Line
	8550 2950 8550 3000
Wire Wire Line
	8500 2950 8500 3000
Wire Wire Line
	8450 2950 8450 3000
Wire Wire Line
	8400 2950 8400 3000
Text Label 8400 3000 0    60   ~ 0
a
Text Label 8450 3000 0    60   ~ 0
b
Text Label 8500 3000 0    60   ~ 0
c
Text Label 8550 3000 0    60   ~ 0
d
Text Label 8600 3000 0    60   ~ 0
e
Text Label 8650 3000 0    60   ~ 0
f
Text Label 8700 3000 0    60   ~ 0
g
Text Label 8750 3000 0    60   ~ 0
h
Text Label 8800 3000 0    60   ~ 0
dp
Entry Wire Line
	8450 4200 8350 4300
Entry Wire Line
	8400 4200 8300 4300
Entry Wire Line
	8550 4200 8450 4300
Entry Wire Line
	8500 4200 8400 4300
Entry Wire Line
	8650 4200 8550 4300
Entry Wire Line
	8600 4200 8500 4300
Entry Wire Line
	8750 4200 8650 4300
Entry Wire Line
	8700 4200 8600 4300
Entry Wire Line
	8800 4200 8700 4300
Wire Bus Line
	7800 4300 8700 4300
Entry Bus Bus
	7800 4300 7700 4400
Wire Wire Line
	8800 4150 8800 4200
Wire Wire Line
	8750 4150 8750 4200
Wire Wire Line
	8700 4150 8700 4200
Wire Wire Line
	8650 4150 8650 4200
Wire Wire Line
	8600 4150 8600 4200
Wire Wire Line
	8550 4150 8550 4200
Wire Wire Line
	8500 4150 8500 4200
Wire Wire Line
	8450 4150 8450 4200
Wire Wire Line
	8400 4150 8400 4200
Text Label 8400 4200 0    60   ~ 0
a
Text Label 8450 4200 0    60   ~ 0
b
Text Label 8500 4200 0    60   ~ 0
c
Text Label 8550 4200 0    60   ~ 0
d
Text Label 8600 4200 0    60   ~ 0
e
Text Label 8650 4200 0    60   ~ 0
f
Text Label 8700 4200 0    60   ~ 0
g
Text Label 8750 4200 0    60   ~ 0
h
Text Label 8800 4200 0    60   ~ 0
dp
Entry Wire Line
	8450 5450 8350 5550
Entry Wire Line
	8400 5450 8300 5550
Entry Wire Line
	8550 5450 8450 5550
Entry Wire Line
	8500 5450 8400 5550
Entry Wire Line
	8650 5450 8550 5550
Entry Wire Line
	8600 5450 8500 5550
Entry Wire Line
	8750 5450 8650 5550
Entry Wire Line
	8700 5450 8600 5550
Entry Wire Line
	8800 5450 8700 5550
Wire Bus Line
	7800 5550 8700 5550
Entry Bus Bus
	7800 5550 7700 5650
Wire Wire Line
	8800 5400 8800 5450
Wire Wire Line
	8750 5400 8750 5450
Wire Wire Line
	8700 5400 8700 5450
Wire Wire Line
	8650 5400 8650 5450
Wire Wire Line
	8600 5400 8600 5450
Wire Wire Line
	8550 5400 8550 5450
Wire Wire Line
	8500 5400 8500 5450
Wire Wire Line
	8450 5400 8450 5450
Wire Wire Line
	8400 5400 8400 5450
Text Label 8400 5450 0    60   ~ 0
a
Text Label 8450 5450 0    60   ~ 0
b
Text Label 8500 5450 0    60   ~ 0
c
Text Label 8550 5450 0    60   ~ 0
d
Text Label 8600 5450 0    60   ~ 0
e
Text Label 8650 5450 0    60   ~ 0
f
Text Label 8700 5450 0    60   ~ 0
g
Text Label 8750 5450 0    60   ~ 0
h
Text Label 8800 5450 0    60   ~ 0
dp
Entry Wire Line
	10300 1800 10200 1900
Entry Wire Line
	10250 1800 10150 1900
Entry Wire Line
	10400 1800 10300 1900
Entry Wire Line
	10350 1800 10250 1900
Entry Wire Line
	10500 1800 10400 1900
Entry Wire Line
	10450 1800 10350 1900
Entry Wire Line
	10600 1800 10500 1900
Entry Wire Line
	10550 1800 10450 1900
Entry Wire Line
	10650 1800 10550 1900
Wire Wire Line
	10650 1750 10650 1800
Wire Wire Line
	10600 1750 10600 1800
Wire Wire Line
	10550 1750 10550 1800
Wire Wire Line
	10500 1750 10500 1800
Wire Wire Line
	10450 1750 10450 1800
Wire Wire Line
	10400 1750 10400 1800
Wire Wire Line
	10350 1750 10350 1800
Wire Wire Line
	10300 1750 10300 1800
Wire Wire Line
	10250 1750 10250 1800
Text Label 10250 1800 0    60   ~ 0
a
Text Label 10300 1800 0    60   ~ 0
b
Text Label 10350 1800 0    60   ~ 0
c
Text Label 10400 1800 0    60   ~ 0
d
Text Label 10450 1800 0    60   ~ 0
e
Text Label 10500 1800 0    60   ~ 0
f
Text Label 10550 1800 0    60   ~ 0
g
Text Label 10600 1800 0    60   ~ 0
h
Text Label 10650 1800 0    60   ~ 0
dp
Wire Bus Line
	9800 1900 10550 1900
Entry Bus Bus
	9800 1900 9700 2000
Entry Wire Line
	10300 3000 10200 3100
Entry Wire Line
	10250 3000 10150 3100
Entry Wire Line
	10400 3000 10300 3100
Entry Wire Line
	10350 3000 10250 3100
Entry Wire Line
	10500 3000 10400 3100
Entry Wire Line
	10450 3000 10350 3100
Entry Wire Line
	10600 3000 10500 3100
Entry Wire Line
	10550 3000 10450 3100
Entry Wire Line
	10650 3000 10550 3100
Wire Wire Line
	10650 2950 10650 3000
Wire Wire Line
	10600 2950 10600 3000
Wire Wire Line
	10550 2950 10550 3000
Wire Wire Line
	10500 2950 10500 3000
Wire Wire Line
	10450 2950 10450 3000
Wire Wire Line
	10400 2950 10400 3000
Wire Wire Line
	10350 2950 10350 3000
Wire Wire Line
	10300 2950 10300 3000
Wire Wire Line
	10250 2950 10250 3000
Text Label 10250 3000 0    60   ~ 0
a
Text Label 10300 3000 0    60   ~ 0
b
Text Label 10350 3000 0    60   ~ 0
c
Text Label 10400 3000 0    60   ~ 0
d
Text Label 10450 3000 0    60   ~ 0
e
Text Label 10500 3000 0    60   ~ 0
f
Text Label 10550 3000 0    60   ~ 0
g
Text Label 10600 3000 0    60   ~ 0
h
Text Label 10650 3000 0    60   ~ 0
dp
Wire Bus Line
	9800 3100 10550 3100
Entry Bus Bus
	9800 3100 9700 3200
Wire Wire Line
	8500 850  8500 800 
Wire Wire Line
	8500 800  8700 800 
Wire Wire Line
	8500 2050 8500 2000
Wire Wire Line
	8500 2000 8700 2000
Wire Wire Line
	8500 3250 8500 3200
Wire Wire Line
	8500 3200 8700 3200
Wire Wire Line
	8500 4500 8500 4450
Wire Wire Line
	8500 4450 8700 4450
Wire Wire Line
	10350 850  10350 800 
Wire Wire Line
	10350 2050 10350 2000
Wire Wire Line
	10350 2000 10550 2000
$Comp
L GND #PWR01
U 1 1 5AC3B76B
P 9050 5400
F 0 "#PWR01" H 9050 5150 50  0001 C CNN
F 1 "GND" H 9050 5250 50  0000 C CNN
F 2 "" H 9050 5400 50  0001 C CNN
F 3 "" H 9050 5400 50  0001 C CNN
	1    9050 5400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 5AC3B8B8
P 9050 4150
F 0 "#PWR02" H 9050 3900 50  0001 C CNN
F 1 "GND" H 9050 4000 50  0000 C CNN
F 2 "" H 9050 4150 50  0001 C CNN
F 3 "" H 9050 4150 50  0001 C CNN
	1    9050 4150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 5AC3B9B4
P 9050 2950
F 0 "#PWR03" H 9050 2700 50  0001 C CNN
F 1 "GND" H 9050 2800 50  0000 C CNN
F 2 "" H 9050 2950 50  0001 C CNN
F 3 "" H 9050 2950 50  0001 C CNN
	1    9050 2950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 5AC3B9FE
P 9100 1750
F 0 "#PWR04" H 9100 1500 50  0001 C CNN
F 1 "GND" H 9100 1600 50  0000 C CNN
F 2 "" H 9100 1750 50  0001 C CNN
F 3 "" H 9100 1750 50  0001 C CNN
	1    9100 1750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 5AC3BA48
P 10950 1750
F 0 "#PWR05" H 10950 1500 50  0001 C CNN
F 1 "GND" H 10950 1600 50  0000 C CNN
F 2 "" H 10950 1750 50  0001 C CNN
F 3 "" H 10950 1750 50  0001 C CNN
	1    10950 1750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 5AC3BA92
P 10950 2950
F 0 "#PWR06" H 10950 2700 50  0001 C CNN
F 1 "GND" H 10950 2800 50  0000 C CNN
F 2 "" H 10950 2950 50  0001 C CNN
F 3 "" H 10950 2950 50  0001 C CNN
	1    10950 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	9000 1150 9100 1150
Wire Wire Line
	9100 1150 9100 1750
Wire Wire Line
	10850 1150 10950 1150
Wire Wire Line
	10950 1150 10950 1750
Wire Wire Line
	10850 2350 10950 2350
Wire Wire Line
	10950 2350 10950 2950
Wire Wire Line
	9000 3550 9050 3550
Wire Wire Line
	9050 3550 9050 4150
Wire Wire Line
	9000 4800 9050 4800
Wire Wire Line
	9050 4800 9050 5400
Wire Wire Line
	9000 2350 9050 2350
Wire Wire Line
	9050 2350 9050 2950
Wire Wire Line
	9000 2000 9300 2000
Wire Wire Line
	9300 2000 9300 1950
Wire Wire Line
	9000 3200 9300 3200
Wire Wire Line
	9300 3200 9300 3150
Wire Wire Line
	9000 4450 9300 4450
Wire Wire Line
	9300 4450 9300 4400
Wire Wire Line
	10350 800  10550 800 
Wire Wire Line
	9000 800  9300 800 
Wire Wire Line
	9300 800  9300 650 
Wire Wire Line
	11050 650  11050 800 
Wire Wire Line
	11050 800  10850 800 
Wire Wire Line
	10850 2000 11100 2000
Wire Wire Line
	11100 2000 11100 1950
Entry Wire Line
	6500 1950 6600 2050
Entry Wire Line
	6500 1850 6600 1950
Wire Wire Line
	6500 1850 6400 1850
Wire Wire Line
	6500 1950 6400 1950
Text Label 6450 1850 0    60   ~ 0
a
Text Label 6450 1950 0    60   ~ 0
b
Text Label 6450 2550 0    60   ~ 0
c
Text Label 6450 2650 0    60   ~ 0
d
Text Label 6450 2750 0    60   ~ 0
e
Text Label 6450 2850 0    60   ~ 0
f
Text Label 6450 2950 0    60   ~ 0
g
Text Label 6450 3050 0    60   ~ 0
h
Text Label 6450 3150 0    60   ~ 0
dp
Wire Wire Line
	6400 1250 6550 1250
Wire Wire Line
	6400 1350 6550 1350
Wire Wire Line
	6400 1450 6550 1450
Wire Wire Line
	6400 1550 6550 1550
Wire Wire Line
	6400 1650 6550 1650
Wire Wire Line
	6400 1750 6550 1750
Text Label 6550 1250 0    60   ~ 0
DIGIT_0
Text Label 6550 1350 0    60   ~ 0
DIGIT_1
Text Label 6550 1450 0    60   ~ 0
DIGIT_2
Text Label 6550 1550 0    60   ~ 0
DIGIT_3
Text Label 6550 1650 0    60   ~ 0
DIGIT_4
Text Label 6550 1750 0    60   ~ 0
DIGIT_5
Wire Wire Line
	5350 1850 5600 1850
Wire Wire Line
	5350 1950 5600 1950
Wire Wire Line
	5350 2550 5600 2550
Wire Wire Line
	5350 2650 5600 2650
Wire Wire Line
	5350 2750 5600 2750
Wire Wire Line
	5350 2850 5600 2850
Wire Wire Line
	5350 2950 5600 2950
Wire Wire Line
	5350 3050 5600 3050
Wire Wire Line
	5350 3150 5600 3150
Text Label 5350 1850 0    60   ~ 0
SEG_A
Text Label 5350 1950 0    60   ~ 0
SEG_B
Text Label 5350 2550 0    60   ~ 0
SEG_C
Text Label 5350 2650 0    60   ~ 0
SEG_D
Text Label 5350 2750 0    60   ~ 0
SEG_E
Text Label 5350 2850 0    60   ~ 0
SEG_F
Text Label 5350 2950 0    60   ~ 0
SEG_G
Text Label 5350 3050 0    60   ~ 0
SEG_H
Text Label 5350 3150 0    60   ~ 0
SEG_DP
Wire Wire Line
	3000 3700 2550 3700
Text Label 2550 3700 0    60   ~ 0
SER
Wire Wire Line
	3000 3800 2550 3800
Text Label 2550 3800 0    60   ~ 0
SRCLK
Wire Wire Line
	3000 3900 2550 3900
Text Label 2550 3900 0    60   ~ 0
SRCLR
Wire Wire Line
	3000 4000 2550 4000
Text Label 2550 4000 0    60   ~ 0
RCLK
Wire Wire Line
	3900 1250 3250 1250
Text Label 3250 1250 0    60   ~ 0
SER
Wire Wire Line
	3900 1450 3250 1450
Text Label 3250 1450 0    60   ~ 0
SRCLK
Wire Wire Line
	3900 1550 3250 1550
Text Label 3250 1550 0    60   ~ 0
SRCLR
Wire Wire Line
	3900 1750 3250 1750
Text Label 3250 1750 0    60   ~ 0
RCLK
Wire Wire Line
	3000 4100 2550 4100
Text Label 2550 4100 0    60   ~ 0
SEG_A
Wire Wire Line
	3000 4200 2550 4200
Text Label 2550 4200 0    60   ~ 0
SEG_B
Wire Wire Line
	3000 4300 2550 4300
Text Label 2550 4300 0    60   ~ 0
SEG_C
Wire Wire Line
	3000 4400 2550 4400
Text Label 2550 4400 0    60   ~ 0
SEG_D
Wire Wire Line
	3000 4500 2550 4500
Text Label 2550 4500 0    60   ~ 0
SEG_E
Wire Wire Line
	3000 4600 2550 4600
Text Label 2550 4600 0    60   ~ 0
SEG_F
Wire Wire Line
	3000 4700 2550 4700
Text Label 2550 4700 0    60   ~ 0
SEG_G
Text Label 4550 4400 0    60   ~ 0
SEG_H
Wire Wire Line
	4200 4400 4550 4400
Text Label 4550 4300 0    60   ~ 0
SEG_DP
Wire Wire Line
	4200 4300 4550 4300
Text Label 4550 4000 0    60   ~ 0
SDA
Wire Wire Line
	4200 4000 4550 4000
Text Label 4550 3900 0    60   ~ 0
SCL
Wire Wire Line
	4200 3900 4550 3900
Text Label 4550 4200 0    60   ~ 0
SW_A
Text Label 4550 4100 0    60   ~ 0
SW_B
$Comp
L GND #PWR013
U 1 1 5AC40D91
P 4450 5100
F 0 "#PWR013" H 4450 4850 50  0001 C CNN
F 1 "GND" H 4450 4950 50  0000 C CNN
F 2 "" H 4450 5100 50  0001 C CNN
F 3 "" H 4450 5100 50  0001 C CNN
	1    4450 5100
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR014
U 1 1 5AC40DC8
P 4350 3100
F 0 "#PWR014" H 4350 2950 50  0001 C CNN
F 1 "+5V" H 4350 3240 50  0000 C CNN
F 2 "" H 4350 3100 50  0001 C CNN
F 3 "" H 4350 3100 50  0001 C CNN
	1    4350 3100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 5AC40E19
P 2850 5100
F 0 "#PWR015" H 2850 4850 50  0001 C CNN
F 1 "GND" H 2850 4950 50  0000 C CNN
F 2 "" H 2850 5100 50  0001 C CNN
F 3 "" H 2850 5100 50  0001 C CNN
	1    2850 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 3600 2850 3600
Wire Wire Line
	2850 3600 2850 5100
Wire Wire Line
	4450 3400 4450 5100
Wire Wire Line
	4200 3400 4450 3400
Wire Wire Line
	4200 3600 4350 3600
Wire Wire Line
	4350 3600 4350 3100
$Comp
L GND #PWR016
U 1 1 5AC41481
P 1600 5950
F 0 "#PWR016" H 1600 5700 50  0001 C CNN
F 1 "GND" H 1600 5800 50  0000 C CNN
F 2 "" H 1600 5950 50  0001 C CNN
F 3 "" H 1600 5950 50  0001 C CNN
	1    1600 5950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR017
U 1 1 5AC414CB
P 1200 5950
F 0 "#PWR017" H 1200 5700 50  0001 C CNN
F 1 "GND" H 1200 5800 50  0000 C CNN
F 2 "" H 1200 5950 50  0001 C CNN
F 3 "" H 1200 5950 50  0001 C CNN
	1    1200 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 5750 1600 5950
Wire Wire Line
	1200 5750 1200 5950
Wire Wire Line
	1200 5350 1200 5150
Wire Wire Line
	1600 5350 1600 5150
Text Label 1200 5150 0    60   ~ 0
SW_A
Text Label 1600 5150 0    60   ~ 0
SW_B
$Comp
L GND #PWR018
U 1 1 5AC419D7
P 3450 7300
F 0 "#PWR018" H 3450 7050 50  0001 C CNN
F 1 "GND" H 3450 7150 50  0000 C CNN
F 2 "" H 3450 7300 50  0001 C CNN
F 3 "" H 3450 7300 50  0001 C CNN
	1    3450 7300
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR019
U 1 1 5AC41F8D
P 3800 700
F 0 "#PWR019" H 3800 550 50  0001 C CNN
F 1 "+5V" H 3800 840 50  0000 C CNN
F 2 "" H 3800 700 50  0001 C CNN
F 3 "" H 3800 700 50  0001 C CNN
	1    3800 700 
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR020
U 1 1 5AC42D74
P 3450 6600
F 0 "#PWR020" H 3450 6450 50  0001 C CNN
F 1 "+5V" H 3450 6740 50  0000 C CNN
F 2 "" H 3450 6600 50  0001 C CNN
F 3 "" H 3450 6600 50  0001 C CNN
	1    3450 6600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 6750 3200 6750
Wire Wire Line
	3600 6850 3200 6850
Wire Wire Line
	3600 6950 3200 6950
Wire Wire Line
	3600 7050 3450 7050
Wire Wire Line
	3450 7050 3450 6600
Wire Wire Line
	3600 7150 3450 7150
Wire Wire Line
	3450 7150 3450 7300
Text Label 3200 6750 0    60   ~ 0
DS
Text Label 3200 6850 0    60   ~ 0
SCL
Text Label 3200 6950 0    60   ~ 0
SDA
Wire Wire Line
	7800 1400 8150 1400
Text Label 7800 1400 0    60   ~ 0
DIGIT_0
Wire Wire Line
	7800 2600 8150 2600
Text Label 7800 2600 0    60   ~ 0
DIGIT_1
Wire Wire Line
	7800 3800 8150 3800
Text Label 7800 3800 0    60   ~ 0
DIGIT_2
Wire Wire Line
	7800 5050 8150 5050
Text Label 7800 5050 0    60   ~ 0
DIGIT_3
Wire Wire Line
	9650 2600 10000 2600
Text Label 9650 2600 0    60   ~ 0
DIGIT_5
Wire Wire Line
	9650 1400 10000 1400
Text Label 9650 1400 0    60   ~ 0
DIGIT_4
$Comp
L +12V #PWR021
U 1 1 5AC456AC
P 5500 1000
F 0 "#PWR021" H 5500 850 50  0001 C CNN
F 1 "+12V" H 5500 1140 50  0000 C CNN
F 2 "" H 5500 1000 50  0001 C CNN
F 3 "" H 5500 1000 50  0001 C CNN
	1    5500 1000
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR022
U 1 1 5AC4579E
P 5200 2400
F 0 "#PWR022" H 5200 2250 50  0001 C CNN
F 1 "+12V" H 5200 2540 50  0000 C CNN
F 2 "" H 5200 2400 50  0001 C CNN
F 3 "" H 5200 2400 50  0001 C CNN
	1    5200 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 2050 5500 2050
Wire Wire Line
	5500 2050 5500 1000
Wire Wire Line
	5600 3350 5200 3350
Wire Wire Line
	5200 3350 5200 2400
$Comp
L GND #PWR023
U 1 1 5AC45A4D
P 6450 3550
F 0 "#PWR023" H 6450 3300 50  0001 C CNN
F 1 "GND" H 6450 3400 50  0000 C CNN
F 2 "" H 6450 3550 50  0001 C CNN
F 3 "" H 6450 3550 50  0001 C CNN
	1    6450 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 3350 6450 3350
Wire Wire Line
	6450 3350 6450 3550
$Comp
L GND #PWR024
U 1 1 5AC45BB7
P 6450 2250
F 0 "#PWR024" H 6450 2000 50  0001 C CNN
F 1 "GND" H 6450 2100 50  0000 C CNN
F 2 "" H 6450 2250 50  0001 C CNN
F 3 "" H 6450 2250 50  0001 C CNN
	1    6450 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 2050 6450 2050
Wire Wire Line
	6450 2050 6450 2250
Text Label 8800 1800 0    60   ~ 0
dp
Entry Wire Line
	6500 3150 6600 3250
Entry Wire Line
	6500 3150 6600 3250
$Comp
L C C2
U 1 1 5AC4B59A
P 6050 4350
F 0 "C2" H 6075 4450 50  0000 L CNN
F 1 "4.7uF" H 6075 4250 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D7.5mm_W5.0mm_P5.00mm" H 6088 4200 50  0001 C CNN
F 3 "" H 6050 4350 50  0001 C CNN
	1    6050 4350
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 5AC4B923
P 6400 4350
F 0 "C3" H 6425 4450 50  0000 L CNN
F 1 "4.7uF" H 6425 4250 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D7.5mm_W5.0mm_P5.00mm" H 6438 4200 50  0001 C CNN
F 3 "" H 6400 4350 50  0001 C CNN
	1    6400 4350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR025
U 1 1 5AC4B982
P 6400 4700
F 0 "#PWR025" H 6400 4450 50  0001 C CNN
F 1 "GND" H 6400 4550 50  0000 C CNN
F 2 "" H 6400 4700 50  0001 C CNN
F 3 "" H 6400 4700 50  0001 C CNN
	1    6400 4700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR026
U 1 1 5AC4B9D2
P 6050 4700
F 0 "#PWR026" H 6050 4450 50  0001 C CNN
F 1 "GND" H 6050 4550 50  0000 C CNN
F 2 "" H 6050 4700 50  0001 C CNN
F 3 "" H 6050 4700 50  0001 C CNN
	1    6050 4700
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR027
U 1 1 5AC4BA22
P 6050 4050
F 0 "#PWR027" H 6050 3900 50  0001 C CNN
F 1 "+12V" H 6050 4190 50  0000 C CNN
F 2 "" H 6050 4050 50  0001 C CNN
F 3 "" H 6050 4050 50  0001 C CNN
	1    6050 4050
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR028
U 1 1 5AC4BA72
P 6400 4050
F 0 "#PWR028" H 6400 3900 50  0001 C CNN
F 1 "+12V" H 6400 4190 50  0000 C CNN
F 2 "" H 6400 4050 50  0001 C CNN
F 3 "" H 6400 4050 50  0001 C CNN
	1    6400 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 4050 6050 4200
Wire Wire Line
	6400 4050 6400 4200
Wire Wire Line
	6400 4500 6400 4700
Wire Wire Line
	6050 4500 6050 4700
$Comp
L C C1
U 1 1 5AC4C0A0
P 3800 950
F 0 "C1" H 3825 1050 50  0000 L CNN
F 1 "4.7uF" H 3825 850 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D7.5mm_W5.0mm_P5.00mm" H 3838 800 50  0001 C CNN
F 3 "" H 3800 950 50  0001 C CNN
	1    3800 950 
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR029
U 1 1 5AC4C0A6
P 3800 2500
F 0 "#PWR029" H 3800 2250 50  0001 C CNN
F 1 "GND" H 3800 2350 50  0000 C CNN
F 2 "" H 3800 2500 50  0001 C CNN
F 3 "" H 3800 2500 50  0001 C CNN
	1    3800 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 1100 3800 2500
$Comp
L GND #PWR030
U 1 1 5AC4C321
P 1900 7500
F 0 "#PWR030" H 1900 7250 50  0001 C CNN
F 1 "GND" H 1900 7350 50  0000 C CNN
F 2 "" H 1900 7500 50  0001 C CNN
F 3 "" H 1900 7500 50  0001 C CNN
	1    1900 7500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR031
U 1 1 5AC4C37A
P 1200 7500
F 0 "#PWR031" H 1200 7250 50  0001 C CNN
F 1 "GND" H 1200 7350 50  0000 C CNN
F 2 "" H 1200 7500 50  0001 C CNN
F 3 "" H 1200 7500 50  0001 C CNN
	1    1200 7500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 7250 1900 7250
Wire Wire Line
	1900 7250 1900 7500
Wire Wire Line
	1250 7250 1200 7250
Wire Wire Line
	1200 7250 1200 7500
$Comp
L +5V #PWR032
U 1 1 5AC4C69E
P 1200 6700
F 0 "#PWR032" H 1200 6550 50  0001 C CNN
F 1 "+5V" H 1200 6840 50  0000 C CNN
F 2 "" H 1200 6700 50  0001 C CNN
F 3 "" H 1200 6700 50  0001 C CNN
	1    1200 6700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 6700 1900 6950
Wire Wire Line
	1900 6950 1950 6950
Wire Wire Line
	1200 6700 1200 6950
Wire Wire Line
	1200 6950 1250 6950
$Comp
L +12V #PWR033
U 1 1 5AC4CA95
P 1900 6700
F 0 "#PWR033" H 1900 6550 50  0001 C CNN
F 1 "+12V" H 1900 6840 50  0000 C CNN
F 2 "" H 1900 6700 50  0001 C CNN
F 3 "" H 1900 6700 50  0001 C CNN
	1    1900 6700
	1    0    0    -1  
$EndComp
Text Notes 950  6400 0    60   ~ 0
MT3608 Up Converter 5V to 12V
$Comp
L 74HC595_Misc U1
U 1 1 5AC4F758
P 4600 1700
F 0 "U1" H 4750 2300 50  0000 C CNN
F 1 "74HC595_Misc" H 4600 1100 50  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm_LongPads" H 4600 1700 50  0001 C CNN
F 3 "" H 4600 1700 50  0001 C CNN
	1    4600 1700
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR034
U 1 1 5AC4F999
P 4450 900
F 0 "#PWR034" H 4450 750 50  0001 C CNN
F 1 "+5V" H 4450 1040 50  0000 C CNN
F 2 "" H 4450 900 50  0001 C CNN
F 3 "" H 4450 900 50  0001 C CNN
	1    4450 900 
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR035
U 1 1 5AC4F9EC
P 4400 2500
F 0 "#PWR035" H 4400 2250 50  0001 C CNN
F 1 "GND" H 4400 2350 50  0000 C CNN
F 2 "" H 4400 2500 50  0001 C CNN
F 3 "" H 4400 2500 50  0001 C CNN
	1    4400 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 900  4450 950 
Wire Wire Line
	4400 2400 4400 2500
$Comp
L Conn_01x04 J1
U 1 1 5AC4E918
P 1450 7050
F 0 "J1" H 1450 7250 50  0000 C CNN
F 1 "Conn_01x04" H 1450 6750 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 1450 7050 50  0001 C CNN
F 3 "" H 1450 7050 50  0001 C CNN
	1    1450 7050
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x04 J2
U 1 1 5AC4EA61
P 2150 7050
F 0 "J2" H 2150 7250 50  0000 C CNN
F 1 "Conn_01x04" H 2150 6750 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 2150 7050 50  0001 C CNN
F 3 "" H 2150 7050 50  0001 C CNN
	1    2150 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 800  3800 700 
Wire Wire Line
	3900 1850 3800 1850
Connection ~ 3800 1850
Wire Wire Line
	4200 4100 4550 4100
Wire Wire Line
	4200 4200 4550 4200
$Comp
L +5V #PWR?
U 1 1 5B0E28B7
P 9300 650
F 0 "#PWR?" H 9300 500 50  0001 C CNN
F 1 "+5V" H 9300 790 50  0000 C CNN
F 2 "" H 9300 650 50  0001 C CNN
F 3 "" H 9300 650 50  0001 C CNN
	1    9300 650 
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 5B0E2A72
P 9300 1950
F 0 "#PWR?" H 9300 1800 50  0001 C CNN
F 1 "+5V" H 9300 2090 50  0000 C CNN
F 2 "" H 9300 1950 50  0001 C CNN
F 3 "" H 9300 1950 50  0001 C CNN
	1    9300 1950
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 5B0E2E85
P 9300 3150
F 0 "#PWR?" H 9300 3000 50  0001 C CNN
F 1 "+5V" H 9300 3290 50  0000 C CNN
F 2 "" H 9300 3150 50  0001 C CNN
F 3 "" H 9300 3150 50  0001 C CNN
	1    9300 3150
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 5B0E2ED8
P 9300 4400
F 0 "#PWR?" H 9300 4250 50  0001 C CNN
F 1 "+5V" H 9300 4540 50  0000 C CNN
F 2 "" H 9300 4400 50  0001 C CNN
F 3 "" H 9300 4400 50  0001 C CNN
	1    9300 4400
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 5B0E2F2B
P 11050 650
F 0 "#PWR?" H 11050 500 50  0001 C CNN
F 1 "+5V" H 11050 790 50  0000 C CNN
F 2 "" H 11050 650 50  0001 C CNN
F 3 "" H 11050 650 50  0001 C CNN
	1    11050 650 
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 5B0E324E
P 11100 1950
F 0 "#PWR?" H 11100 1800 50  0001 C CNN
F 1 "+5V" H 11100 2090 50  0000 C CNN
F 2 "" H 11100 1950 50  0001 C CNN
F 3 "" H 11100 1950 50  0001 C CNN
	1    11100 1950
	1    0    0    -1  
$EndComp
$EndSCHEMATC
