#include <Arduino.h>
#include <ArduinoLog.h> 
#include <configuration.h>
#include <shift_register_hal.h>

#include <SPI.h>
#include <wiring_private.h> // For the pinPeripheral() function.

#include <Adafruit_ZeroDMA.h>
#include <dma.h>

#if defined(SHIFT_SPI) || defined(SHIFT_SPI_DMA)
// Declare our own SPI peripheral 'mySPI' on pins 11/12/13:
// (Do not call this SPI1; Arduino Zero and Metro M0 already
// have an SPI1 (the EDBG interface) and it won't compile.)
SPIClass mySPI (
        &sercom1,           // -> Sercom periperhal
        12,                 // MISO pin
        13,                 // SCK pin 
        11,                 // MOSI pin 
        SPI_PAD_0_SCK_1,    // TX pad (MOSI, SCK pads) 
        SERCOM_RX_PAD_3);   // RX pad (MISO pad)

#endif

#ifdef SHIFT_SPI_DMA
Adafruit_ZeroDMA myDMA;
ZeroDMAstatus stat;

uint8_t source_memory[2][ARRAY_LAYER_SIZE];
uint8_t buffer_being_filled = 0;
volatile bool transfer_done = true;

void dma_callback(Adafruit_ZeroDMA *dma)
{
    transfer_done = true;
}

DmacDescriptor *desc; 
#endif

#ifdef SHIFT_SOFTWARE
static inline void local_shift_sw(uint8_t* data, uint32_t size);
#endif
#ifdef SHIFT_SPI
static inline void local_shift_spi(uint8_t* data, uint32_t size);
#endif
#ifdef SHIFT_SPI_DMA
static inline void local_shift_spi_dma(uint8_t* data, uint32_t size);
#endif
#ifdef SHIFT_SPI_DMA_TC
static inline void local_shift_spi_dma_tc(uint8_t* data, uint32_t size);
#endif


void shift_hal_init(void)
{
#ifdef SHIFT_SOFTWARE
    pinMode(SHIFT_DATA_PIN, OUTPUT);
    pinMode(SHIFT_CLK_PIN, OUTPUT);
    pinMode(SHIFT_LATCH_PIN, OUTPUT);
#else
    #if defined(SHIFT_SPI) || defined(SHIFT_SPI_DMA)
    Serial.println("Using SPI");
    mySPI.begin();
    // SERCOM for the SPI Pins
    pinPeripheral(11, PIO_SERCOM);
    pinPeripheral(12, PIO_SERCOM);
    pinPeripheral(13, PIO_SERCOM);
    mySPI.beginTransaction(SPISettings(10000000UL, MSBFIRST, SPI_MODE0));
    pinMode(SHIFT_LATCH_PIN, OUTPUT);
        #ifdef SHIFT_SPI_DMA
        myDMA.setTrigger(SERCOM1_DMAC_ID_TX);
        myDMA.setAction(DMA_TRIGGER_ACTON_BEAT);
        stat = myDMA.allocate();
        myDMA.printStatus(stat);
        desc = myDMA.addDescriptor(
            source_memory[buffer_being_filled], // move data from here
            (void *)(&SERCOM1->SPI.DATA.reg),   // to here
            ARRAY_LAYER_SIZE,                   // this many...
            DMA_BEAT_SIZE_BYTE,                 // bytes/hword/words
            true,                               // increment source addr?
            false);                             // increment dest addr? 
        myDMA.setCallback(dma_callback);
        #endif

    #endif
#endif
}

void print_data(uint8_t* data, uint32_t size)
{
    for(uint32_t i = 0; i < size; i ++)
    {
       Serial.print(data[i]);
    }
    Serial.println("");
}

void shift_array_hal(uint8_t* data, uint32_t size)
{
#ifdef SHIFT_SOFTWARE   
    local_shift_sw(data, size);
#else 
    #ifdef SHIFT_SPI
        local_shift_spi(data, size);
    #else 
        #ifdef SHIFT_SPI_DMA
            local_shift_spi_dma(data, size);
        #else
            #ifdef SHIFT_SPI_DMA_TC
                local_shift_spi_dma_tc(data, size);
            #endif
        #endif
    #endif

#endif
}

void shift_latch_hal(uint8_t state)
{
    digitalWrite(SHIFT_LATCH_PIN, state);
}

#ifdef SHIFT_SOFTWARE
static inline void local_shift_sw(uint8_t* data, uint32_t size)
{
    uint8_t i = 0;

    for(i = 0; i < size; i++)
     {
        shiftOut(SHIFT_DATA_PIN, SHIFT_CLK_PIN, MSBFIRST, data[i]);
    }
}
#endif

#ifdef SHIFT_SPI
static inline void local_shift_spi(uint8_t* data, uint32_t size)
{
    uint8_t i = 0;

    for(i = 0; i < size; i++)
    {
        mySPI.transfer(data[i]);
    }
}
#endif



#ifdef SHIFT_SPI_DMA
static inline void local_shift_spi_dma(uint8_t* data, uint32_t size)
{
    //reverse_array(data, size);

    // Fill buffer with new data.  The other buffer might
    // still be transmitting in the background via DMA.
    memcpy(source_memory[buffer_being_filled], (const void*)data, size);

    
    // Wait for prior transfer to complete before starting new one...
    while(!transfer_done);

    print_data(data, size);
    print_data(source_memory[buffer_being_filled], size);
    Serial.println(ARRAY_LAYER_SIZE);

    // Modify the DMA descriptor using the newly-filled buffer as source...
    myDMA.changeDescriptor(desc,           // DMA descriptor address
    (void *)&source_memory[buffer_being_filled]); // New src; dst & count don't change
    //myDMA.changeDescriptor(desc,           // DMA descriptor address
    //source_memory[buffer_being_filled]); // New src; dst & count don't change

    transfer_done = false;            // Reset 'done' flag
    stat = myDMA.startJob(); // Go!
    myDMA.printStatus(stat);

    // Switch buffer indices so the alternate buffer is filled on the next pass.
    buffer_being_filled = 1 - buffer_being_filled;

}
#endif

#ifdef SHIFT_SPI_DMA_TC
static inline void local_shift_spi_dma_tc(uint8_t* data, uint32_t size)
{
    // PA20 ist am LATCH angeschlossen
    // MUX E -> TC7/WO[0]
    // MUX F -> TCC0/WO[6]
    //
}
#endif

//void reverse_array(uint8_t *array, uint32_t number) {
//    uint32_t x, t;
//
//    for(x = 0; x < number; x ++, number --) {
//        t = array[x];
//        array[x] = array[number];
//        array[number] = t;
//    }
//}
