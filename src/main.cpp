//! This program reads data from a LiDAR sensor and outputs distances to objects.

#include <Arduino.h>
#include <TFmini_plus.h>
#include <SoftwareSerial.h>

///////////////////////////////////////////////////////////////////////////////

const int LIDAR_RX = 2; //D2;
const int LIDAR_TX = 1; //D1;
const long LIDAR_UART_BAUDRATE = 115200;

const long LOG_SERIAL_BAUD = 115200;

///////////////////////////////////////////////////////////////////////////////

SoftwareSerial soft_serial(LIDAR_RX, LIDAR_TX);
TFminiPlus lidar;

void setup() {
  // Start up serial communications
  Serial.begin(LOG_SERIAL_BAUD);
  Serial.println("Started lidar test");

  // Start up UART communications with the lidar
  soft_serial.begin(LIDAR_UART_BAUDRATE);
  lidar.begin(&soft_serial);

  // Set lidar options (saving is important)
  lidar.set_framerate(TFMINI_PLUS_FRAMERATE_10HZ);
  lidar.set_output_format(TFMINI_PLUS_OUTPUT_CM);
  lidar.enable_output(true);
  lidar.save_settings();
}

void loop() {
  // Grab a reading from the lidar
  tfminiplus_data_t data;
  bool result = lidar.read_data(data, true);

  if (result)
    Serial.println("result: true");
  else
    Serial.println("result: false");

  // Display reading
  String output = "Distance: " + String((float)data.distance/1000.0f) + " m (" + String(data.distance) + " cm)\t";
  output += "Strength: " + String(data.strength) + "\t";
  output += "Temperature: " + String(data.temperature) + " °C";
  Serial.println(output);

  delay(1000);
}



/*
  This program is the interpretation routine of standard output protocol of TFmini-Plus product on Arduino.
  For details, refer to Product Specifications.
  For Arduino boards with only one serial port like UNO board, the function of software visual serial port is to be used.
*/
/*#include <Arduino.h>
#include <SoftwareSerial.h>  //header file of software serial port
SoftwareSerial Serial1_(2,3); //define software serial port name as Serial1_ and define pin2 as RX and pin3 as TX
/* For Arduinoboards with multiple serial ports like DUEboard, interpret above two pieces of code and directly use Serial1_ serial port* /
int dist; //actual distance measurements of LiDAR
int strength; //signal strength of LiDAR
float temprature;
int check;  //save check value
int i;
int uart[9];  //save data measured by LiDAR
const int HEADER=0x59;  //frame header of data package
void setup() {
  Serial.begin(9600); //set bit rate of serial port connecting Arduino with computer
  Serial1_.begin(115200);  //set bit rate of serial port connecting LiDAR with Arduino
}
void loop() {
  //if (Serial1_.available()) {  //check if serial port has data input
    //if(Serial1_.read() == HEADER) {  //assess data package frame header 0x59
      uart[0]=HEADER;
      //if (Serial1_.read() == HEADER) { //assess data package frame header 0x59
        uart[1] = HEADER;
        for (i = 2; i < 9; i++) { //save data in array
          uart[i] = Serial1_.read();
        }
        check = uart[0] + uart[1] + uart[2] + uart[3] + uart[4] + uart[5] + uart[6] + uart[7];
        //if (uart[8] == (check & 0xff)){ //verify the received data as per protocol
          dist = uart[2] + uart[3] * 256;     //calculate distance value
          strength = uart[4] + uart[5] * 256; //calculate signal strength value
          temprature = uart[6] + uart[7] *256;//calculate chip temprature
          temprature = temprature/8 - 256;
          Serial.print("dist = ");
          Serial.print(dist); //output measure distance value of LiDAR
          Serial.print('\t');
          Serial.print("strength = ");
          Serial.print(strength); //output signal strength value
          Serial.print("\t Chip Temprature = ");
          Serial.print(temprature);
          Serial.println(" celcius degree"); //output chip temperature of Lidar
        //} else { Serial.println("else 3"); }
      //} else { Serial.println("else 2"); }
    //} else { Serial.println("else 1"); }
  //} else {
    /*delay(400);
    Serial.println("Serial1_.available() -> else");
    for(int i = 0; i<9; i++) {
      Serial.println(uart[i]);
    }* /

  //}
  delay(600);
}*/


/**/
