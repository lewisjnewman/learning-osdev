#ifndef GPT_H
#define GPT_H

#include <stdint.h>
#include <stddef.h>

#include <guid.h>

//structures for guid partition table

typedef struct __attribute__((__packed__)) _gpt_header{
    uint64_t signature;
    uint32_t revision;
    uint32_t header_size;
    uint32_t header_crc32;
    uint32_t _reserved;
    uint64_t current_lba;
    uint64_t backup_lba;
    uint64_t first_lba;
    uint64_t last_lba;
    guid disk_guid;
    uint64_t entries_lba;
    uint32_t number_of_partitions;
    uint32_t entry_size;
    uint32_t entries_crc32;
    //reserved...
} gpt_header;

typedef struct __attribute__((__packed__)) _gpt_entry{
    guid type_guid;
    guid part_guid;
    uint64_t first_lba;
    uint64_t last_lba;
    uint64_t attr_flags;
    wchar_t part_name[36];
} gpt_entry;

#endif