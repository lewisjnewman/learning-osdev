#ifndef MEM_LOCATIONS_H
#define MEM_LOCATIONS_H

//bios data area
#define BDA_START   0x0400
#define BDA_SIZE    0x100

//bios mem map (we load it into this address in boot.asm)
#define BIOS_MEMMAP 0x0500

//base address of our executable (keeping in mind we are linked to the mbr)
#define EXE_BASE    0x7C00

//extended bios data area
#define EBDA_START  0x00080000
#define EBDA_END    0x0009FFFF
#define EBDA_SIZE   (EBDA_END-EBDA_START+1)

//video graphics array
#define VGA_START   0x000b8000
#define VGA_END     0x000BFFFF
#define VGA_SIZE    (VGA_END-VGA_START+1)

//size in bytes of a vga line
#define VGA_LINE   0xA0


#endif