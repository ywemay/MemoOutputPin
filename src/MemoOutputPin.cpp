#include "MemoOutputPin.h"
#include <EEPROM.h>

#define ON 255
#define OFF 0

MemoOutputPin::MemoOutputPin() {}

void MemoOutputPin::attach(int pin, int address) {
  _pin = pin;
  _address = address;
  pinMode(_pin, OUTPUT);
  delay(10);
  analogWrite(_pin, EEPROM.read(_address));
}

void MemoOutputPin::write(int state) {
  analogWrite(_pin, state < 256 && state >=0 ? state : 0);
  EEPROM.write(_address, state); // Store the state in EEPROM
  EEPROM.commit();
}

void MemoOutputPin::On() {
  write(ON);
}

void MemoOutputPin::Off() {
  write(OFF);
}

bool MemoOutputPin::read() {
  return (EEPROM.read(_address));
}