#include <Arduino.h>

const byte potPin = A1;
const byte micAnalogPin = A0;
const int micDigitalPin = 7;
const int redLed = 3;
const int greenLed = 2;
const int buzzer = 9;
const int button = 5;

float decibel;
int percent;
String userInput;
int buttonState;
int potValue = 0;
float micAnalogValue;
int micDigitalValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(micAnalogPin, INPUT);
  pinMode(micDigitalPin, INPUT);
  pinMode(potPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void redLedBlink() {
  digitalWrite(redLed, HIGH);
  delay(100);
  digitalWrite(redLed, LOW);
  delay(100);
}

void loop() {
  // BASICS -----------------------------------------------------
  // micAnalogValue = analogRead(micAnalogPin);
  // micDigitalValue = digitalRead(micDigitalPin);
  // micAnalogValue = micAnalogValue * (100.0 / 1023.0);
  buttonState = digitalRead(button);
  potValue = analogRead(potPin);
  percent = map(potValue, 0, 1023, 0, 100);
  // ------------------------------------------------------------

  // BUZZER -----------------------------------------------------
  // noTone(buzzer);
  // digitalWrite(buzzer, LOW);
  // analogWrite(buzzer, 0);
  // tone(buzzer, 0);
  // tone(buzzer, 1000);
  // if (percent > 50) {
  //   noTone(buzzer);
  // }
  // delay(500);
  // Serial.println(buzzer);
  // Serial.println(percent);
  // ------------------------------------------------------------

  // LED --------------------------------------------------------
  // digitalWrite(redLed, HIGH);
  // digitalWrite(greenLed, HIGH);
  // ------------------------------------------------------------
  
  // MIC --------------------------------------------------------
  // Serial.print("Mic Analog: ");
  // Serial.print(micAnalogValue);
  // Serial.print(" Mic Digital: ");
  // Serial.println(micDigitalValue);
  // delay(200);
  // ------------------------------------------------------------

  // POTENTIO ---------------------------------------------------
  // Serial.print("Potentio Reading: ");
  // Serial.print(potValue);
  // Serial.println("Potentio Percentage: ");
  // Serial.print(percent);
  // ------------------------------------------------------------

  // BUTTON -----------------------------------------------------
  if (buttonState == HIGH) {
    redLedBlink();
  } else {
    digitalWrite(redLed, LOW);
  }
  // ------------------------------------------------------------

  // SERIAL -----------------------------------------------------
  if (Serial.available() > 0 ) {
    char recieved = Serial.read();
    if (recieved == '\n') {
      Serial.println("Arduino Received: " + userInput);
      if (userInput = "aan") {
        digitalWrite(greenLed, HIGH);
      } else if (userInput = "uit") {
        digitalWrite(greenLed, LOW);
      }
      userInput = "";
    } else {
      userInput += recieved;
    }
  }

  // ------------------------------------------------------------
}