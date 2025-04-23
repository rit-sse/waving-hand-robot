#include <Arduino.h>
#include "sensor.h"
#include "logging.h"

float duration, distance;
float previousDistance = 0;

init_sensor(){
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

read(){
    float totalDistance = 0;
    int validReadings = 0;

    // Take multiple readings
    for (int i = 0; i < NUM_READINGS; i++) {
        digitalWrite(TRIG_PIN, LOW);
        delayMicroseconds(2);
        digitalWrite(TRIG_PIN, HIGH);
        delayMicroseconds(10);
        digitalWrite(TRIG_PIN, LOW);

        duration = pulseIn(ECHO_PIN, HIGH, 0);
        distance = duration * DISTANCE_MULTIPLE;

        // Only include reasonable readings to avoid large jumps
        if (distance > 2 && distance < 400 && abs(distance - previousDistance) < OUTLIER_THRESHOLD) {
        totalDistance += distance;
        validReadings++;
        }
        delay(20);
    }

    // Calculate the average distance only from valid readings
    if (validReadings > 0) {
        float averageDistance = totalDistance / validReadings;

        // Only update if the distance change exceeds the threshold
        if (abs(averageDistance - previousDistance) > CHANGE_THRESHOLD) {
            log_serial("Distance: ");
        log_serial(averageDistance);
        previousDistance = averageDistance;
        }
    }

    delay(200);
}