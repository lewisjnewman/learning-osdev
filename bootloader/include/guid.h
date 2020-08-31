#ifndef GUID_H
#define GUID_H

#include <stdint.h>

typedef struct __attribute__((__packed__)) _guid{
    uint32_t time_low;
    uint16_t time_mid;
    uint16_t time_hi_and_version;
    uint8_t clock_seq_hi_and_reserved;
    uint8_t clock_seq_low;
    uint8_t node[6];
} guid;

#endif