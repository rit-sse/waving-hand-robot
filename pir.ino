int ledPin = 13;
int irPin1 = 2;
int irPin2 = 3;

int cachedState1 = LOW;
int cachedState2 = LOW;
int peopleInLab = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(irPin1, INPUT);
  pinMode(irPin2, INPUT);
  Serial.begin(9600); // will have to merge with ultrasonic
  // probably both publish to a serial subscriber that sends it over serial?
}

void loop(){
  int irState1 = digitalRead(irPin1);
  int irState2 = digitalRead(irPin2);
  // loop counter for printing
  static int loopCounter = 0;
  loopCounter++;
  // 2 sensors next to eachother
  // someone walks through they trip 1 then 2
  // someone walks out they trip 2 then 1
  // reading this back I'm not confident it even works as described
  if (irState1 == HIGH && irState2 == LOW) {
    peopleInLab++;
    Serial.println("++");
  } else if (irState1 == LOW && irState2 == HIGH) {
    peopleInLab--;
    Serial.println("--");
  }
  // print out information every 7.5 seconds
  if (loopCounter % 10 == 0) {
    Serial.print("In Lab: ");
    Serial.println(peopleInLab);
  }
    

  cachedState1 = LOW;
  cachedState2 = LOW;

  delay(750); // hopefully just evaporates sensor noise
  // not good enough, maybe require multiple reads in quick succession?

}
