#include "utils.h"

uint8_t lsb(uint16_t b)
{
    return b;
}

uint8_t msb(uint16_t b)
{
    return b >> 8;
}

uint16_t unsigned16(uint8_t lsb, uint8_t msb)
{
    return (uint16_t)msb << 8 | lsb;
}

int8_t signed8(uint8_t value)
{
    return (int8_t)value;
}
