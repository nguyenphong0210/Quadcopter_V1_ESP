#include <Arduino.h>
#include <Signals.h>
#include <Sensors.h>
#include <Environment.h>
#include <linearAirframe.h>
#include <flightControlSystem.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(1200);
  Signal_initialize();
  Sensors_initialize();
  Environment_initialize();
  linearAirframe_initialize();
  flightControlSystem_initialize();
}

void loop() {
  // put your main code here, to run repeatedly:
  Signal_step();
  Sensors_step();
  Environment_step();
  linearAirframe_step();
  flightControlSystem_step();
  Serial.println(motors_outport[0]);
}