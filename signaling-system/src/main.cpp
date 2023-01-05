#include <Arduino.h>

const byte micPin = A0;
const byte potPin = A1;
const int redLed = 3;
const int greenLed = 2;
const int buzzer = 4;

float decibel;
int percent;
int potValue = 0;
int micValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(micPin, INPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  micValue = analogRead(micPin);
  potValue = analogRead(potPin);
  percent = map(potValue, 0, 1023, 0, 100);

if (micValue >= 1023) {
    decibel = 130;
  } else {
    decibel = 20 * log10(micValue / 1023);
}

  Serial.print("Mic Reading: ");
  Serial.println(micValue);
  Serial.print("Decibel: ");
  Serial.println(decibel);
  delay(500);
  // Serial.print("Potentio Reading: ");
  // Serial.print(potValue);
  // Serial.print("Potentio Percentage: ");
  // Serial.print(percent);
}