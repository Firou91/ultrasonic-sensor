#include "config.h"

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

int measureDistance() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration * 0.034 / 2; // Conversion en cm
  return distance;
}

void loop() {
  int distance = measureDistance();

  if (distance >= 300) {
      noTone(BUZZER_PIN);
      Serial.println("DISTANCE SUPERIEUR A 3M");
      Serial.println(distance);
      delay(500);
  } else if (distance <= 300 & distance >=150) {
    // Émettre un bip court
    tone(BUZZER_PIN, frequency);
    delay(800);
    noTone(BUZZER_PIN);
    delay(800);
    Serial.println("DISTANCE ENTRE 3M ET 1,5M");
    Serial.println(distance);
  } else if (distance <= 150 & distance >=100) {
    // Émettre un bip très court
    tone(BUZZER_PIN, frequency);
    delay(400);
    noTone(BUZZER_PIN);
    delay(400);
    Serial.println("DISTANCE ENTRE 1,5M ET 1M");
    Serial.println(distance);
  } else if (distance <= 150 & distance >=100) {
    // Émettre un bip constant
    tone(BUZZER_PIN, frequency);
    delay(100);
    noTone(BUZZER_PIN);
    delay(100);
    Serial.println("DISTANCE ENTRE 1,5M ET 1M");
    Serial.println(distance);  
  } else if (distance <= 100) {
    tone(BUZZER_PIN, frequency);
    Serial.println("DISTANCE INFERIEUR A 1M");
  }
}