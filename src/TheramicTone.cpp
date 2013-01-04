#include "TheramicTone.h"

void TheramicTone::init() {
  _tone.begin(SOUND_OUTPUT);
  _sharpIr.init(PIN_INSTRUMENT);

  /* Store values for better managment  */
  _leds[DO] = PIN_LED_DO;
  _leds[DO_S] = PIN_LED_DO_S;
  _leds[RE] = PIN_LED_RE;
  _leds[RE_S] = PIN_LED_RE_S;
  _leds[MI] = PIN_LED_MI;
  _leds[FA] = PIN_LED_FA;
  _leds[FA_S] = PIN_LED_FA_S;
  _leds[SOL] = PIN_LED_SOL;
  _leds[SOL_S] = PIN_LED_SOL_S;
  _leds[LA] = PIN_LED_LA;
  _leds[LA_S] = PIN_LED_LA_S;
  _leds[SI] = PIN_LED_SI;

  /* Turn off all LED  */
  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(_leds[i], OUTPUT);
    digitalWrite(_leds[i], LOW);
  }

}

int TheramicTone::distanceToNote(int d) {
  int note;

  if (d < MIN_DIST) {
    note = DO;
  } else if (d > MAX_DIST) {
    note = SI;
  } else {
    note = ((d - MIN_DIST) / NOTE_DIST) + 1;
  }
  Serial.print("note: ");
  Serial.println(note);

  return note;
}

int TheramicTone::beat() {
  int raw;
  raw = analogRead(PIN_BEAT);
  return (raw > BEAT_TH) ? 1 : 0;
}

int TheramicTone::getNote() {
  int d;

  d = _sharpIr.getDistance();
  Serial.print("Disntace value: ");
  Serial.println(d);
  return distanceToNote(d);
}

int TheramicTone::play(int octave, int note) {

  if (octave == _current_octave && note == _current_note) {
    /* Do not put any tone, its already playing */
    return 0;
  }

  _current_octave = octave;
  _current_note = note;
  _tone.play(_octaves[octave][note]);
  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(_leds[i], LOW);
  }
  digitalWrite(_leds[note], HIGH);
}

int TheramicTone::rawPlay(int note) {
  _tone.play(note);
}


void TheramicTone::mute() {
  _tone.stop();
}

void TheramicTone::wait() {
  //TODO sleep until change
  delay(100);
}

