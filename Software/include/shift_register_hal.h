#ifndef SHIFT_REGISTER_HAL_H
#define SHIFT_REGISTER_HAL_H

#include <Arduino.h>

void shift_hal_init(void);
void shift_array_hal(uint8_t *data, uint32_t size);
void shift_latch_hal(uint8_t state);

#endif
