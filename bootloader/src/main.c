#include <string.h>
#include <mem_locations.h>
#include <vga_io.h>
#include <bios_map.h>
#include <allocator.h>

#define BOOTLOADER_ALLOCATOR_SIZE 32*1024*1024

void print_bios_memory_maps(){
    bios_memmap* list = (bios_memmap*)BIOS_MEMMAP;

    b_puts("BIOS MEMORY MAPS\n");

    uint32_t i = 0;
    while(list[i].type != 0){
        char buf[80];
        memset(buf, 0, 80);

        uint64_t base = list[i].base_address;
        uint64_t size = list[i].map_size;
        uint64_t top = base + size;
        char* str = bios_mem_map_strings[list[i].type];

        b_sprintf(buf, "[0x%lx - 0x%lx] 0x%lx %s\n", base, top, size, str);
        b_puts(buf);

        i++;
    }
    b_puts("\n");
}

void setup_memory(){
    bios_memmap* list = (bios_memmap*)BIOS_MEMMAP;

    //find the first free memory above 1MB
    uint32_t i = 0;
    while(list[i].type != BIOS_MAP_FREE_MEMORY || list[i].base_address < 0x00100000){
        i++;
    }

    uint32_t allocator_size = list[i].map_size;

    if(allocator_size > BOOTLOADER_ALLOCATOR_SIZE){
        allocator_size = BOOTLOADER_ALLOCATOR_SIZE;
    }

    char output_buf[80];

    b_sprintf(output_buf, "Creating Allocator At 0x%lx Size %lu\n", list[i].base_address, list[i].map_size);
    b_puts(output_buf);

    init_allocator((void*)list->base_address, list->map_size);
}

void boot_main(){

    clear_screen();

    b_puts("Hello From The C Bootloader\n\n");

    //print out the bios memory maps
    print_bios_memory_maps();

    //setup the memory allocator
    setup_memory();

    b_puts("Memory Allocator Created");
}