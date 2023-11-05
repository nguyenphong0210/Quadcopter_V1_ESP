#include <Arduino.h>
#include <Wire.h>
#include "Signals.h"

void setup() {
  // put your setup code here, to run once:
  Signal_initialize();
}

void loop() {
  // put your main code here, to run repeatedly:
  Signal_step();
}
