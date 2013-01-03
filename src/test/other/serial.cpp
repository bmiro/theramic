/* Test to send values to USB using serial interface */
 
#include "Arduino.h"

#define PIN_AIN A0

int ain;

void setup() {                
    Serial.begin(9600);
}

void loop() {
    ain = analogRead(PIN_AIN);
    Serial.println(ain);
    delay(1000);
}
