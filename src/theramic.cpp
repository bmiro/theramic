#include <Arduino.h>
#include "TheramicTone.h"

TheramicTone thrmc;
int octave;
int note;

void setup() {
  Serial.begin(9600);              
  thrmc.init();
  octave = 3;
}

void loop() {

  if (thrmc.beat()) {
    note = thrmc.getNote();
    thrmc.play(octave, note);      
  } else {
    thrmc.mute();
  }

  thrmc.wait();    

}

