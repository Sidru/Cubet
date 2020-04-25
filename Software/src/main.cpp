#include <Arduino.h>
#include <ArduinoLog.h>

#include <configuration.h>
#include <cube.h>
#include <draw.h>
#include <animations.h>

/* These functions were used to test the Board */
static inline void toggle_led_debug(void);
static inline void init_led_debug(void);

cCube Cubet;
cDraw Draw;

void setup()
{
    Serial.begin(115200);
    Serial.println("Hello World");
    Log.begin(LOG_LEVEL_VERBOSE, &Serial);

    init_led_debug();

    Cubet.begin();
    Draw.begin(&Cubet);
}


void loop()
{
    static unsigned long start_millis = millis();
    static unsigned long change_millis = millis();
    static uint8_t animNr = 0; 

    toggle_led_debug();
    //Cubet.test_layer();
    
    if((millis() - start_millis) >= 75)   
    {
        start_millis = millis();

        switch(animNr)
        {
            case 0:
                effect_rain(&Draw, 0); 
                break;
            case 1:
                effect_wormsqueeze (&Draw, 2, AXIS_X, -1, 100, 1000);
                break;
            case 2:
                sinelines(&Draw, 4000, 100);
                break;
            case 3:
                side_ripples(&Draw, 300, 75);
                break;
            case 4:
                effect_random_sparkle(&Draw);
                break;
            case 5:
                mirror_ripples(&Draw, 600, 75);
                break;
            case 6:
                linespin(&Draw, 1500, 50);
                break;
            case 7:
                effect_planboing(&Draw, AXIS_X, 75);
                break;
            case 8:
                effect_planboing(&Draw, AXIS_Y, 75);
                break;
            case 9:
                effect_planboing(&Draw, AXIS_Z, 75);
                break;
            case 10:
                effect_rand_patharound(&Draw, 200, 75);
                break;

            default:
                animNr = 0;
                break;
        }
    }

    if((millis() - change_millis) > 10000)
    {
        change_millis = millis();
        animNr++;
    }

//if((millis() - start_millis) >= 75)   
    //{
    //    start_millis = millis();
    //    
    //    //effect_rain(&Draw, 0); 
    //    //effect_wormsqueeze (&Draw, 2, AXIS_X, -1, 100, 1000);
    //    //sinelines(&Draw, 4000, 100);
    //    //side_ripples(&Draw, 300, 75);
    //    //effect_random_sparkle(&Draw);
    //    //mirror_ripples(&Draw, 600, 75);
    //    //linespin(&Draw, 1500, 50);
    //    //effect_planboing(&Draw, AXIS_X, 75);
    //    //effect_planboing(&Draw, AXIS_Y, 75);
    //    //effect_planboing(&Draw, AXIS_Z, 75);
    //    effect_rand_patharound(&Draw, 200, g5);
    //}
    Cubet.refresh();
    ////cube_test_layer();
    ////cube_refresh();
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
