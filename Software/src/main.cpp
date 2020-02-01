/*
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */

#include <Arduino.h>

#define DEBUG_PIN 19 
//#define DEBUG_PIN PIN_PB02
//
void setup()
{
  //  while(!Serial);
  // initialize LED digital pin as an output.
  pinMode(DEBUG_PIN, OUTPUT);
}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(DEBUG_PIN, HIGH);
  // wait for a second
  delay(1000);
  // turn the LED off by making the voltage LOW
  digitalWrite(DEBUG_PIN, LOW);
   // wait for a second
  delay(1000);
}
