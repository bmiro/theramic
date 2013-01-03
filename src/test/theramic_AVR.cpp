
/* Thanks to https://github.com/damellis/ for interrupt code */

#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>

#include "Arduino.h"

#define BEAT_PIN A0
#define NOTE_PIN A2

#define PWM_OUT  11

#define SAMPLE_RATE 8000

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

#define DELAY 100

#define NOTE_MAX 7
int dist2note[NOTE_MAX];

int note_raw;
int beat_raw;

int note, last_note;

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

void init_isr() {
    ASSR &= ~(_BV(EXCLK) | _BV(AS2));
  
    // Set fast PWM mode (p.157)
    TCCR2A |= _BV(WGM21) | _BV(WGM20);
    TCCR2B &= ~_BV(WGM22);
  
    // Do non-inverting PWM on pin OC2A (p.155)
    // On the Arduino this is pin 11.
    TCCR2A = (TCCR2A | _BV(COM2A1)) & ~_BV(COM2A0);
    TCCR2A &= ~(_BV(COM2B1) | _BV(COM2B0));
  
    // No prescaler (p.158)
    TCCR2B = (TCCR2B & ~(_BV(CS12) | _BV(CS11))) | _BV(CS10);
  
    // Set initial pulse width to the first sample.
    OCR2A = pgm_read_byte(&sounddata_data[0]);
  
  
    // Set up Timer 1 to send a sample every interrupt.
  
    cli();
  
    // Set CTC mode (Clear Timer on Compare Match) (p.133)
    // Have to set OCR1A *after*, otherwise it gets reset to 0!
    TCCR1B = (TCCR1B & ~_BV(WGM13)) | _BV(WGM12);
    TCCR1A = TCCR1A & ~(_BV(WGM11) | _BV(WGM10));
  
    // No prescaler (p.134)
    TCCR1B = (TCCR1B & ~(_BV(CS12) | _BV(CS11))) | _BV(CS10);
  
    // Set the compare register (OCR1A).
    // OCR1A is a 16-bit register, so we have to do this with
    // interrupts disabled to be safe.
    OCR1A = F_CPU / SAMPLE_RATE; // 16e6 / 8000 = 2000
  
    // Enable interrupt when TCNT1 == OCR1A (p.136)
    TIMSK1 |= _BV(OCIE1A);
    sei();
}

void setup() {                
    Serial.begin(9600);
    init_note_distances();
    init_isr();
}

void loop() {
    note_raw = analogRead(NOTE_PIN);
    beat_raw = analogRead(BEAT_PIN);
    
    note = dist2note(distance(note_raw));
    if (beat_raw > BEAT_TH) {
        if (note != last_note) {
            last_note = note;
            play(note);
        }
    }

    if (DELAY) {
        delay(DELAY);
    }
}
