#ifndef _MEMO_OUTPUT_PIN_H
#define _MEMO_OUTPUT_PIN_H

#include <Arduino.h>

class MemoOutputPin {
public:
  MemoOutputPin();
  void attach(int pin, int address);
  void write(int state);
  void On();
  void Off();
  bool read();

private:
  int _pin;
  int _address;
};

#endif // _MEMO_OUTPUT_PIN_H