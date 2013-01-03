
/* Thanks to https://github.com/damellis/ for interrupt code */

#include "Arduino.h"
#include "Tone.h"

#define BEAT_PIN A0
#define NOTE_PIN A2

#define SOUND_OUT  11

/* #define OCTAVE_PIN TODO
#define VOLUME_PIN TODO
#define ESCALA?

#define DO_LED_PIN TODO
#define RE_LED_PIN TODO
#define MI_LED_PIN TODO
#define FA_LED_PIN TODO
#define SO_LED_PIN TODO
#define LA_LED_PIN TODO
#define SI_LED_PIN TODO
*/

#define NONE -1

#define DO  0
#define RE  1
#define MI  2
#define FA  3
#define SOL 4
#define LA  5
#define SI  6

#define NOTE_START_DIST 10
#define NOTES_DIST 7 

#define BEAT_TH 3

#define DELAY 1000

#define NOTE_MAX 7
int dist2note[NOTE_MAX];

int note_raw;
int beat_raw;

int note, last_note;

int notes[12];


int all_notes[] = {NOTE_B0, NOTE_C1,NOTE_CS1, NOTE_D1 , NOTE_DS1 , NOTE_E1, NOTE_F1, NOTE_FS1 , NOTE_G1, NOTE_GS1 , NOTE_A1, NOTE_AS1 , NOTE_B1, NOTE_C2, NOTE_CS2 , NOTE_D2, NOTE_DS2 , NOTE_E2, NOTE_F2, NOTE_FS2 , NOTE_G2, NOTE_GS2 , NOTE_A2, NOTE_AS2 , NOTE_B2, NOTE_C3, NOTE_CS3 , NOTE_D3, NOTE_DS3 , NOTE_E3, NOTE_F3, NOTE_FS3 , NOTE_G3, NOTE_GS3 , NOTE_A3, NOTE_AS3 , NOTE_B3, NOTE_C4, NOTE_CS4 , NOTE_D4, NOTE_DS4 , NOTE_E4, NOTE_F4, NOTE_FS4 , NOTE_G4, NOTE_GS4 , NOTE_A4, NOTE_AS4 , NOTE_B4, NOTE_C5, NOTE_CS5 , NOTE_D5, NOTE_DS5 , NOTE_E5, NOTE_F5, NOTE_FS5 , NOTE_G5, NOTE_GS5 , NOTE_A5, NOTE_AS5 , NOTE_B5, NOTE_C6, NOTE_CS6 , NOTE_D6, NOTE_DS6 , NOTE_E6, NOTE_F6, NOTE_FS6 , NOTE_G6, NOTE_GS6 , NOTE_A6, NOTE_AS6 , NOTE_B6, NOTE_C7, NOTE_CS7 , NOTE_D7, NOTE_DS7 , NOTE_E7, NOTE_F7, NOTE_FS7 , NOTE_G7, NOTE_GS7 , NOTE_A7, NOTE_AS7 , NOTE_B7, NOTE_C8, NOTE_CS8 , NOTE_D8, NOTE_DS8};

Tone tn;

/* Convert analog input to distance of the Sharp GP2Y0A02 */
float distance(int raw) {
    float v, d;
    v = raw * 0.0048828125; /* 5 / 1024 */
    d = 65 * pow(v, -1.1);
    return d; 
}

void play(int note) {
    /* Nothing only simbolic */
}

void init_note_distances() {
    for (int i; i < NOTE_MAX; i++) {
        dist2note[i] = NOTE_START_DIST + i * NOTES_DIST;
    } 
}


void setup() {                
    Serial.begin(9600);
    init_note_distances();
    tn.begin(11);
}

void loop() {
    note_raw = analogRead(NOTE_PIN);
    beat_raw = analogRead(BEAT_PIN);
    
//    note = dist2note[distance(note_raw)];
//    if (beat_raw > BEAT_TH) {
//        if (note != last_note) {
//            last_note = note;
//            tn.play(notes[note]);
//        }
//    } else {
//        tn.stop()
//    }

    for (int i = 0; i < 89; i++) {
        tn.play(all_notes[i]); 
        if (DELAY) {
            delay(DELAY);
        }
    }
}



