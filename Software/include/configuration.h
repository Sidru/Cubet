#ifndef CONFIGURATION_H
#define CONFIGURATION_H

/* PINS */
#define DEBUG_LED_PIN   19  // PIN_PB02 -> 19 for Arduino
#define BUTTON_PIN      2   // PIN_PA14 -> 2 for Arduino
#define SHIFT_DATA_PIN  11  // PIN_PA16 -> 11 for Arduino
#define SHIFT_CLK_PIN   13  // PIN_PA17 -> 13 for Arduino
#define SHIFT_LATCH_PIN 10  // PIN_PA18 -> 10 for Arduino

#define SHIFT_READ_PIN  9   // PIN_PA07 -> 9 for Arduino. Not used, only to test the Shifty library


/* CUBE */
#define SIZE_OF_X 8
#define SIZE_OF_Y 8
#define SIZE_OF_Z 8

#define FRAMES_PER_SECOND   25
#define PWM_RESOLUTION      32 
//#define PWM


//#define SHIFT_SOFTWARE
#define SHIFT_SPI
//#define SHIFT_SPI_DMA
//
#endif
