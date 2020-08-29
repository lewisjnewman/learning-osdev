#ifndef BIOS_MAP
#define BIOS_MAP

#include <stdint.h>
#include <stddef.h>

typedef struct __attribute__((__packed__)){
    uint64_t base_address;
    uint64_t map_size;
    uint32_t type;    
} bios_memmap;

//types of maps
#define BIOS_MAP_FREE_MEMORY    0x01
#define BIOS_MAP_RESERVED       0x02
#define BIOS_MAP_ACPI_RECLAIM   0x03
#define BIOS_MAP_ACPI_NVS       0x04

#endif