#include <string.h>
#include <mem_locations.h>
#include <vga_io.h>

void boot_main(){
    
       clear_screen();
 
       b_puts("Hello From The C Bootloader\n");

       char buf[1024];

       b_sprintf(buf, "%s", "Testing Format Strings");

       b_puts(buf);
}