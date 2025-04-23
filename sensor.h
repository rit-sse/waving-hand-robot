#ifndef _sensor
#define _sensor
#ifdef __cplusplus
extern "C" {
#endif

#define TRIG_PIN 9 // Trigger pin from ultrasonic sensor
#define ECHO_PIN 10 // Echo pin

#define DISTANCE_MULTIPLE 0.01715 / 2 // was magic number before 0.0343 / 2, typing this into duckduckgo to precalculate says derived from speed of sound
#define NUM_READINGS 20  // Averages number of readings to guarantee accurate readings
#define CHANGE_THRESHOLD 2.0  // Minimum change in distance to update
#define OUTLIER_THRESHOLD 200.0  // Maximum allowed deviation from previous average

void init_sensor();

int read();

#ifdef __cplusplus
}  // extern "C"
#endif
#endif