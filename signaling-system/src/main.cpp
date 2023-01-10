#include <Arduino.h>

const byte micPin = A0;
const byte potPin = A1;
const int redLed = 3;
const int greenLed = 2;
const int buzzer = 4;
const int button = 5;

// float decibel;
int percent;
int potValue = 0;
int micValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(micPin, INPUT);
  pinMode(potPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  potValue = analogRead(potPin);
  percent = map(potValue, 0, 1023, 0, 100);

  while (percent <= 50) {
    digitalWrite(redLed, HIGH);
  }
  
  // Serial.print("Potentio Reading: ");
  // Serial.print(potValue);
  Serial.print("Potentio Percentage: ");
  Serial.print(percent);
}