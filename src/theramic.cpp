#include <Arduino.h>
#include "TheramicTone.h"

TheramicTone thrmc;
int octave;
int note;

void setup() {
  Serial.begin(9600);              
  thrmc.init();
}

void loop() {

  thrmc.checkBeatSelector();

  if (thrmc.beat()) {
    note = thrmc.getNote();
    octave = thrmc.getOctave();
    thrmc.play(octave, note);      
  } else {
    thrmc.mute();
  }

  thrmc.wait();    

  Serial.println("--------------------");

}

