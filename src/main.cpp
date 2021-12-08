//! This program reads data from a LiDAR sensor and outputs distances to objects.

#include <Arduino.h>
#include <TFmini_plus.h>
#include <SoftwareSerial.h>
#include <EEPROM.h>
#include <inttypes.h>

#include <avr/io.h>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

///////////////////////////////////////////////////////////////////////////////

//TODO: Verify that the RX and TX pins are correct; https://www.arduino.cc/reference/en/language/functions/communication/serial/
const int LIDAR_RX = 2; //D2;
const int LIDAR_TX = 3; //D3;
const int BUTTON_PIN = 4;
const int LED_PIN_RED = 9; // PWM
const int LED_PIN_GREEN = 10; // PWM
const int LED_PIN_BLUE = 11; // PWM
const u8 EEPROM_ADDRESS = 0;
const long LIDAR_UART_BAUDRATE = 115200;
const long LOG_SERIAL_BAUD = 115200;

enum unit_mode {
  METRIC,
  PRECISE,
  MURICAN
};

unit_mode config_mode;
int button_state = 0;
int previous_state{0};

///////////////////////////////////////////////////////////////////////////////

SoftwareSerial soft_serial(LIDAR_RX, LIDAR_TX);
TFminiPlus lidar;

void RGB_colour(u8 red_light_value=0, u8 green_light_value=0, u8 blue_light_value=0)
 {
  analogWrite(LED_PIN_RED, red_light_value);
  analogWrite(LED_PIN_GREEN, green_light_value);
  analogWrite(LED_PIN_BLUE, blue_light_value);

  //TODO: Figure out why OCR1A and the rest aren't defined
  // OCR1A = static_cast<int>(red_light_value/255.0 * 360);
  // OCR1B = static_cast<int>(green_light_value/255.0 * 360);
  // OCR2A = static_cast<int>(blue_light_value/255.0 * 360);
}

void set_LED(unit_mode mode) {
  switch (mode) {
    case METRIC:
      // set LED to green
      RGB_colour(0, 255, 0);
      break;
    case PRECISE:
      // set LED to yellow
      RGB_colour(255, 255, 0);
      break;
    case MURICAN:
      // set LED to red
      RGB_colour(255, 0, 0);
      break;
    default:
      Serial.println("Unsupported mode");
      RGB_colour(255, 255, 255);
  }
}

void cycle_settings() {
  //! Update settings
  switch (config_mode) {
    case METRIC:
      config_mode = PRECISE;
      break;
    case PRECISE:
      config_mode = MURICAN;
      break;
    case MURICAN:
      config_mode = METRIC;
      break;
    default:
      Serial.println("Unsupported mode");
  }

  EEPROM.write(EEPROM_ADDRESS, config_mode);
  set_LED(config_mode);
}

void battery_indicator_led(int charge_percentage) {

}

void setup() {

  //! Docs for register manipulation: https://www.arduino.cc/en/Reference/PortManipulation
  // DDRD |= B11110000;
  DDRB = B11000111;
  PORTB = B00111000;

  //! Start up serial communications
  Serial.begin(LOG_SERIAL_BAUD);
  Serial.println("Started lidar test");

  //! Start up UART communications with the lidar
  soft_serial.begin(LIDAR_UART_BAUDRATE);
  lidar.begin(&soft_serial);

  //! Set lidar options (saving is important)
  lidar.set_framerate(TFMINI_PLUS_FRAMERATE_10HZ);
  lidar.set_output_format(TFMINI_PLUS_OUTPUT_CM);
  lidar.enable_output(true);
  lidar.save_settings();

  //! Get config from EEPROM (if exists)
  u8 value = EEPROM.read(EEPROM_ADDRESS);
  if (value <= 2) {
    //! Load config from EEPROM if exists
    config_mode = static_cast<unit_mode>(value);
  } else {
    //! Initialise the EEPROM state if empty
    config_mode = METRIC;
    EEPROM.write(EEPROM_ADDRESS, config_mode);
  }

  set_LED(config_mode);
}

void loop() {
  //! Check if the settings need to be updated
  previous_state = button_state;
  button_state = digitalRead(BUTTON_PIN);
  if (button_state == HIGH && previous_state != button_state) {
    cycle_settings();
  }

  //! Grab a reading from the lidar
  tfminiplus_data_t data;
  bool result = lidar.read_data(data, true);

  if (result) {
    Serial.println("result: true");
  } else {
    Serial.println("result: false");
  }

  //! Display reading
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
