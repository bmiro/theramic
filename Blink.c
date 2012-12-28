/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:

#include "Arduino.h"

int led0 = 0;
int led1 = 1;
int led2 = 2;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led0, OUTPUT);     
  pinMode(led1, OUTPUT);     
  pinMode(led2, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led0, HIGH); 
  delay(1000);              
  digitalWrite(led0, LOW); 
  delay(1000);              
  digitalWrite(led1, HIGH);
  delay(1000);              
  digitalWrite(led1, LOW); 
  delay(1000);              
  digitalWrite(led2, HIGH);
  delay(1000);              
  digitalWrite(led2, LOW);
  delay(1000);              
}
