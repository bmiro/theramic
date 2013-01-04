#ifndef _Theramic_tone_h
#define _Theramic_tone_h

#include <Arduino.h>
#include "Tone.h" 
#include "SharpIR.h"

#define OCTAVE_COUNT   7
#define NOTE_COUNT    12
#define LED_COUNT     NOTE_COUNT


/******** Hardware PINS *********/
#define PIN_LED_DO     13  /* 0 is giving problems */
#define PIN_LED_RE     1
#define PIN_LED_MI     2 
#define PIN_LED_FA     3
#define PIN_LED_SOL    4
#define PIN_LED_LA     5
#define PIN_LED_SI     6

#define PIN_LED_DO_S   7
#define PIN_LED_RE_S   8
#define PIN_LED_FA_S   9
#define PIN_LED_SOL_S 10
#define PIN_LED_LA_S  12

/* Arduino UNO: 11 is a PWM pin */
#define SOUND_OUTPUT  11

#define PIN_INSTRUMENT      A0
#define PIN_OCTAVE_SELECTOR A1
#define PIN_DISTORSION      A2
#define PIN_BEAT            A3

/** Some musical defines  **/
#define DO    0
#define DO_S  1
#define RE    2
#define RE_S  3
#define MI    4
#define FA    5
#define FA_S  6
#define SOL   7
#define SOL_S 8
#define LA    9
#define LA_S 10 
#define SI   11

#define OCTAVE_1 0
#define OCTAVE_2 1
#define OCTAVE_3 2
#define OCTAVE_4 3
#define OCTAVE_5 4
#define OCTAVE_6 5
#define OCTAVE_7 6

#define BEAT_TH 200

#define MAX_DIST 600 /* in mm */
#define MIN_DIST 100 /* in mm */
#define NOTE_DIST ((MAX_DIST-MIN_DIST)/NOTE_COUNT) /* Distance for each note */


class TheramicTone {
  public:

    void init();
    int beat();
    void mute();
    int getNote();
    int rawPlay(int note);
    int play(int octave, int note);
    void wait();

  private:
    int _octaves[OCTAVE_COUNT][NOTE_COUNT] =
  /*       DO       DO#       RE       RE#       MI       FA       FA#      SOL       SOL#      LA       LA#       SI */
    {{NOTE_C1, NOTE_CS1, NOTE_D1, NOTE_DS1, NOTE_E1, NOTE_F1, NOTE_FS1, NOTE_G1, NOTE_GS1, NOTE_A1, NOTE_AS1, NOTE_B1},
     {NOTE_C2, NOTE_CS2, NOTE_D2, NOTE_DS2, NOTE_E2, NOTE_F2, NOTE_FS2, NOTE_G2, NOTE_GS2, NOTE_A2, NOTE_AS2, NOTE_B2},
     {NOTE_C3, NOTE_CS3, NOTE_D3, NOTE_DS3, NOTE_E3, NOTE_F3, NOTE_FS3, NOTE_G3, NOTE_GS3, NOTE_A3, NOTE_AS3, NOTE_B3},
     {NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4, NOTE_B4},
     {NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_AS5, NOTE_B5},
     {NOTE_C6, NOTE_CS6, NOTE_D6, NOTE_DS6, NOTE_E6, NOTE_F6, NOTE_FS6, NOTE_G6, NOTE_GS6, NOTE_A6, NOTE_AS6, NOTE_B6},
     {NOTE_C7, NOTE_CS7, NOTE_D7, NOTE_DS7, NOTE_E7, NOTE_F7, NOTE_FS7, NOTE_G7, NOTE_GS7, NOTE_A7, NOTE_AS7, NOTE_B7}
    };

    Tone _tone;
    SharpIR _sharpIr;

    int _leds [LED_COUNT];
    int _current_note;
    int _current_octave;
    int _note_position[NOTE_COUNT];
    
    int distanceToNote(int d);

};  
#endif

