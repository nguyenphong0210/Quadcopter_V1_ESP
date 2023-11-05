#include <Arduino.h>
#include <Signals.h>
#include <Sensors.h>
#include <Environment.h>
#include <linearAirframe.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(300);
  Signal_initialize();
  Sensors_initialize();
  Environment_initialize();
  linearAirframe_initialize();
}

void loop() {
  // put your main code here, to run repeatedly:
  Signal_step();
  Sensors_step();
  Environment_step();
  linearAirframe_step();
  Serial.println(rtDW.TmpSignalConversionAtLinearMode[0]);
}