#ifndef _sharp_ir_h
#define _sharp_ir_h

#include <Arduino.h>

#define INVERT_TH 650

class SharpIR
{
  public:
    void init(int sensorPin);
    int getDistance();

  private:
    int _pin;

};

#endif
