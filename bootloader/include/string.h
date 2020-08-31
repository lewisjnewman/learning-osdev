#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stddef.h>

void memset(void* dst, uint8_t b, size_t sz);
void memcpy(void* dst, const void* src, size_t sz);


uint32_t strlen(char* str);
void strreverse(char* str);
void strcpy(char* dst, char* src);

uint32_t b_sprintf(char* dst, const char* fmt, ...);

void hexdump8(uint8_t* buffer, char* str_buf, size_t size);
void hexdump16(uint16_t* buffer, char* str_buf, size_t size);
void hexdump32(uint32_t* buffer, char* str_buf, size_t size);
void hexdump64(uint64_t* buffer, char* str_buf, size_t size);

#endif