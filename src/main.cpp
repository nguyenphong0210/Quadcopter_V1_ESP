#include <Arduino.h>
#include <MPU6050.h>
#include <Wire.h>
#include <Signals.h>

MPU6050 mpu6050(Wire);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Signal_initialize();
}

void loop() {
  // put your main code here, to run repeatedly:
  Signal_step();
  Serial.println(cmd_inport.live_time_ticks);
}
