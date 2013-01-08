#include "TheramicTone.h"

void TheramicTone::init() {
  _tone.begin(PIN_SOUND_OUTPUT);
  _sharpIr.init(PIN_INSTRUMENT);

  /* Store values for better managment  */
  _note_leds[DO] = PIN_LED_DO;
  _note_leds[RE] = PIN_LED_RE;
  _note_leds[MI] = PIN_LED_MI;
  _note_leds[FA] = PIN_LED_FA;
  _note_leds[SOL] = PIN_LED_SOL;
  _note_leds[LA] = PIN_LED_LA;
  _note_leds[SI] = PIN_LED_SI;

  _octave_leds[OCTAVE_1] = PIN_OCTAVE_1;
  _octave_leds[OCTAVE_2] = PIN_OCTAVE_2;
  _octave_leds[OCTAVE_3] = PIN_OCTAVE_3;
  _octave_leds[OCTAVE_4] = PIN_OCTAVE_4;
  _octave_leds[OCTAVE_5] = PIN_OCTAVE_5;

  /* Turn off all LED  */
  for (int i = 0; i < NOTE_COUNT; i++) {
    pinMode(_note_leds[i], OUTPUT);
    digitalWrite(_note_leds[i], LOW);
  }

  for (int i = 0; i < OCTAVE_COUNT; i++) {
    pinMode(_octave_leds[i], OUTPUT);
    digitalWrite(_octave_leds[i], LOW);
  }

}

int TheramicTone::distanceToNote(int d) {
  int note;

  if (d < MIN_DIST) {
    note = DO;
  } else if (d > MAX_DIST) {
    note = NOTHING;
  } else {
    note = ((d - MIN_DIST) / NOTE_DIST) + 1;
  }
  Serial.print("note: ");
  Serial.println(note);

  return note;
}

int TheramicTone::checkBeatSelector() {
  int raw; 
  raw = analogRead(PIN_BEAT_SELECTOR);

  Serial.print("beatselector: ");
  Serial.println(raw);

  Serial.print("bpm: ");
  if (raw < BEAT_NEVER_TH) {
    Serial.print("(BEAT_NEVER) ");
    _bpm = BEAT_NEVER;
  } else if (raw > BEAT_ALWAYS_TH) {
    Serial.print("(BEAT_ALWAYS) ");
    _bpm = BEAT_ALWAYS;
  } else {
    _bpm = raw>>2; // from BEAT_NEVER_TH - 255 is a boot beat per minute range
  }

  Serial.println(_bpm);

  return _bpm; /* Probabily not needed */
}

int TheramicTone::beat() {
  int raw;
  int pressed;
 
  raw = analogRead(PIN_BEAT);
 
  /* Button connected with high value by default, 0V when press */
  pressed = (raw > BEAT_TH) ? 0 : 1;

  Serial.print("beatbutton: ");
  Serial.println(pressed);

  if (_bpm == BEAT_NEVER) {
    return pressed;
  } else {
    /* If BEAT_ALWAYS act as always pressed, but stop beating when pressed.
     * Also when beating with a rythm button acts as a mute */
    return !pressed;
  }
}

int TheramicTone::getNote() {
  int d;

  d = _sharpIr.getDistance();
  Serial.print("dist: ");
  Serial.println(d);
  return distanceToNote(d);
}

int TheramicTone::getOctave() {
  int raw;
  int octave;
  raw = analogRead(PIN_OCTAVE_SELECTOR);

  Serial.print("octave_selector: ");
  Serial.println(raw);

  /* 1023 shifted 7 is 3 bits 0-7 */
  octave = raw>>7;
 
  /* If bigger than octave count truncate the biggest value */ 
  if (octave > OCTAVE_COUNT-1) octave = OCTAVE_COUNT-1;

  for (int i = 0; i < OCTAVE_COUNT; i++) {
    digitalWrite(_octave_leds[i], LOW);
  }
  digitalWrite(_octave_leds[octave], HIGH);

  Serial.print("octave: ");
  Serial.println(octave);

  return octave;
}

int TheramicTone::play(int octave, int note) {


  Serial.print("play: ");

//  if (octave == _current_octave && note == _current_note) {
//    /* Do not put any tone, its already playing */
//    return 0;
//  }
  
  if (note < MIN_NOTE or note > MAX_NOTE) {
    /* Incorrect note */
    Serial.println("Incorrect Note");
    mute();
    return 0;
  }
  if (octave < MIN_OCTAVE or octave > MAX_OCTAVE) {
    Serial.println("Incorrect Octave");
    mute();
    return 0;
  }

  Serial.print(octave);
  Serial.print(" : ");
  Serial.print(note);
  Serial.println("");

  _current_octave = octave;
  _current_note = note;
  _tone.play(_octaves[octave][note]);

  for (int i = 0; i < NOTE_COUNT; i++) {
     digitalWrite(_note_leds[i], LOW);
  }
  digitalWrite(_note_leds[note], HIGH);
}

int TheramicTone::rawPlay(int note) {
  _tone.play(note);
}


void TheramicTone::mute() {
  Serial.println("MUTE");
  for (int i = 0; i < NOTE_COUNT; i++) {
     digitalWrite(_note_leds[i], LOW);
  }
  _tone.stop();
}

void TheramicTone::wait() {
  int lapse;

  Serial.print("wait: ");
  /* BEAT NEVER wait also uses BEAT_ALWAYS_DELAY, difference in preeed button value
   * (see func beat) */
  if (_bpm == BEAT_ALWAYS or _bpm == BEAT_NEVER) {
   Serial.print("BEAT_ALWAYS ");
   Serial.println(BEAT_ALWAYS_DELAY); 
   delay(BEAT_ALWAYS_DELAY);     
  } else {
    lapse = MINUTE_DELAY/_bpm;
    Serial.println(lapse);
    delay(lapse);
  }
}


