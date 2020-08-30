#include <string.h>
#include <mem_locations.h>
#include <vga_io.h>

void boot_main(){
    
       clear_screen();
 
       b_puts("Hello From The C Bootloader\n");

       char buf[1024];

       b_sprintf(buf, "0x%d", 0x41414141);

       b_puts(buf);
}