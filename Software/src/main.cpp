#include <Arduino.h>
#include <ArduinoLog.h>

#include <configuration.h>
#include <cube.h>


/* These functions were used to test the Board */
static inline void toggle_led_debug(void);
static inline void init_led_debug(void);


void setup()
{
    Serial.begin(115200);
    Serial.println("Hello World");
    Log.begin(LOG_LEVEL_VERBOSE, &Serial);

    init_led_debug();
    cube_init();
}


void loop()
{
    toggle_led_debug();
    cube_test();
    cube_refresh();
}    


void init_led_debug(void)
{
    // initialize LED digital pin as an output.
    pinMode(DEBUG_LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
}

void toggle_led_debug(void)
{
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
