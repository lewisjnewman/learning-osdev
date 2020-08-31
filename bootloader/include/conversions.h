#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include <stdint.h>
#include <stddef.h>

void int32_to_str(int32_t val, char* str);
void uint32_to_str(uint32_t val, char* str);
void int64_to_str(int64_t val, char* str);
void uint64_to_str(uint64_t val, char* str);
void bits8_to_hex(uint8_t val, char* str);
void bits16_to_hex(uint16_t val, char* str);
void bits32_to_hex(uint32_t val, char* str);
void bits64_to_hex(uint64_t val, char* str);

#endif