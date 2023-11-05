#include <Arduino.h>
#include <Wire.h>
#include <Signals.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Signal_initialize();
}

void loop() {
  // put your main code here, to run repeatedly:
  Signal_step();
}
