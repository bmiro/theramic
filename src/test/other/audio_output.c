/* Test to send analog audio tought the Jack  */
/* Test to send values to USB using serial interface */
 
#include "Arduino.h"

Tone tone;

int note [] = {NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4, NOTE_B4};

void setup() {                
    Serial.begin(9600);
    tone.begin(12);
}

void loop() {
    for (int i; i < 12; i++) {
        tone.play(note[i]);
        delay(1000);
    }
}
