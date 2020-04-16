#ifndef CUBE_H
#define CUBE_H 

#include <Arduino.h>
#include <pinning.h>

typedef struct 
{
    uint8_t R;
    uint8_t G;
    uint8_t B;
}sRGB;

typedef struct
{
    uint8_t H;
    uint8_t S;
    uint8_t V;
}sHSV;

typedef union
{
    sRGB rgb;
    sHSV hsv;
    uint8_t bytes[4];
    uint32_t value;
}uCUBE;

typedef struct
{
    uint32_t refresh_us;
}sCubet;

void cube_init(void);
void cube_refresh(void);
void cube_test(void);


#endif
