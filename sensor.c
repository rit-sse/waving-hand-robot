#include <Arduino.h>
#include "sensor.h"

float duration, distance;
float previousDistance = 0;

init_sensor(){
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600); // will have to merge with pir
}

read(){
    float totalDistance = 0;
    int validReadings = 0;

    // Take multiple readings
    for (int i = 0; i < numReadings; i++) {
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);

        duration = pulseIn(echoPin, HIGH);
        distance = duration * distance_multiple;

        // Only include reasonable readings to avoid large jumps
        if (distance > 2 && distance < 400 && abs(distance - previousDistance) < outlierThreshold) {
        totalDistance += distance;
        validReadings++;
        }
        delay(20);
    }

    // Calculate the average distance only from valid readings
    if (validReadings > 0) {
        float averageDistance = totalDistance / validReadings;

        // Only update if the distance change exceeds the threshold
        if (abs(averageDistance - previousDistance) > changeThreshold) {
        Serial.print("Distance: ");
        Serial.println(averageDistance);
        previousDistance = averageDistance;
        }
    }

    delay(200);
}