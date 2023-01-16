#include <Arduino.h>

// Pin definitions
const byte potPin = A1;
const byte micAnalogPin = A0;
const int micDigitalPin = 9;
const int redLed = 8;
const int blueLed = 2;
const int orangeLed = 3;
const int yellowLed = 4;
const int greenLed = 5;
const int whiteButton = 6;
const int blackButton = 10;

// Variable definitions
int percent;
int potValue = 0;
String userInput;
bool lightShowActive;
int whiteButtonState;
int blackButtonState;
float micAnalogValue;
int micDigitalValue;

// Enum variable
enum ledOptions {
  on,
  off, 
  blink,
  lightshow
};

// Setup
void setup() {
  Serial.begin(9600);
  pinMode(potPin, INPUT);
  pinMode(micAnalogPin, INPUT);
  pinMode(micDigitalPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(orangeLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(whiteButton, INPUT_PULLUP);  
  pinMode(blackButton, INPUT_PULLUP);
  // attachInterrupt(digitalPinToInterrupt(blackButton), lightShow, CHANGE);
  Serial.println("Typ aan, uit, of knipper om de blauwe LED te bedienen");
}

void lightShow(){
  while (true) {
    int brightness1 = random(0,255);
    int brightness2 = random(0,255);
    int brightness3 = random(0,255);
    analogWrite(orangeLed, brightness1);
    analogWrite(yellowLed, brightness2);
    analogWrite(greenLed, brightness3);
    delay(300);
  }
}

// void lightShow() {
//   // if (digitalRead(blackButton) == LOW) {
//   //   lightShowActive = true;
//     while (lightShowActive) {
//         int brightness1 = random(0,255);
//         int brightness2 = random(0,255);
//         int brightness3 = random(0,255);
//         analogWrite(orangeLed, brightness1);
//         analogWrite(yellowLed, brightness2);
//         analogWrite(greenLed, brightness3);
//         delay(1000);
//     }
//   // }
//   // else {
//   //   lightShowActive = false;
//   // }
// }

// void lightShow() {
//   // if (digitalRead(blackButton) == LOW) {
//   //   lightShowActive = true;
//     while (lightShowActive) {
//         int brightness1 = random(0,255);
//         int brightness2 = random(0,255);
//         int brightness3 = random(0,255);
//         analogWrite(orangeLed, brightness1);
//         analogWrite(yellowLed, brightness2);
//         analogWrite(greenLed, brightness3);
//         delay(1000);
//     }
//   // }
//   // else {
//   //   lightShowActive = false;
//   // }
// }

// void buttonInterrupt(){
//   if (digitalRead(blackButton) == LOW) {
//     lightShowActive = true;
//     lightShow();
//   } else {
//     lightShowActive = false;
//   }
// }



void ledBlink() {
  digitalWrite(blueLed, HIGH);
  delay(100);
  digitalWrite(blueLed, LOW);
  delay(100);
  digitalWrite(blueLed, HIGH);
  delay(100);
  digitalWrite(blueLed, LOW);
  delay(100);
  digitalWrite(blueLed, HIGH);
  delay(100);
  digitalWrite(blueLed, LOW);
  delay(100);
}

// void remoteControlPicker(enum ledOptions) {
//   ledOptions filter = on;
//   switch (filter) {
//   case on:
//     digitalWrite(blueLed, HIGH);
//     break;
//   case off:
//     digitalWrite(blueLed, LOW);
//     break;
//   case blink:
//     ledBlink();
//     break;
//   case lightshow:
//     Serial.println("Coming soon!");
//     break;
//   default:
//     break;
//   }
// }

void ledControl(int choice) {
  switch (choice) {
  case 1:
    digitalWrite(blueLed, HIGH);
    break;
  case 2:
    digitalWrite(blueLed, LOW);
    break;
  case 3:
    ledBlink();
    break;
  default:
    break;
  }
}

void loop() {
  // BASICS -----------------------------------------------------
  micAnalogValue = analogRead(micAnalogPin) * (5.0 / 1023.0);
  micDigitalValue = digitalRead(micDigitalPin);
  blackButtonState = digitalRead(blackButton);
  potValue = analogRead(potPin);
  percent = map(potValue, 0, 1023, 0, 100);
  // ------------------------------------------------------------

  // BUTTON -----------------------------------------------------
  // If the black button is pressed, the lightshow turns on.
  if (blackButtonState == LOW) {
    if (!lightShowActive) {
      lightShow();
    }
  } else if (blackButtonState == HIGH) {
    lightShowActive = false;
  }
  // buttonInterrupt();

  // ------------------------------------------------------------

  // SERIAL -----------------------------------------------------
  
  // Attempt 1:
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

  // Attempt 2
  // if (Serial.available() > 0) {
  //   userInput = Serial.readStringUntil('\n');
  //   Serial.println("Arduino recieved: " + userInput);
  //   // Check the user's message based on this executes the remoteControlPicker() function or gives an error message. 
  //   if (userInput.equals("aan")) {
  //     remoteControlPicker(on);
  //     Serial.println(userInput);
  //     // digitalWrite(blueLed, HIGH);
  //   } else if (userInput.equals("uit")) {
  //     remoteControlPicker(off);
  //     Serial.println(userInput);
  //     // digitalWrite(blueLed, LOW);
  //   } else if (userInput.equals("knipper")) {
  //     remoteControlPicker(blink);
  //     Serial.println(userInput);
  //   } else if (userInput.equals("lichtshow")) {
  //     remoteControlPicker(lightshow);
  //   }
  //   userInput.trim();
  // }

  // Attempt 3:Remote control of the blue LED.
  if (Serial.available() > 0) {
    userInput = Serial.readStringUntil('\n');
    userInput.trim();
    Serial.println("Arduino recieved: " + userInput);
    // Check the user's message based on this executes the ledControl() function. 
    if (userInput.equals("aan")) {
      ledControl(1);
    } else if (userInput.equals("uit")) {
      ledControl(2);
    } else if (userInput.equals("knipper")) {
      ledControl(3);
    } else {
      Serial.println("Dit commando is onbekend.");
    }
  }
  // ------------------------------------------------------------

  // MIC --------------------------------------------------------
  if (micDigitalValue == 1) {
    digitalWrite(redLed, HIGH);
  } else {
    digitalWrite(redLed, LOW);
  }
  // ------------------------------------------------------------

  // POTENTIO ---------------------------------------------------
  // Serial.print("Potentio Percentage: ");
  // Serial.println(percent);
  int ledPins[] = {orangeLed, yellowLed, greenLed};

  if (percent < 30) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(ledPins[i], LOW);
    }
  } else {
    for (int i = 0; i < 3; i++) {
      if (percent >= (i + 1) * 30) {
        digitalWrite(ledPins[i], HIGH);
      } else {
        digitalWrite(ledPins[i], LOW);
      }
    }
  }
  // ------------------------------------------------------------
}