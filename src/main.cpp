#include <Arduino.h>
// #include <Adafruit_MPU6050.h>
// #include <Adafruit_Sensor.h>
// #include <Wire.h>
#include <Signals.h>
#include <Sensors.h>

// Adafruit_MPU6050 mpu;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Signal_initialize();
  Sensors_initialize();
}

void loop() {
  // put your main code here, to run repeatedly:
  Signal_step();
  Sensors_step();
  Serial.println(sensor_inport.HALSensors.HAL_acc_SI.z);
}