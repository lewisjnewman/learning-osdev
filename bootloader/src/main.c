#include <string.h>
#include <mem_locations.h>
#include <vga_io.h>

const char* hello = "Hello From The C Bootloader";

void boot_main(){
    
       clear_screen();
       puts(hello);

/*
       vga_char filler;
       filler.character = 'x';
       filler.colour_bg = BLUE;
       filler.colour_fg = WHITE;

       fill_screen(filler);
*/
}