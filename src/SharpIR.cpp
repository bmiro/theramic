#include "SharpIR.h"

void SharpIR::init(int sensorPin) {
  _pin = sensorPin;
}

/* Return dinstance in mm */
int SharpIR::getDistance() {
//    double v, d;
//  v = analogRead(_pin) * 0.0048828125; /* 5 / 1024 */
//  d = 65 * pow(v, -1.1);
//
//
//  return (int)d;
  return INVERT_TH - analogRead(_pin);
}

