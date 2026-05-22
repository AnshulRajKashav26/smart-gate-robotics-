#include <Servo.h>

Servo gate;

const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int LED_PIN  = 13;
const int THRESHOLD_CM = 50;

bool gateOpen = false;

long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration / 58;
}

void blinkLED(int durationMs) {
  unsigned long start = millis();
  while (millis() - start < durationMs) {
    digitalWrite(LED_PIN, HIGH); delay(200);
    digitalWrite(LED_PIN, LOW);  delay(200);
  }
}

void setup() {
  gate.attach(6);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN,  OUTPUT);
  gate.write(0);
  Serial.begin(9600);
}

void loop() {
  long dist = getDistance();
  Serial.print("Distance: "); Serial.println(dist);

  if (dist < THRESHOLD_CM && !gateOpen) {
    gateOpen = true;
    Serial.println("Vehicle detected! Opening gate...");
    gate.write(90);
    blinkLED(5000);

    long clearCheck = getDistance();
    if (clearCheck > THRESHOLD_CM) {
      Serial.println("Path clear. Closing gate.");
      gate.write(0);
      digitalWrite(LED_PIN, LOW);
      gateOpen = false;
    } else {
      Serial.println("Path blocked! Gate stays open.");
    }
  }
  delay(300);
}