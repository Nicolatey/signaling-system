#include <Arduino.h>

const int buzzer = 3;
const int redLed = 4; 
const int greenLed = 5; 
const int buttonK1 = 8;
const int buttonK2 = 9;
// const int microphone = ;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buttonK1, INPUT);
  pinMode(buttonK2, INPUT);
  // pinMode(microphone, );
}

void loop() {
  // put your main code here, to run repeatedly:
}