#include <Arduino.h>
#include <Wire.h>
#include <Signals.h>
#include <Sensors.h>
#include <Environment.h>
#include <linearAirframe.h>
#include <flightControlSystem.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(4800);
  Signal_initialize();
  Sensors_initialize();
  Environment_initialize();
  flightControlSystem_initialize();
  linearAirframe_initialize();
}

void loop() {
  // put your main code here, to run repeatedly:
  Signal_step();
  Sensors_step();
  Environment_step();
  flightControlSystem_step();
  linearAirframe_step();
  Serial.print(motors_outport[0]);
  Serial.print("  ");
  Serial.print(motors_outport[1]);
  Serial.print("  ");
  Serial.print(motors_outport[2]);
  Serial.print("  ");
  Serial.println(motors_outport[3]);
}