#include <allocator.h>

#include <stdint.h>
#include <stddef.h>

typedef struct __attribute__((__packed__)) _allocator_block {
    struct _allocator_block* next;  //pointer to the next allocator block
    struct _allocator_block* prev;
    size_t size;                    //sizeof this block - also the least significant bit indicates free or used
} allocator_block;

#define LIST_SENTINEL ((void*)0)

allocator_block* allocator_base = (allocator_block*)LIST_SENTINEL;
allocator_block* allocator_top = (allocator_block*)LIST_SENTINEL;
size_t allocator_size = 0;

//helpers for getting/setting whether a block is free/used
#define IS_USED(n) (n & 0x01)
#define MSK_FREE(n) (n & ~0x01)
#define SET_FREE(n) (n = n & ~0x01)
#define SET_USED(n) (n = n | 0x01)

//alignment helpers
#define ALIGN(n) (n + sizeof(size_t)-(n%sizeof(size_t))) 

void init_allocator(void* base, size_t size){
    allocator_base = (allocator_block*)base;
    allocator_size = size;
    allocator_top = (allocator_block*)((size_t)allocator_base + allocator_size);

    allocator_block* root_block = (allocator_block*)allocator_base;

    root_block->next = (allocator_block*)LIST_SENTINEL;
    root_block->prev = (allocator_block*)LIST_SENTINEL;
    root_block->size = allocator_size - sizeof(allocator_block);
}


void* allocate_mem(size_t block_size){

    if(block_size < sizeof(allocator_block)){
        block_size = sizeof(allocator_block);
    }

    block_size = ALIGN(block_size);

    allocator_block* iterator = (allocator_block*)allocator_base;

    //find the first free block that is big enough
    while(IS_USED(iterator->size) || MSK_FREE(iterator->size) < block_size+sizeof(allocator_block)){
        if(iterator->next == LIST_SENTINEL){
            //allocator is out of memory
            return NULL;
        }

        iterator = iterator->next;
    }

    //iterator now points at a block that we can use

    //an exact match
    if(block_size == MSK_FREE(iterator->size)){
        SET_USED(iterator->size);
        return (void*)(iterator+1);
    }
    else{

        //get the location of the newblock we are going to create        
        allocator_block* new_block = (allocator_block*)((uint8_t*)iterator + block_size + sizeof(allocator_block));


        //add the new allocator block to the block of linked lists
        new_block->next = iterator->next;
        new_block->prev = iterator;
        iterator->next = new_block;



        //if there is a block after us then set it's prev pointer to point to us
        if(new_block->next != LIST_SENTINEL){
            new_block->next->prev = new_block;
        }


        //set the new block size
        new_block->size = MSK_FREE(iterator->size) - block_size - sizeof(allocator_block);

        //set the old block size to the amount allocated
        iterator->size = block_size;

        //mark it as used
        SET_USED(iterator->size);

        //return a ptr to the start of the heap space to be used
        return (void*)(iterator+1);
    }
}


void forward_merge(allocator_block* block){

    if(block->next == LIST_SENTINEL){
        return;
    }
    else if(IS_USED(block->next->size)){
        return;
    }

    forward_merge(block->next);

    //the next block is free, we can do a forward merge
    allocator_block* next = block->next;

    block->next = next->next;
    block->size += sizeof(allocator_block) + MSK_FREE(next->size);
    if(block->next != LIST_SENTINEL){
        block->next->prev = block;
    }
}

void reverse_merge(allocator_block* block){
    

    if(block->prev == LIST_SENTINEL){
        return;
    }
    else if(IS_USED(block->prev->size)){
        return;
    }

    reverse_merge(block->prev);

    //previous block is free
    forward_merge(block->prev);
}

void free_mem(void* ptr){
    allocator_block* block = (allocator_block*)ptr - 1;

    //mark this block as free
    SET_FREE(block->size);

    forward_merge(block);
    reverse_merge(block);
}