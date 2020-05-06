#include <Arduino.h>
#include <configuration.h>
#include <pinning.h>
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

#ifndef ARRAY_LAYER_SIZE
#warning no ARRAY_LAYER_SIZE calculated
#define ARRAY_LAYER_SIZE (((uint32_t)SIZE_OF_X * (uint32_t)SIZE_OF_Y)/8 + ((uint32_t)SIZE_OF_Z/8))
#endif




cCube::cCube(void)
{
    memset(_voxel, 0, sizeof(_voxel));
    memset(_shift_data, 0, sizeof(_shift_data));
//    sRGBW testColor = {255, 0, 0, 0};
//
//    for(uint8_t i = 0; i < SIZE_OF_X; i++)
//    {
//        _voxel[i][i][i].rgbw = testColor;
//    }

    _sizeX = SIZE_OF_X;
    _sizeY = SIZE_OF_Y;
    _sizeZ = SIZE_OF_Z;
}

cCube::~cCube(void)
{
}

void cCube::begin(void)
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
        _shift_data[pos] = shift_val;
        shift_val >>= 1;
        pos += 9; // Every X*Y + Z -> 64/8 + 8/8  = 9
    }

    _refresh_us = ((1000000u / ((uint32_t)FRAMES_PER_SECOND * (uint32_t)PWM_RESOLUTION)) / (uint32_t)SIZE_OF_Z);
}

void cCube::set_shift_led(uint32_t x, uint32_t y, uint32_t z)
{
    uint32_t offset = z*9 + 8;
    uint32_t shift_pos = column_pos[x][y]; 
    uint32_t byte_pos = offset - (shift_pos / 8); // LSB, must be inverted
    uint32_t bit_pos = shift_pos % 8;

    _shift_data[byte_pos] |= 1 << bit_pos;
}

void cCube::clear_shift_led(uint32_t x, uint32_t y, uint32_t z)
{
    uint32_t offset = z*9 + 8;
    uint32_t shift_pos = column_pos[x][y]; 
    uint32_t byte_pos = offset - (shift_pos / 8); // LSB, must be inverted
    uint32_t bit_pos = shift_pos % 8;

    _shift_data[byte_pos] &= ~(1 << bit_pos);
}


void cCube::refresh(void)
{
    static unsigned long start_micros = micros();
    static uint32_t z_layer = 0;
    static uint8_t* pArray = _shift_data;

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
            pArray = _shift_data; 
            cube_to_shift();
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

void cCube::set_voxel(uint32_t x, uint32_t y, uint32_t z, uint32_t state)
{
   _voxel[x][y][z].value = state;

   //if(state)
   //{
   //    this->set_shift_led(x, y, z);
   //}
   //else
   //{
   //    this->clear_shift_led(x, y, z);
   //}
}

uint32_t cCube::get_voxel(uint32_t x, uint32_t y, uint32_t z)
{
    //if(_voxel[x][y][z].value)
    //{
    //    return 1;
    //}
    //else
    //{
    //    return 0;
    //}
    return _voxel[x][y][z].value;
}

void cCube::cube_to_shift(void) 
{
    uint32_t x, y, z;

    for(x = 0; x < _sizeX; x++)
    {
        for(y = 0; y < _sizeY; y++)
        {
            for(z = 0; z < _sizeZ; z++)
            {
                if(_voxel[x][y][z].value)
                {
                    this->set_shift_led(x, y, z);
                }
                else
                {
                    this->clear_shift_led(x, y, z);
                }

            }
        }
    }
}

void cCube::test_single(void)
{
    static unsigned long start_millis = millis();
    static uint8_t x = 0;
    static uint8_t y = 0;
    static uint8_t z = 0;
    
    if((millis() - start_millis) >= (1000/8))
    {
        start_millis = millis();

        this->set_voxel(x,y,z,0);

        y++;
        if(y >= 8)
        {
            y = 0;
            z++;

            if(z >= 8)
            {
                z = 0;
                x++;

                if(x >= 8)
                {
                    x = 0;
                }
            }
        }
        this->set_voxel(x,y,z,1);
    }
}

void cCube::test_layer(void)
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
                this->clear_shift_led(x,y,z); 
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
                this->set_shift_led(x, y, z);
            }
        }
    }
}

void cCube::fill_array(uint8_t value)
{
    int x, y, z;   

    //memset(_voxel, value, sizeof(_voxel));
    memset(_voxel, value, sizeof(_voxel)); 

    //for(x = 0; x < 8; x++)
    //{
    //    for(y = 0; y < 8; y++)
    //    {
    //        for(z = 0; z < 8; z++)
    //        {
    //            this->set_voxel(x, y, z, value);
    //        }
    //    }
    //    
    //}
}

