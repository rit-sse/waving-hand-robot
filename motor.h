#ifndef MOTOR_H_
#define MOTOR_H_
#ifdef __cplusplus
extern "C" {
#endif

#define DIRECTOR_PIN 4
#define STEPPER_PIN 3
#define ENABLE_PIN 7
#define STEP_PER_REVOLUTION 50
#define TIME_BETWEEN_STEPS 3000
#define DELAY_TICS_MILIS 50
#define RESET_WAVE_COUNT_VALUE 10

  /**
 * initializes motor pins for usage in motor control
 * 
 * MUST BE CALLED IN ORDER TO RUN MOTOR
 */
  void init_motor();

  /**
 * sets the bot to start waving anew, if already waving
 *  it will reset the number of expected waves to do
 */
  void trigger_wave();

  /**
 * main loop for motor, will wave if theres waves to be counted
 *
 * this should only be called within the main arduino loop
 */
  void wave();

#ifdef __cplusplus
}  // extern "C"
#endif
#endif