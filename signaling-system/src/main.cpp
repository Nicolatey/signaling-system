#include <Arduino.h>

// const byte potentio = A1;
const int redLed = 3;
const int greenLed = 2;


void setup() {
  Serial.begin(9600);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  // pinMode(potentio, INPUT);
}

void loop() {
  digitalWrite(redLed, HIGH);
  delay(200);
  digitalWrite(redLed, LOW);
  delay(200);
  digitalWrite(greenLed, HIGH);
  delay(200);
  digitalWrite(greenLed, LOW);
  delay(200);
}