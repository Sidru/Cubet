#ifndef SHIFT_REGISTER_H
#define SHIFT_REGISTER_H

#include <Arduino.h>

void shift_init(void);
void shift_array(uint8_t* data, uint32_t size);
void shift_latch(uint8_t state);

#endif
