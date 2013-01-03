#include <Arduino.h>
#include "TheramicTone.h"

Theramic thrmc;
int octave;

void setup() {                
  thrmc.init();
  octave = 1;
}

void loop() {

  if (thrmc.beat()) {
    note = thrmc.getNote();
    thrmc.play(note, octave);      
  } else {
    thrmc.mute();
  }

  thrmc.wait();    

}

