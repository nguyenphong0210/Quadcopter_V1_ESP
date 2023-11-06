#include <Arduino.h>
#include <Signals.h>
#include <Sensors.h>
#include <Environment.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(1200);
  Signal_initialize();
  Sensors_initialize();
  Environment_initialize();
}

void loop() {
  // put your main code here, to run repeatedly:
  Signal_step();
  Sensors_step();
  Environment_step();
  Serial.println(sensor_inport.HALSensors.HAL_acc_SI.x);
}