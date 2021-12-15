/*! \file main.cpp
 *  \brief An Arduino Every program.
 *
 * This program reads data from a LiDAR sensor and outputs
 * distances to objects.
 */

#include <Arduino.h>
#include <TFmini_plus.h>
#include <SoftwareSerial.h>
#include <EEPROM.h>
#include <inttypes.h>

/** \name Type Aliases
 * \brief Rust-like aliases for numeric types
 */
///@{
typedef uint8_t  u8;  //!< Unsigned 8-bit integer
typedef uint16_t u16; //!< Unsigned 16-bit integer
typedef uint32_t u32; //!< Unsigned 32-bit integer
typedef uint64_t u64; //!< Unsigned 64-bit integer
typedef int8_t   i8;  //!< Signed 8-bit integer
typedef int16_t  i16; //!< Signed 16-bit integer
typedef int32_t  i32; //!< Signed 32-bit integer
typedef int64_t  i64; //!< Signed 64-bit integer
///@}

///////////////////////////////////////////////////////////////////////////////

//TODO: Verify that the RX and TX pins are correct; https://www.arduino.cc/reference/en/language/functions/communication/serial/

/** \defgroup CONSTANTS Constant values used in the LiDAR project
 *
 * This section includes information about named constants used in the project.
 * Many of them exist to make hot-swapping pins or data rates easier,
 * though some are hard values that shouldn't be changed.
 *
 */

/** @addtogroup CONSTANTS_PINS Pins
 * \ingroup CONSTANTS
 * \brief Named hardware pin constants used in the project
 * @{ */
const int LIDAR_RX = 2;             //!< Lidar sensor data read pin, D2
const int LIDAR_TX = 3;             //!< Lidar sensor data write pin, D3
const int BUTTON_PIN = 4;           //!< Pin assigned for the button that controls measurement precision, D4
const int LED_PIN_RED = 9;          //!< PWM pin used to control the red LED, D9
const int LED_PIN_GREEN = 10;       //!< PWM pin used to control the green LED, D10
const int LED_PIN_BLUE = 11;        //!< PWM pin used to control the blue LED, D11
const int BATTERY_VOLTAGE_PIN = 14; //!< ADC pin used to read battery voltage, A0 (D14) !!!!!CHECK PIN!!!!!
/** @} */

/** @addtogroup CONSTANTS_MEMORY Memory addresses
 * \ingroup CONSTANTS
 * \brief Named EEPROM address constants used in the project
 * @{ */
const u8 UNIT_MODE_CONFIG_ADDRESS = 0;  //!< EEPROM address where LiDAR unit mode configuration is stored
/** @} */

/** @addtogroup CONSTANTS_SERIAL Serial configuration
 * \ingroup CONSTANTS
 * \brief Named serial constants used in the project
 * @{ */
const long LIDAR_UART_BAUDRATE = 115200;  //!< LiDAR serial output frequency
const long LOG_SERIAL_BAUDRATE = 115200;    //!< Serial logging output frequency
/** @} */

/**
 * \brief Represents the different modes for measuremement units supported by the LiDAR sensor
 *
 * Used to store the mode in use in the device memory.
 */
enum unit_mode {
  LIDAR_CM,  //!< Measurements in centimetres
  LIDAR_MM,  //!< Measurements in millimetres
  LIDAR_PIXHAWK  //!< Measurements in Pixhawk drone units
};

///////////////////////////////////////////////////////////////////////////////

/** \defgroup GLOBAL_VARIABLES Global values used in the LiDAR project
 *
 * This section includes information about global variables used in the project.
 * Their main purpose is keeping track of hardware events and to provide mutable state
 * for the program.
 *
 */

/** @addtogroup GLOBAL_VARIABLES_STATE State tracking
 * \ingroup GLOBAL_VARIABLES
 * \brief Hardware state tracking used in the project
 * @{ */
unit_mode config_mode;  //!< Stores the LiDAR measurement unit
int button_state = 0;   //!< Stores the current state of the button (up/down, 0/1)
int previous_state{0};  //!< Stores the previous state of the button (up/down, 0/1)
/** @} */

/** @addtogroup GLOBAL_VARIABLES_OTHER Other globals
 * \ingroup GLOBAL_VARIABLES
 * \brief Other required global state
 * @{ */
SoftwareSerial soft_serial(LIDAR_RX, LIDAR_TX);  //!< Handles serial traffic with the LiDAR sensor
TFminiPlus lidar;  //!< Needed to configure the LiDAR sensor
/** @} */

///////////////////////////////////////////////////////////////////////////////

/**
 * @brief Sets the colour and brightness of the RGB LED based on the colour values of the parameters
 *
 * By mixing the colours, different colours can be created. \n
 * Yellow = red + green \n
 * Purple = red + blue \n
 * Cyan   = green + blue \n
 * White  = red + green + blue
 *
 * Different concentrations produce different shades.
 *
 * @param red_light_value   Controls the amount of red light (0-255)
 * @param green_light_value Controls the amount of green light (0-255)
 * @param blue_light_value  Controls the amount of blue light (0-255)
 */
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


/**
 * @brief Changes the colour of the RGB LED to fixed colours based on the current LiDAR unit
 *
 * @param mode The current LiDAR unit mode
 */
void set_LED(unit_mode mode) {
  switch (mode) {

    case LIDAR_CM:
      ///< set LED to green
      Serial.println("set LED to green");
      RGB_colour(0, 200, 0);
      break;

    case LIDAR_MM:
      ///< set LED to yellow
      Serial.println("set LED to yellow");
      RGB_colour(200, 200, 0);
      break;

    case LIDAR_PIXHAWK:
      ///< set LED to red
      Serial.println("set LED to red");
      RGB_colour(200, 0, 0);
      break;

    default:
      Serial.println("Unsupported mode");
      ///< Set LED to white
      RGB_colour(200, 200, 200);

  }
}

/**
 * @brief Sets the lidar output format
 *
 * @param mode The current LiDAR unit mode
 */
void set_lidar_output_format(unit_mode mode) {
  //! Update settings
  switch (mode) {
    case LIDAR_CM:
      lidar.set_output_format(TFMINI_PLUS_OUTPUT_CM);
      break;
    case LIDAR_MM:
      lidar.set_output_format(TFMINI_PLUS_OUTPUT_MM);
      break;
    case LIDAR_PIXHAWK:
      lidar.set_output_format(TFMINI_PLUS_OUTPUT_PIXHAWK);
      break;
    default:
      Serial.println("Unsupported mode");
      return;
  }
  lidar.save_settings();

  set_LED(mode);
}

/**
 * @brief Changes the LiDAR unit mode
 *
 * The function cycles over all the modes available,
 * picking the next one in the sequence,
 * then changes the config mode to that. Afterwards it
 * changes the RGB LED to show the new setting and
 * stores this setting into the EEPROM.
 *
 */
void cycle_settings() {
  //! Update settings
  switch (config_mode) {

    case LIDAR_CM:
      config_mode = LIDAR_MM;
      break;

    case LIDAR_MM:
      config_mode = LIDAR_PIXHAWK;
      break;

    case LIDAR_PIXHAWK:
      config_mode = LIDAR_CM;
      break;

    default:
      Serial.println("Unsupported mode");
      return;

  }

  set_lidar_output_format(config_mode);
  EEPROM.write(UNIT_MODE_CONFIG_ADDRESS, config_mode);
}

/**
 * @brief Reads the battery level and shows it via LED
 *
 */
void read_battery_level() {
  // Read battery voltage (10 bits, so 0V is 0 and 5V is 1023)
  int value = analogRead(BATTERY_VOLTAGE_PIN);
  float voltage = value * (5.0 / 1023.0);
  Serial.println("Voltage: " + String(voltage));

  // Set led color
  if (voltage > 3.7)
    RGB_colour(0, 200, 0);
  else if (voltage > 3.2)
    RGB_colour(0, 200, 200);
  else
    RGB_colour(200, 0, 0);

  // Wait 2 seconds and set the led back to show the config mode state
  delay(2000);
  set_LED(config_mode);
}


/**
 * @brief Sets up the register, serial traffic, LiDAR configuration, and EEPROM config
 *
 */
void setup() {

  // Docs for register manipulation: https://www.arduino.cc/en/Reference/PortManipulation
  // DDRX <- B76543210

  /**
   * @brief Details on the set DDRD pins
   *
   * 0-1: Unused pins (built-in serial)
   * 2-3: LiDAR serial (read, write)
   * 4:   Button pin (read)
   * 5-7: Unused
   */
  DDRD |= B00001000;
  /**
   * @brief Details on the set DDRB pins
   *
   * 0-1: Unused pins (built-in crystals) (D6-7)
   * 2:   Unused pin (D8)
   * 3:   Red LED pin (write) (D9)
   * 4:   Green LED pin (write) (D10)
   * 5:   Blue LED pin (write) (D11)
   * 6-7: Unused pin (D12)
   */
  DDRB |= B00111000;
  PORTB = B00111000;  //!< Lits up the LEDs

  /**
   * @brief Details on the set DDRC pins
   *
   * 0:   Voltage measurement pin (read) (A0)
   * 1-7: Unused (A1-A7)
   */
  DDRC |= B00000000;

  // pinMode(LIDAR_RX, INPUT);
  // pinMode(LIDAR_TX, OUTPUT);
  // pinMode(BUTTON_PIN, INPUT);
  // pinMode(LED_PIN_RED, OUTPUT);
  // pinMode(LED_PIN_GREEN, OUTPUT);
  // pinMode(LED_PIN_BLUE, OUTPUT);
  // pinMode(BATTERY_VOLTAGE_PIN, OUTPUT);

  //!< Start up serial communications
  Serial.begin(LOG_SERIAL_BAUDRATE);
  Serial.println("Started lidar test");

  //!< Start up UART communications with the lidar
  soft_serial.begin(LIDAR_UART_BAUDRATE);
  lidar.begin(&soft_serial);

  //!< Set lidar options (saving is important)
  lidar.set_framerate(TFMINI_PLUS_FRAMERATE_10HZ);
  lidar.set_output_format(TFMINI_PLUS_OUTPUT_CM);
  lidar.enable_output(true);
  lidar.save_settings();

  //!< Get config from EEPROM (if exists)
  u8 value = EEPROM.read(UNIT_MODE_CONFIG_ADDRESS);
  if (value <= 2) {
    //!< Load config from EEPROM if exists
    config_mode = static_cast<unit_mode>(value);
  } else {
    //!< Initialise the EEPROM state if empty
    config_mode = LIDAR_CM;
    EEPROM.write(UNIT_MODE_CONFIG_ADDRESS, config_mode);
  }

  set_lidar_output_format(config_mode);
}

/**
 * @brief The main program loop
 *
 */
void loop() {
  //!< Check if the settings need to be updated
  previous_state = button_state;
  button_state = digitalRead(BUTTON_PIN);
  if (button_state == LOW && previous_state != button_state) {
    // If the button is still pressed after 0.5 seconds, show the battery level and otherwise show LiDAR mode
    delay(500);
    if (digitalRead(BUTTON_PIN) == LOW)
      read_battery_level();
    } else {
      cycle_settings();
      Serial.println("Change mode");
    }
  }

  //!< Grab a reading from the lidar
  tfminiplus_data_t data;
  bool result = lidar.read_data(data, true);

  /*if (result) {
    Serial.println("result: true");
  } else {
    Serial.println("result: false");
  }*/

  //!< Display reading
  /*String output = "Distance: " + String((float)data.distance/1000.0f) + " m (" + String(data.distance) + " cm)\t";
  output += "Strength: " + String(data.strength) + "\t";
  output += "Temperature: " + String(data.temperature) + " °C";
  Serial.println(output);*/

  delay(200);
}
