/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2. Stores last state in EEPROM.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

*/
#include <MemoOutputPin.h>
#include <EEPROM.h>

#define EEPROM_SIZE 1

MemoOutputPin light;

const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
const int light_address = 1;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  EEPROM.begin(EEPROM_SIZE);
  // initialize the LED pin as an output:
  light.attach(ledPin, light_address);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    light.On();
    // or can use light.write(255); or light.write(255/2) for halth strength.
  } else {
    // turn LED off:
    light.Off():
  }
}