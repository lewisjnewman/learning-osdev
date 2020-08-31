#include <asm/io_port.h>


uint8_t io_in8 (uint16_t port) {
    uint8_t result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

void io_out8 (uint16_t port, uint8_t data) {
    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}

uint16_t io_in16 (uint16_t port) {
    uint16_t result;
    __asm__("in %%dx, %%ax" : "=a" (result) : "d" (port));
    return result;
}

void io_out16 (uint16_t port, uint16_t data) {
    __asm__("out %%ax, %%dx" : : "a" (data), "d" (port));
}

void io_out32(uint16_t port, uint32_t value) {
	   __asm__ __volatile__("outl %%eax,%%dx"::"d" (port), "a" (value));
};

uint32_t io_int32(uint16_t port) {
    uint32_t result;
    __asm__ __volatile__("inl %%dx,%%eax":"=a" (result):"d"(port));
    return result;
}