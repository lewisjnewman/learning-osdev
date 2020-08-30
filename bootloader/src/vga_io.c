
#include <stdint.h>
#include <stddef.h>

#include "mem_locations.h"
#include "vga_io.h"


vga_char* screen_ptr = (vga_char*)VGA_START;
uint8_t foreground_colour = LIGHT_GRAY;
uint8_t background_colour = BLACK;

//from the fact we set the video mode to 0x03 in boot.asm
const uint32_t TERM_WIDTH = 80;
const uint32_t TERM_HEIGHT = 25;

void set_foreground(uint8_t colour){
    foreground_colour = colour;
}

void set_background(uint8_t colour){
    background_colour = colour;
}


void fill_screen(vga_char c){
    //iterate throughout the entire vga array
    for(vga_char* it = (vga_char*)VGA_START; it < (vga_char*)VGA_END; it++){
        *it = c;
    }
}

void clear_screen(){
    vga_char c;
    c.character = ' ';
    c.colour_fg = foreground_colour;
    c.colour_bg = background_colour;
    fill_screen(c);

    screen_ptr = (vga_char*)VGA_START;
}

void newline(){
    size_t ptr = (size_t)screen_ptr;
    ptr = ptr - (ptr%VGA_LINE) + VGA_LINE;
    screen_ptr = (vga_char*)ptr;
}

void b_putc(char c){
    vga_char vc;
    
    vc.character = c;
    vc.colour_fg = foreground_colour;
    vc.colour_bg = background_colour;
    
    *screen_ptr = vc;

    screen_ptr++;
}

void b_puts(const char* s){

    const char* ptr = s;

    char c = *ptr++;
    while(c != '\0'){

        switch (c)
        {
        case '\n':
        case '\r':
            newline();
            break;        
        default:
            b_putc(c);
            break;
        }
         c = *ptr++;
    }
}

/*

uint32_t get_cursor_x(){
    uint32_t position = (uint32_t)screen_ptr / 2;

}

uint32_t get_cursor_y(){

}

void set_cursor_x(uint32_t x){

}

void set_cursor_y(uint32_t y){

}

void set_cursor(uint32_t x, uint32_t y){

}
*/