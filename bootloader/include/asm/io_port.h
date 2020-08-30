#ifndef IO_PORT_H
#define IO_PORT_H

#include <stdint.h>

uint8_t io_in8(uint16_t portnum);
uint16_t io_in16(uint16_t portnum);
uint32_t io_in32(uint16_t portnum);

uint8_t io_out8(uint16_t portnum, uint8_t val);
uint16_t io_out16(uint16_t portnum, uint16_t val);
uint32_t io_out32(uint16_t portnum, uint32_t val);

#endif