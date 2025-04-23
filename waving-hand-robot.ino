#include "motor.h"
#include "sensor.h"

#define MIN_WAVE_DIST 50 // this will need to be changed whenever I have the motor

void setup() {
  // put your setup code here, to run once:
  init_motor();
  init_sensor();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // read ultrasonic sensor input
  int value = read();

  // if someone is close enough to the sensor for it to be a 'wave'
  if(value <= MIN_WAVE_DIST){
    trigger_wave();
  }
}