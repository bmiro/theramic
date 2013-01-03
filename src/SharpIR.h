#include <Arduino.h>

#ifndef _sharp_ir_h
#define _sharp_ir_h

class SharpIR
{
  public:
    void init(int sensorPin);
    int getDistance();

  private:
    int _pin;

};

#endif
