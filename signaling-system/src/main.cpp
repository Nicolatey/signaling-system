#include <Arduino.h>

// Pin definitions
const byte potPin = A1;
const byte micAnalogPin = A0;
const int redLed = 1;
const int blueLed = 2;
const int orangeLed = 3;
const int yellowLed = 4;
const int greenLed = 5;
const int whiteButton = 6;
const int blackButton = 7;

// Variable definitions
int percent;
int potValue = 0;
int userInput;
int whiteButtonState;
int blackButtonState;
float micAnalogValue;

// Enum variable
enum ledOptions {
  on,
  off, 
  blink,
  lightshow
};

// Setup
void setup() {
  pinMode(potPin, INPUT);
  pinMode(micAnalogPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(orangeLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(whiteButton, INPUT_PULLUP);  
  pinMode(blackButton, INPUT_PULLUP);
  Serial.begin(9600);
}

// als userInput als string in een enum als een numerieke waarde wordt vastgelegd en deze 
// enum als parameter van een functie meegegeven kan worden gebruikt dan is het mogelijk om 
// een switch case te gebruiken als check functie

void remoteControlPicker(enum ledOptions) {
  ledOptions filter = ledOptions::on;
  switch (filter)
  {
  case ledOptions::on:
    return digitalWrite(blueLed, HIGH);
    break;
  case ledOptions::off:
    return digitalWrite(blueLed, LOW);
    break;
  case ledOptions::blink:
    digitalWrite(blueLed, HIGH);
    delay(100);
    digitalWrite(blueLed, LOW);
    delay(100);
    break;
  case ledOptions::lightshow:
    Serial.println("Coming soon!");
    break;
  default:
    break;
  }
  // if (userInput == "aan") {
  //   digitalWrite(blueLed, HIGH);
  // }
  // if (userInput == "uit") {
  //   digitalWrite(blueLed, LOW);
  // }
  // if (userInput == "knipper") {
  //   digitalWrite(blueLed, HIGH);
  //   delay(100);
  //   digitalWrite(blueLed, LOW);
  //   delay(100);
  // }
}

void loop() {
  // Black button pressed = blue led on
  // if (blackButton == HIGH) {
  //   digitalWrite(blueLed, HIGH);
  // } else {
  //   digitalWrite(blueLed, LOW);
  // }

// Blue led on = enabled remote control 

  if (Serial.available() > 0 ) {
    char received = Serial.read();
    Serial.println(received);
    // Keeps adding up characters until the user hits "Enter", then it checks the type of input and executes the remoteControlPicker() function. 
    if (received == '\n') {
      Serial.println("Arduino recieved: " + userInput);
      Serial.println("Hello" == "Hello");
      if (userInput == 1) {
        digitalWrite(blueLed, HIGH);
        remoteControlPicker(on);
      } else if (userInput == 2) {
        digitalWrite(blueLed, LOW);
        // remoteControlPicker(off);
      } else if (userInput == 3) {
        remoteControlPicker(blink);
      } else if (userInput == 4) {
        remoteControlPicker(lightshow);
      } else {
        digitalWrite(blueLed, HIGH);
      }
      userInput = 0;
    } else {
      userInput += received;
    }
  }

  // BASICS -----------------------------------------------------
  // micAnalogValue = analogRead(micAnalogPin);
  // micDigitalValue = digitalRead(micDigitalPin);
  // micAnalogValue = micAnalogValue * (100.0 / 1023.0);
  // blackButtonState = digitalRead(blackButton);
  // potValue = analogRead(potPin);
  // percent = map(potValue, 0, 1023, 0, 100);
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
  // if (buttonState == HIGH) {
  //   redLedBlink();
  // } else {
  //   digitalWrite(redLed, LOW);
  // }
  // ------------------------------------------------------------

  // SERIAL -----------------------------------------------------
  // if (Serial.available() > 0 ) {
  //   char recieved = Serial.read();
  //   if (recieved == '\n') {
    //   Serial.println("Arduino Received: " + userInput);
    //   if (userInput = "aan") {
    //     digitalWrite(greenLed, HIGH);
    //   } else if (userInput = "uit") {
    //     digitalWrite(greenLed, LOW);
    //   }
    //   userInput = "";
    // } else {
    //   userInput += recieved;
  //   }
  // }
  // ------------------------------------------------------------
}