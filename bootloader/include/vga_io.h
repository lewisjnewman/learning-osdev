#ifndef VGA_IO_H
#define VGA_IO_H

#include <stdint.h>
#include <stddef.h>

typedef struct __attribute__((__packed__)){
    char    character;
    uint8_t colour_fg:4;
    uint8_t colour_bg:4;
} vga_char;

//16bit colours
#define BLACK 0x0
#define BLUE 0x1
#define GREEN 0x2
#define CYAN 0x3
#define RED 0x4
#define MAGENTA 0x5
#define BROWN 0x6
#define LIGHT_GRAY 0x7
#define DARK_GRAY 0x8
#define LIGHT_BLUE 0x9
#define LIGHT_GREEN 0xA
#define LIGHT_CYAN 0xB
#define LIGHT_RED 0xC
#define LIGHT_MAGENTA 0xD
#define YELLOW 0xE
#define WHITE 0xF

void fill_screen(vga_char);
void clear_screen();
void b_putc(char);
void b_puts(const char*);

#endif