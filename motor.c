#include <Arduino.h>
#include "motor.h"

// counts number of waves to do before sleeping
static volatile int wave_count = 0;
// flag for enabling the driver when user input is read
static volatile uint8_t driver_just_started = 0;

/**
 * enables driver
 */
void enable_motor()
{
  digitalWrite(ENABLE_PIN, LOW);
}

/**
 * turns off driver to reduce power consumption
 */
void disable_motor()
{
  digitalWrite(ENABLE_PIN, HIGH);
}

void init_motor() {
  // dir pin
  pinMode(DIRECTOR_PIN, OUTPUT);
  // step pin
  pinMode(STEPPER_PIN, OUTPUT);
  
  // the motor control pin
  pinMode(ENABLE_PIN, OUTPUT);
  // by default disable to driver
  disable_motor();
}

void trigger_wave() {
  // set state so that we wait next iteration for driver to turn on
  if (!driver_just_started && !wave_count)
    driver_just_started = 1;

  // reset wave count and enable the driver
  wave_count = RESET_WAVE_COUNT_VALUE;
}

void wave() {
  // if just turned on, then wait for the driver to start up
  if (driver_just_started)
  {
    // enable the driver
    enable_motor();
    delayMicroseconds(2000);
    driver_just_started = 0;
  }

  // if need to wave, wave!
  //    else, disable the driver
  if (wave_count > 0) {
    // Set motor direction clockwise
    digitalWrite(DIRECTOR_PIN, HIGH);

    // motor wave right 45 degrees
    for (int x = 0; x < STEP_PER_REVOLUTION; x++) {
      digitalWrite(STEPPER_PIN, HIGH);
      delayMicroseconds(TIME_BETWEEN_STEPS);
      digitalWrite(STEPPER_PIN, LOW);
      delayMicroseconds(TIME_BETWEEN_STEPS);
    }
    delay(DELAY_TICS_MILIS);  // Wait

    // Set motor direction counterclockwise
    digitalWrite(DIRECTOR_PIN, LOW);

    // motor wave left 45 degrees
    for (int x = 0; x < STEP_PER_REVOLUTION; x++) {
      digitalWrite(STEPPER_PIN, HIGH);
      delayMicroseconds(TIME_BETWEEN_STEPS);
      digitalWrite(STEPPER_PIN, LOW);
      delayMicroseconds(TIME_BETWEEN_STEPS);
    }

    delay(DELAY_TICS_MILIS);  // Wait

    wave_count--;
  }
  else
  {
    disable_motor();
  }
}