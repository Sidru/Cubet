#ifndef CUBE_H
#define CUBE_H 

#include <Arduino.h>
#include <configuration.h>

typedef struct 
{
    uint8_t R;
    uint8_t G;
    uint8_t B;
    uint8_t W;
}sRGBW;

typedef struct
{
    uint8_t H;
    uint8_t S;
    uint8_t V;
    uint8_t dummy;
}sHSV;

typedef union
{
    sRGBW rgbw;
    sHSV hsv;
    uint8_t bytes[4];
    uint32_t value;
}uVoxel;


class cCube {
private:
    uint32_t _refresh_us; 
    uVoxel _voxel[SIZE_OF_X][SIZE_OF_Y][SIZE_OF_Z];
    uint8_t _shift_data[SIZE_OF_X * SIZE_OF_Y + SIZE_OF_Z];

    void voxel_to_shift(void);

public:
    cCube();
    ~cCube();

    void begin(void);
    void refresh(void);
    void set_voxel(uint32_t x, uint32_t y, uint32_t z, uint8_t state);
    uint32_t get_voxel(uint32_t x, uint32_t y, uint32_t z);
    void test_single(void);
    void test_layer(void);
};

 
#endif
