
#include <stdint.h>
#include <stddef.h>

#include "mem_locations.h"
#include "vga_io.h"


vga_char* screen_ptr = (vga_char*)VGA_START;
uint8_t foreground_colour = WHITE;
uint8_t background_colour = BLUE;

void fill_screen(vga_char c){
    //iterate throughout the entire vga array
    for(vga_char* it = (vga_char*)VGA_START; it < (vga_char*)VGA_END; it++){
        *it = c;
    }
}

void clear_screen(){
    vga_char c;
    c.character = ' ';
    c.colour_fg = WHITE;
    c.colour_bg = BLACK;
    fill_screen(c);

    screen_ptr = (vga_char*)VGA_START;
}

void newline(){
    size_t ptr = (size_t)screen_ptr;
    ptr = ptr - (ptr%VGA_LINE) + VGA_LINE;
    screen_ptr = (vga_char*)ptr;
}

void putc(char c){
    vga_char vc;
    
    vc.character = c;
    vc.colour_fg = foreground_colour;
    vc.colour_bg = background_colour;
    
    *screen_ptr = vc;

    screen_ptr++;
}

void puts(const char* s){

    const char* ptr = s;

    vga_char* it = screen_ptr;

    char c = *ptr++;
    while(c != '\0'){

        it->character = c;
        it += 1;

        c = *ptr++;
    }

}