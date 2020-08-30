#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stdint.h>
#include <stddef.h>



void init_allocator(void* base, size_t size);
void* allocate_mem(size_t block_size);
void free_mem(void* ptr);

#endif