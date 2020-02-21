/*
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */

#include <Arduino.h>
#include <ArduinoLog.h>
#include <Shifty.h>

#include <configuration.h>

#define SHIFTY_NR_BITS 72
Shifty shift;

void shift_init(void);
static void toggle_led_debug(void);
static void shift_test(void);

void shift_init(void)
{
    //shift.setBitCount(SHIFTY_NR_BITS); // 8x8 Columns and 8 Layers
    //shift.setPins(SHIFT_CLK_PIN, SHIFT_DATA_PIN, SHIFT_LATCH_PIN, SHIFT_READ_PIN);

    pinMode(SHIFT_DATA_PIN, OUTPUT);
    pinMode(SHIFT_CLK_PIN, OUTPUT);
    pinMode(SHIFT_LATCH_PIN, OUTPUT);
}


void toggle_led_debug(void) {
    static bool last = 0;
    static unsigned long start_millis = millis();
    
    if (digitalRead(BUTTON_PIN) == (bool)0) // Test the Board Button
    {
        if ((millis() - start_millis) >= 250)
        {
            start_millis = millis();
            last = !last;
            digitalWrite(DEBUG_LED_PIN, (bool)last);
        }

    }
    else if ((millis() - start_millis) >= 1000)
    {
        start_millis = millis();
        last = !last;
        digitalWrite(DEBUG_LED_PIN, (bool)last);
    }
}

void shift_test(void)
{
    static unsigned long start_millis = millis();
    static uint32_t cnt = 1; 
    uint32_t i = 0;

    if ((millis() - start_millis) >= 100)
    {
        start_millis = millis();
        
        if (cnt >= 256)
        {
            cnt = 0;
        }
        digitalWrite(SHIFT_LATCH_PIN, LOW);
        shiftOut(SHIFT_DATA_PIN, SHIFT_CLK_PIN, MSBFIRST, cnt);
        digitalWrite(SHIFT_LATCH_PIN, HIGH);
        cnt++;
    }
}
void setup()
{
  // initialize LED digital pin as an output.
    pinMode(DEBUG_LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
    Serial.begin(115200);
    Serial.println("Hello World");
    Log.begin(LOG_LEVEL_VERBOSE, &Serial);
    shift_init();
}
void loop()
{
    toggle_led_debug();
    shift_test();
}
