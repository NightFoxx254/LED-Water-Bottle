#include <FastLED.h>
#include <iostream>
#include <cmath>

#define NUM_LEDS 300
#define DATA_PIN 0

CRGB leds[NUM_LEDS];


#include "MPU9250.h"

// an MPU9250 object with the MPU-9250 sensor on I2C bus 0 with address 0x68
MPU9250 IMU(Wire,0x68);
int status;

double radiansToDegrees(double radians) {
    return radians * (180.0 / M_PI);
}

void setup() {
  FastLED.addLeds<NEOPIXEL,DATAPIN>(leds, NUM_LEDS);
  // serial to display data
  Serial.begin(115200);
  while(!Serial) {}

  // start communication with IMU 
  status = IMU.begin();
  if (status < 0) {
    Serial.println("IMU initialization unsuccessful");
    Serial.println("Check IMU wiring or try cycling power");
    Serial.print("Status: ");
    Serial.println(status);
    while(1) {}
  }
}

void loop() {
  // read the sensor
  IMU.readSensor();

  int GyroX = IMU.getGyroX_degrees(); 
  int GyroY = IMU.getGyroY_degrees();
  

  Serial.println();
  delay(200);
} 
 
