#include <Arduino.h>
#include <configuration.h>
#include <shift_register_hal.h>

#include <SPI.h>
#include <wiring_private.h> // For the pinPeripheral() function.


#ifdef SHIFT_SPI
SPIClass mySPI (&sercom1, 12, 13, 11, SPI_PAD_0_SCK_1, SERCOM_RX_PAD_3);
#endif

void shift_hal_init(void)
{
#ifdef SHIFT_SOFTWARE
    pinMode(SHIFT_DATA_PIN, OUTPUT);
    pinMode(SHIFT_CLK_PIN, OUTPUT);
    pinMode(SHIFT_LATCH_PIN, OUTPUT);
#else
    #ifdef SHIFT_SPI
    Serial.println("Using SPI");
    mySPI.begin();
    // SERCOM for the SPI Pins
    pinPeripheral(11, PIO_SERCOM);
    pinPeripheral(12, PIO_SERCOM);
    pinPeripheral(13, PIO_SERCOM);
    mySPI.beginTransaction(SPISettings(40000000UL, MSBFIRST, SPI_MODE0));
    pinMode(SHIFT_LATCH_PIN, OUTPUT);
    #endif
#endif
}

void shift_array_hal(uint8_t* data, uint32_t size)
{
    uint8_t i = 0;
#ifdef SHIFT_SOFTWARE   
    for(i = 0; i < size; i++)
    {
        shiftOut(SHIFT_DATA_PIN, SHIFT_CLK_PIN, MSBFIRST, data[i]);
    }
#else 
    #ifdef SHIFT_SPI
    for(i = 0; i < size; i++)
    {
        mySPI.transfer(data[i]);
    }
    //mySPI.transfer(data, size);
    //mySPI.endTransaction();
    #endif
#endif
}

void shift_latch_hal(uint8_t state)
{
    digitalWrite(SHIFT_LATCH_PIN, state);
}
