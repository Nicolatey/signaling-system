#include <Arduino.h>

const byte potentio = A0;
const int redLed = 3;
const int greenLed = 2;
const int buzzer = 4;

int potValue = 0;
int ledBrightness = 0;

void setup() {
  Serial.begin(9600);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(potentio, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // digitalWrite(redLed, HIGH);
  // delay(200);
  // digitalWrite(redLed, LOW);
  // delay(200);
  // digitalWrite(greenLed, HIGH);
  // delay(200);
  // digitalWrite(greenLed, LOW);
  // delay(200);

  potValue = analogRead(potentio);
  Serial.println(potValue);

  ledBrightness = map(potValue, 0, 1023, 0, 255);
  analogWrite(redLed, ledBrightness);

  tone(buzzer, 1000);
}