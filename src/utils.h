#ifndef UTILS_H

#define UTILS_H

#include <stdint.h>

typedef struct
{
    uint8_t *str;
    uint64_t size;
} string8;

uint8_t msb(uint16_t b);

uint8_t lsb(uint16_t b);

uint16_t unsigned16(uint8_t lsb, uint8_t msb);

int8_t signed8(uint8_t value);

#endif