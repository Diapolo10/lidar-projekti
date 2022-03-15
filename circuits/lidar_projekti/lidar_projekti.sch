EESchema Schematic File Version 4
EELAYER 30 0
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
L MCU_Module:Arduino_Nano_Every A1
U 1 1 623086B0
P 5900 4100
F 0 "A1" H 5900 3011 50  0000 C CNN
F 1 "Arduino_Nano_Every" H 5900 2920 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 5900 4100 50  0001 C CIN
F 3 "https://content.arduino.cc/assets/NANOEveryV3.0_sch.pdf" H 5900 4100 50  0001 C CNN
	1    5900 4100
	1    0    0    -1  
$EndComp
$Comp
L Device:LED_GRBC D1
U 1 1 6230AA77
P 4400 4250
F 0 "D1" H 4400 4747 50  0000 C CNN
F 1 "LED_GRBC" H 4400 4656 50  0000 C CNN
F 2 "LED_SMD:LED_ASMB-KTF0-0A306" H 4400 4200 50  0001 C CNN
F 3 "~" H 4400 4200 50  0001 C CNN
	1    4400 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 6230C6DA
P 4900 4050
F 0 "R2" V 5107 4050 50  0000 C CNN
F 1 "180R" V 5016 4050 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 4830 4050 50  0001 C CNN
F 3 "~" H 4900 4050 50  0001 C CNN
	1    4900 4050
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R3
U 1 1 6230CE1C
P 4900 4250
F 0 "R3" V 5107 4250 50  0000 C CNN
F 1 "120R" V 5016 4250 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 4830 4250 50  0001 C CNN
F 3 "~" H 4900 4250 50  0001 C CNN
	1    4900 4250
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R4
U 1 1 6230CFB6
P 4900 4450
F 0 "R4" V 5107 4450 50  0000 C CNN
F 1 "120R" V 5016 4450 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 4830 4450 50  0001 C CNN
F 3 "~" H 4900 4450 50  0001 C CNN
	1    4900 4450
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x04 L1
U 1 1 6230D64D
P 5250 2800
F 0 "L1" V 5214 2512 50  0000 R CNN
F 1 "TFmini_Plus_LiDAR" V 5123 2512 50  0000 R CNN
F 2 "Connector:FanPinHeader_1x04_P2.54mm_Vertical" H 5250 2800 50  0001 C CNN
F 3 "~" H 5250 2800 50  0001 C CNN
	1    5250 2800
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R1
U 1 1 6230DED0
P 4650 2950
F 0 "R1" H 4720 2996 50  0000 L CNN
F 1 "R" H 4720 2905 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 4580 2950 50  0001 C CNN
F 3 "~" H 4650 2950 50  0001 C CNN
	1    4650 2950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5200 4200 5200 4050
Wire Wire Line
	5200 4050 5050 4050
Wire Wire Line
	4600 4050 4750 4050
Wire Wire Line
	4600 4250 4750 4250
Wire Wire Line
	4600 4450 4750 4450
Wire Wire Line
	5050 4250 5100 4250
Wire Wire Line
	5100 4250 5100 4300
Wire Wire Line
	5050 4450 5100 4450
Wire Wire Line
	5100 4450 5100 4400
Wire Wire Line
	5200 4200 5400 4200
Wire Wire Line
	5100 4300 5400 4300
Wire Wire Line
	5100 4400 5400 4400
Wire Wire Line
	5400 3800 5200 3800
Wire Wire Line
	5200 3800 5200 3500
Wire Wire Line
	6100 3000 6100 3100
Wire Wire Line
	6100 3000 5450 3000
Wire Wire Line
	5350 3000 5350 3700
Wire Wire Line
	5350 3700 5400 3700
Wire Wire Line
	5400 3600 5250 3600
Wire Wire Line
	5250 3600 5250 3000
NoConn ~ 5400 3300
NoConn ~ 5400 3400
NoConn ~ 5400 3900
NoConn ~ 5400 4000
NoConn ~ 5400 4100
NoConn ~ 5400 4600
NoConn ~ 5400 4700
NoConn ~ 5400 4800
NoConn ~ 6400 4800
NoConn ~ 6400 4700
NoConn ~ 6400 4600
NoConn ~ 6400 4500
NoConn ~ 6400 4400
NoConn ~ 6400 4300
NoConn ~ 6400 4200
NoConn ~ 6400 4100
NoConn ~ 6400 3900
NoConn ~ 6400 3600
NoConn ~ 6400 3500
NoConn ~ 6000 3100
$Comp
L power:GND #PWR0101
U 1 1 623235A0
P 5150 5100
F 0 "#PWR0101" H 5150 4850 50  0001 C CNN
F 1 "GND" H 5155 4927 50  0000 C CNN
F 2 "" H 5150 5100 50  0001 C CNN
F 3 "" H 5150 5100 50  0001 C CNN
	1    5150 5100
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0102
U 1 1 623237BE
P 5800 2700
F 0 "#PWR0102" H 5800 2550 50  0001 C CNN
F 1 "+5V" H 5815 2873 50  0000 C CNN
F 2 "" H 5800 2700 50  0001 C CNN
F 3 "" H 5800 2700 50  0001 C CNN
	1    5800 2700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 62324BA6
P 4200 4350
F 0 "#PWR0103" H 4200 4100 50  0001 C CNN
F 1 "GND" H 4205 4177 50  0000 C CNN
F 2 "" H 4200 4350 50  0001 C CNN
F 3 "" H 4200 4350 50  0001 C CNN
	1    4200 4350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 62325055
P 5150 3050
F 0 "#PWR0104" H 5150 2800 50  0001 C CNN
F 1 "GND" H 5155 2877 50  0000 C CNN
F 2 "" H 5150 3050 50  0001 C CNN
F 3 "" H 5150 3050 50  0001 C CNN
	1    5150 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 5100 5250 5100
Wire Wire Line
	4200 4250 4200 4350
Wire Wire Line
	5150 3000 5150 3050
$Comp
L power:+5V #PWR0105
U 1 1 623269DC
P 3950 3400
F 0 "#PWR0105" H 3950 3250 50  0001 C CNN
F 1 "+5V" H 3965 3573 50  0000 C CNN
F 2 "" H 3950 3400 50  0001 C CNN
F 3 "" H 3950 3400 50  0001 C CNN
	1    3950 3400
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0104
U 1 1 6232A0EB
P 5250 5100
F 0 "#FLG0104" H 5250 5175 50  0001 C CNN
F 1 "PWR_FLAG" H 5250 5273 50  0000 C CNN
F 2 "" H 5250 5100 50  0001 C CNN
F 3 "~" H 5250 5100 50  0001 C CNN
	1    5250 5100
	1    0    0    -1  
$EndComp
Connection ~ 5250 5100
Wire Wire Line
	5250 5100 5150 5100
Wire Wire Line
	5800 2700 5800 3100
Wire Wire Line
	3700 3400 3950 3400
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 62328889
P 3700 3400
F 0 "#FLG0102" H 3700 3475 50  0001 C CNN
F 1 "PWR_FLAG" H 3700 3573 50  0000 C CNN
F 2 "" H 3700 3400 50  0001 C CNN
F 3 "~" H 3700 3400 50  0001 C CNN
	1    3700 3400
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPDT SW2
U 1 1 6233E6FF
P 4300 3400
F 0 "SW2" H 4300 3685 50  0000 C CNN
F 1 "SW_SPDT" H 4300 3594 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_B3S-1100" H 4300 3400 50  0001 C CNN
F 3 "~" H 4300 3400 50  0001 C CNN
	1    4300 3400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 6234526F
P 4800 3050
F 0 "#PWR01" H 4800 2800 50  0001 C CNN
F 1 "GND" H 4805 2877 50  0000 C CNN
F 2 "" H 4800 3050 50  0001 C CNN
F 3 "" H 4800 3050 50  0001 C CNN
	1    4800 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 2950 4800 3050
Wire Wire Line
	4500 3300 4500 2950
Wire Wire Line
	4100 3400 3950 3400
Connection ~ 3950 3400
Wire Wire Line
	4500 3500 5200 3500
$EndSCHEMATC