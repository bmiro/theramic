/* Send sensor value to the serial port */
/* Test to send values to USB using serial interface */
 
#include "Arduino.h"

#define PIN_BEAT A0
#define PIN_PROX A2

int beat_in;
int prox_in;

void setup() {                
    Serial.begin(9600);
}

void loop() {
    beat_in = analogRead(PIN_BEAT);
    Serial.println(beat_in);


    if (beat_in > 550 and beat_in < 700) {
        Serial.println("do");
    } else if (beat_in > 450  and beat_in < 550) {
        Serial.println("re");
    } else if (beat_in > 400  and beat_in < 450) {
        Serial.println("mi");
    } else if (beat_in > 350 and beat_in < 400) {
        Serial.println("fa");
    } else if (beat_in > 300 and beat_in < 350) {
        Serial.println("sol");
    } else if (beat_in > 200 and beat_in < 300) {
        Serial.println("la");
    } else if (beat_in > 100 and beat_in < 200) {
        Serial.println("si");
    } else if (beat_in > 0 and beat_in < 100) {
        Serial.println("up_do");
    }else {
        Serial.println("UNK");
    } 





    delay(500);
}
