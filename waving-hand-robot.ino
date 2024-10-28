#include "motor.h"

// needs to be on pin 2, as it is one of the only arduino uno interrupt pins
#define PUSH_BUTTON_PIN 2

void setup() {
  // put your setup code here, to run once:
  init_motor();

  // push button
  pinMode(PUSH_BUTTON_PIN, INPUT); 
  attachInterrupt(digitalPinToInterrupt(PUSH_BUTTON_PIN), pushButtonInterrupt, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  wave();
}

/**
 * interrupt to wave robot using a push button 
 *
 * CAN BE DELETED IN FINAL VERSION
 */
void pushButtonInterrupt()
{
  trigger_wave();
}