#include <conversions.h>

#include <stdint.h>
#include <stddef.h>

#include <string.h>
#include <div.h>

//int32_to_str
//uint32_to_str
//int64_to_str
//uint64_to_str
//bit32_to_hex
//bit64_to_hex

void int32_to_str(int32_t val, char* str){

    char* str_start = str;

    if(val == 0){
        *str++ = '0';
        *str++ = '\0';
        return;
    }

    if(val < 0){
        *str++ = '-';
        val = -val;
    }

    while(val != 0){
        uint32_t digit = val % 10;
        *str++ = digit + '0';
        val /= 10;
    }

    *str++ = '\0';

    strreverse(str_start);
}

void uint32_to_str(uint32_t val, char* str){

    char* str_start = str;

    if(val == 0){
        *str++ = '0';
        *str++ = '\0';
        return;
    }

    while(val != 0){
        uint32_t digit = val % 10;
        *str++ = digit + '0';
        val /= 10;
    }

    *str++ = '\0';

    strreverse(str_start);
}

void int64_to_str(int64_t val, char* str){

    char* str_start = str;

    if(val == 0){
        *str++ = '0';
        *str++ = '\0';
        return;
    }

    if(val < 0){
        *str++ = '-';
        val = -val;
    }

    while(val != 0){
        int64_t digit = mod_i64(val, 10);
        *str++ = digit + '0';
        val = div_i64(val, 10);
    }

    *str++ = '\0';

    strreverse(str_start);
}

void uint64_to_str(uint64_t val, char* str){

    char* str_start = str;

    if(val == 0){
        *str++ = '0';
        *str++ = '\0';
        return;
    }

    while(val != 0){
        uint64_t digit = mod_u64(val, 10);
        *str++ = digit + '0';
        val = div_u64(val, 10);
    }

    *str++ = '\0';

    strreverse(str_start);
}

char hex_digit_table[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void bits8_to_hex(uint8_t val, char* str){
    char* str_start = str;
    for(uint8_t i = 0; i < sizeof(uint8_t); i++){
        *str++ = hex_digit_table[val&0xF];
        val = val >> 4;

        *str++ = hex_digit_table[val&0xF];
        val = val >> 4;
    }
    *str++ = '\0';
    strreverse(str_start);
}

void bits16_to_hex(uint16_t val, char* str){
    char* str_start = str;
    for(uint16_t i = 0; i < sizeof(uint16_t); i++){
        *str++ = hex_digit_table[val&0xF];
        val = val >> 4;

        *str++ = hex_digit_table[val&0xF];
        val = val >> 4;
    }
    *str++ = '\0';
    strreverse(str_start);
}

void bits32_to_hex(uint32_t val, char* str){
    char* str_start = str;
    for(uint32_t i = 0; i < sizeof(uint32_t); i++){
        *str++ = hex_digit_table[val&0xF];
        val = val >> 4;

        *str++ = hex_digit_table[val&0xF];
        val = val >> 4;
    }
    *str++ = '\0';
    strreverse(str_start);
}

void bits64_to_hex(uint64_t val, char* str){
    char* str_start = str;

    for(uint32_t i = 0; i < sizeof(uint64_t); i++){
        *str++ = hex_digit_table[val&0xF];
        val = val >> 4;

        *str++ = hex_digit_table[val&0xF];
        val = val >> 4;
    }
    *str++ = '\0';
    strreverse(str_start);
}