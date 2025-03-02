const int trigPin = 9; // Trigger pin from ultrasonic sensor
const int echoPin = 10; // Echo pin

float duration, distance;
float previousDistance = 0;
const int numReadings = 20;  // Averages number of readings to guarantee accurate readings
const float changeThreshold = 2.0;  // Minimum change in distance to update
const float outlierThreshold = 200.0;  // Maximum allowed deviation from previous average

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
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
    distance = (duration * 0.0343) / 2;

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
