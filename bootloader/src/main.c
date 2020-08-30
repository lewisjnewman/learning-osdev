#include <string.h>
#include <mem_locations.h>
#include <vga_io.h>
#include <bios_map.h>

void print_bios_memory_maps(){
       bios_memmap* list = (bios_memmap*)BIOS_MEMMAP;

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
}

void boot_main(){
    
       clear_screen();
 
       b_puts("Hello From The C Bootloader\n");

       print_bios_memory_maps();
}