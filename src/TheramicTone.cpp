#include "TheramicTone.h"

void TheramicTone::init() {
  tone.begin(SOUND_OUTPUT);

  pinMode(PIN_LED_DO, OUTPUT);
  pinMode(PIN_LED_RE, OUTPUT);
  pinMode(PIN_LED_MI, OUTPUT); 
  pinMode(PIN_LED_FA, OUTPUT);
  pinMode(PIN_LED_SOL, OUTPUT);
  pinMode(PIN_LED_LA, OUTPUT);
  pinMode(PIN_LED_SI, OUTPUT);
  pinMode(PIN_LED_DO_S, OUTPUT);
  pinMode(PIN_LED_RE_S, OUTPUT);
  pinMode(PIN_LED_FA_S, OUTPUT);
  pinMode(PIN_LED_SOL_S, OUTPUT);
  pinMode(PIN_LED_LA_S, OUTPUT);

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

}

int TheramicTone::distanceToNote(int d) {
  //TODO
}

int TheramicTone::beat() {
  raw = analogRead(PIN_BEAT);
  return (raw > BEAT_TH) ? 1 : 0;
}

int TheramicTone::getNote() {

}

void TheramicTone::play(int note, int octave) {
  _tone.play(_octaves[ocateve][note]);
  for (int i; i < LED_COUNT; i++) {
    digitalWrite(_leds[i], LOW);
  }
  digitalWrite(_leds[note], HIGH);
}

void TheramicTone::rawPlay(int note) {
  _tone.play(note);
}

void TheramicTone::mute() {
  _tone.stop();
}

void TheramicTone::wait() {
  //TODO sleep until change

}

