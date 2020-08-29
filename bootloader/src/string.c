#include <stdint.h>
#include <stddef.h>

void memset(void* dst, uint8_t b, size_t sz){

    uint8_t* ptr = dst;
    for(size_t i = 0; i < sz; ++i){
        ptr[i] = b;
    }

}

void memcpy(void* dst, const void* src, size_t sz){

    uint8_t* dst_s = (uint8_t*)dst;
    const uint8_t* src_s = (const uint8_t*)src;

    for(size_t i = 0; i < sz; ++i){
        dst_s[i] = src_s[i];
    }
    
}