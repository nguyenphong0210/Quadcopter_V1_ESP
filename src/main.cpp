#include <Arduino.h>
#include <Signals.h>
#include <Sensors.h>
#include <Environment.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(300);
  Signal_initialize();
  Sensors_initialize();
  Environment_initialize();
}

void loop() {
  // put your main code here, to run repeatedly:
  Signal_step();
  Sensors_step();
  Environment_step();
  Serial.println(Environment_Y.Environmentb.AtmosphereBus.pressure);
}