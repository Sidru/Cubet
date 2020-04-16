#include <Arduino.h>
#include <configuration.h>

#include <shift_register.h>
#include <cube.h>

#ifndef SIZE_OF_X
#warning no SIZE_OF_X has been defined. A default value of 8 will be taken
#define SIZE_OF_X 8
#endif

#ifndef SIZE_OF_Y
#warning no SIZE_OF_Y has been defined. A default value of 8 will be taken
#define SIZE_OF_Y
#endif

#ifndef SIZE_OF_Z
#warning no SIZE_OF_Z has been defined. A default value of 8 will be taken
#define SIZE_OF_Z 8
#endif

#define CUBE_REFRESH_MS 1

#define ARRAY_LAYER_SIZE (((uint32_t)SIZE_OF_X * (uint32_t)SIZE_OF_Y)/8 + ((uint32_t)SIZE_OF_Z/8))

uCUBE cube[SIZE_OF_X][SIZE_OF_Y][SIZE_OF_Z];

sCubet Cubet;

/* There are (SIZE_OF_X * SIZE_OF_Y)/8 + (SIZE_OF_Z/8) LED Driver */
uint8_t cube_array[SIZE_OF_X * SIZE_OF_Y + SIZE_OF_Z] = {0};
//uint8_t cube_array[9] = {1, 0, 0, 0, 0, 0, 0, 0, 1};

void set_test_cube(void)
{
    memset(cube, 0, sizeof(cube));
    sRGB testColor = {0, 0, 255}; 

    for(uint8_t i = 0; i < SIZE_OF_X; i++)
    {
        cube[i][i][i].rgb = testColor;
    }
}


void cube_to_shift_array(uCUBE* pCube, uint32_t cube_size, uint8_t* pArray, uint32_t array_size)
{
    uint8_t layer = 0;

    for(layer = 0; layer < SIZE_OF_Z; layer++)
    {
        
    }
}

void cube_init(void)
{
    uint8_t i = 0;
    uint8_t shift_val = 128;
    uint32_t pos = 0;

    shift_init();
    
    /* Fill the array positions for the Z Layer Shift Register. The first 8bits of the data packet
     * are for Z Layer. The 8 Layers are connected to the shift register 
    */
    for(i = 0; i < SIZE_OF_Z; i++)
    {
        cube_array[pos] = shift_val;
        shift_val >>= 1;
        pos += 9; // Every X*Y + Z -> 64/8 + 8/8  = 9
    }

    Cubet.refresh_us = ((1000000u / ((uint32_t)FRAMES_PER_SECOND * (uint32_t)PWM_RESOLUTION)) / (uint32_t)SIZE_OF_Z);

    Serial.println(Cubet.refresh_us);

}

void cube_set_shift_led(uint32_t x, uint32_t y, uint32_t z)
{
    uint32_t offset = z*9 + 8;
    uint32_t shift_pos = column_pos[x][y]; 
    uint32_t byte_pos = offset - (shift_pos / 8); // LSB, must be inverted
    uint32_t bit_pos = shift_pos % 8;

    cube_array[byte_pos] |= 1 << bit_pos;
}

void cube_clear_shift_led(uint32_t x, uint32_t y, uint32_t z)
{
    uint32_t offset = z*9 + 8;
    uint32_t shift_pos = column_pos[x][y]; 
    uint32_t byte_pos = offset - (shift_pos / 8); // LSB, must be inverted
    uint32_t bit_pos = shift_pos % 8;

    cube_array[byte_pos] &= ~(1 << bit_pos);
}



void cube_refresh(void)
{
    static unsigned long start_micros = micros();
    static uint32_t z_layer = 0;
    static uint8_t* pArray = (uint8_t*)cube_array;

    if((micros() - start_micros) >= (CUBE_REFRESH_MS*1000/SIZE_OF_Z))
    {
        start_micros = micros();

        shift_latch(LOW);
        shift_array(pArray, ARRAY_LAYER_SIZE); 
        shift_latch(HIGH);
        
        z_layer ++;
        if(z_layer >= SIZE_OF_Z)
        {
            z_layer = 0;
            pArray = cube_array; 
        }
        else
        {
            pArray += ARRAY_LAYER_SIZE;
        }
    }

    /* REFRESH JEDE X MS */

    /* 
     * Z Layer * 8 = 1xFrame
     * 25xFrames = 1s
     * [Z_Layer_0][Byte für Layer_0][Z_Layer_N][Byte für Layer_N]
    */
    
}

//void cube_test(void)
//{
//    static unsigned long start_millis = millis();
//    static uint8_t toggle = 0;
//    static uint8_t x = 0;
//    static uint8_t y = 0;
//    static uint8_t z = 0;
//    
//    if((millis() - start_millis) >= (1000/8))
//    {
//        start_millis = millis();
//
//        cube_clear_shift_led(x,y,z); 
//
//        y++;
//        if(y >= 8)
//        {
//            y = 0;
//            z++;
//
//            if(z >= 8)
//            {
//                z = 0;
//                x++;
//
//                if(x >= 8)
//                {
//                    x = 0;
//                }
//            }
//        }
//        cube_set_shift_led(x, y, z);
//
//    }
//}

void cube_test(void)
{
    static unsigned long start_millis = millis();
    static uint8_t z = 0;
    
    if((millis() - start_millis) >= (100))
    {
        start_millis = millis();

        for(uint8_t x = 0; x < 8; x++)
        {
            for(uint8_t y = 0; y < 8; y++)
            {
                cube_clear_shift_led(x,y,z); 
            }
        }

        z++;

        if(z >= 8)
        {
            z = 0;
        }

        for(uint8_t x = 0; x < 8; x++)
        {
            for(uint8_t y = 0; y < 8; y++)
            {
                cube_set_shift_led(x, y, z);
            }
        }
    }
}

