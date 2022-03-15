EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr User 5189 5212
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
L MCU_Module:Arduino_Nano_Every A1
U 1 1 623086B0
P 3550 2150
F 0 "A1" H 3550 1061 50  0000 C CNN
F 1 "Arduino_Nano_Every" H 3550 970 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 3550 2150 50  0001 C CIN
F 3 "https://content.arduino.cc/assets/NANOEveryV3.0_sch.pdf" H 3550 2150 50  0001 C CNN
	1    3550 2150
	1    0    0    -1  
$EndComp
$Comp
L Device:LED_GRBC D1
U 1 1 6230AA77
P 2050 2300
F 0 "D1" H 2050 2797 50  0000 C CNN
F 1 "LED_GRBC" H 2050 2706 50  0000 C CNN
F 2 "LED_SMD:LED_ASMB-KTF0-0A306" H 2050 2250 50  0001 C CNN
F 3 "~" H 2050 2250 50  0001 C CNN
	1    2050 2300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 6230C6DA
P 2550 2100
F 0 "R2" V 2757 2100 50  0000 C CNN
F 1 "180R" V 2666 2100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 2480 2100 50  0001 C CNN
F 3 "~" H 2550 2100 50  0001 C CNN
	1    2550 2100
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R3
U 1 1 6230CE1C
P 2550 2300
F 0 "R3" V 2757 2300 50  0000 C CNN
F 1 "120R" V 2666 2300 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 2480 2300 50  0001 C CNN
F 3 "~" H 2550 2300 50  0001 C CNN
	1    2550 2300
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R4
U 1 1 6230CFB6
P 2550 2500
F 0 "R4" V 2757 2500 50  0000 C CNN
F 1 "120R" V 2666 2500 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 2480 2500 50  0001 C CNN
F 3 "~" H 2550 2500 50  0001 C CNN
	1    2550 2500
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x04 L1
U 1 1 6230D64D
P 2900 850
F 0 "L1" V 2864 562 50  0000 R CNN
F 1 "TFmini_Plus_LiDAR" V 2773 562 50  0000 R CNN
F 2 "Connector:FanPinHeader_1x04_P2.54mm_Vertical" H 2900 850 50  0001 C CNN
F 3 "~" H 2900 850 50  0001 C CNN
	1    2900 850 
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R1
U 1 1 6230DED0
P 2300 1000
F 0 "R1" V 2507 1000 50  0000 C CNN
F 1 "10k" V 2416 1000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 2230 1000 50  0001 C CNN
F 3 "~" H 2300 1000 50  0001 C CNN
	1    2300 1000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2850 2250 2850 2100
Wire Wire Line
	2850 2100 2700 2100
Wire Wire Line
	2250 2100 2400 2100
Wire Wire Line
	2250 2300 2400 2300
Wire Wire Line
	2250 2500 2400 2500
Wire Wire Line
	2700 2300 2750 2300
Wire Wire Line
	2750 2300 2750 2350
Wire Wire Line
	2700 2500 2750 2500
Wire Wire Line
	2750 2500 2750 2450
Wire Wire Line
	2850 2250 3050 2250
Wire Wire Line
	2750 2350 3050 2350
Wire Wire Line
	2750 2450 3050 2450
Wire Wire Line
	3050 1850 2850 1850
Wire Wire Line
	2850 1850 2850 1550
Wire Wire Line
	3750 1050 3750 1150
Wire Wire Line
	3750 1050 3100 1050
Wire Wire Line
	3000 1050 3000 1750
Wire Wire Line
	3000 1750 3050 1750
Wire Wire Line
	3050 1650 2900 1650
Wire Wire Line
	2900 1650 2900 1050
NoConn ~ 3050 1350
NoConn ~ 3050 1450
NoConn ~ 3050 1950
NoConn ~ 3050 2050
NoConn ~ 3050 2150
NoConn ~ 3050 2650
NoConn ~ 3050 2750
NoConn ~ 3050 2850
NoConn ~ 4050 2850
NoConn ~ 4050 2750
NoConn ~ 4050 2650
NoConn ~ 4050 2550
NoConn ~ 4050 2450
NoConn ~ 4050 2350
NoConn ~ 4050 2250
NoConn ~ 4050 2150
NoConn ~ 4050 1950
NoConn ~ 4050 1650
NoConn ~ 4050 1550
NoConn ~ 3650 1150
$Comp
L power:GND #PWR0101
U 1 1 623235A0
P 2800 3150
F 0 "#PWR0101" H 2800 2900 50  0001 C CNN
F 1 "GND" H 2805 2977 50  0000 C CNN
F 2 "" H 2800 3150 50  0001 C CNN
F 3 "" H 2800 3150 50  0001 C CNN
	1    2800 3150
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0102
U 1 1 623237BE
P 3450 750
F 0 "#PWR0102" H 3450 600 50  0001 C CNN
F 1 "+5V" H 3465 923 50  0000 C CNN
F 2 "" H 3450 750 50  0001 C CNN
F 3 "" H 3450 750 50  0001 C CNN
	1    3450 750 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 62324BA6
P 1850 2400
F 0 "#PWR0103" H 1850 2150 50  0001 C CNN
F 1 "GND" H 1855 2227 50  0000 C CNN
F 2 "" H 1850 2400 50  0001 C CNN
F 3 "" H 1850 2400 50  0001 C CNN
	1    1850 2400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 62325055
P 2800 1100
F 0 "#PWR0104" H 2800 850 50  0001 C CNN
F 1 "GND" H 2805 927 50  0000 C CNN
F 2 "" H 2800 1100 50  0001 C CNN
F 3 "" H 2800 1100 50  0001 C CNN
	1    2800 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 3150 2900 3150
Wire Wire Line
	1850 2300 1850 2400
Wire Wire Line
	2800 1050 2800 1100
$Comp
L power:+5V #PWR0105
U 1 1 623269DC
P 1600 1450
F 0 "#PWR0105" H 1600 1300 50  0001 C CNN
F 1 "+5V" H 1615 1623 50  0000 C CNN
F 2 "" H 1600 1450 50  0001 C CNN
F 3 "" H 1600 1450 50  0001 C CNN
	1    1600 1450
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0104
U 1 1 6232A0EB
P 2900 3150
F 0 "#FLG0104" H 2900 3225 50  0001 C CNN
F 1 "PWR_FLAG" H 2900 3323 50  0000 C CNN
F 2 "" H 2900 3150 50  0001 C CNN
F 3 "~" H 2900 3150 50  0001 C CNN
	1    2900 3150
	1    0    0    -1  
$EndComp
Connection ~ 2900 3150
Wire Wire Line
	2900 3150 2800 3150
Wire Wire Line
	3450 750  3450 1150
Wire Wire Line
	1350 1450 1600 1450
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 62328889
P 1350 1450
F 0 "#FLG0102" H 1350 1525 50  0001 C CNN
F 1 "PWR_FLAG" H 1350 1623 50  0000 C CNN
F 2 "" H 1350 1450 50  0001 C CNN
F 3 "~" H 1350 1450 50  0001 C CNN
	1    1350 1450
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPDT SW2
U 1 1 6233E6FF
P 1950 1450
F 0 "SW2" H 1950 1735 50  0000 C CNN
F 1 "SW_SPDT" H 1950 1644 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_B3S-1100" H 1950 1450 50  0001 C CNN
F 3 "~" H 1950 1450 50  0001 C CNN
	1    1950 1450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 6234526F
P 2450 1100
F 0 "#PWR01" H 2450 850 50  0001 C CNN
F 1 "GND" H 2455 927 50  0000 C CNN
F 2 "" H 2450 1100 50  0001 C CNN
F 3 "" H 2450 1100 50  0001 C CNN
	1    2450 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 1000 2450 1100
Wire Wire Line
	2150 1350 2150 1000
Wire Wire Line
	1750 1450 1600 1450
Connection ~ 1600 1450
Wire Wire Line
	2150 1550 2850 1550
Text Notes 900  4450 0    50   ~ 0
LiDAR-Projekti
Text Notes 1650 4600 0    50   ~ 0
2022/03/15
Text Notes 4100 4600 0    50   ~ 0
1.0\n
$EndSCHEMATC
