#include <Arduino.h>
#include <shift_register.h>
#include <shift_register_hal.h>

void shift_init(void)
{
    shift_hal_init();
}

void shift_array(uint8_t* data, uint32_t size)
{
    shift_array_hal(data, size);
}

void shift_latch(uint8_t state)
{
    shift_latch_hal(state);
}





