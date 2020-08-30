#ifndef DIV_H
#define DIV_H

#include <stdint.h>

uint64_t div_u64(uint64_t dividend, uint64_t divisor){

    uint64_t denom=divisor;
    uint64_t current = 1;
    uint64_t answer=0;

    if ( denom > dividend) 
        return 0;

    if ( denom == dividend)
        return 1;

    while (denom <= dividend) {
        denom <<= 1;
        current <<= 1;
    }

    denom >>= 1;
    current >>= 1;

    while (current!=0) {
        if ( dividend >= denom) {
            dividend -= denom;
            answer |= current;
        }
        current >>= 1;
        denom >>= 1;
    }    
    return answer;
}

int64_t div_i64(int64_t dividend, int64_t divisor){

    int64_t sign = 1;

    if(dividend < 0){
        sign *= -1;
        dividend *= -1;
    }
    if(divisor < 0){
        sign *= -1;
        divisor *= -1;
    }

    uint64_t denom=divisor;
    uint64_t current = 1;
    uint64_t answer=0;

    if ( denom > dividend) 
        return 0;

    if ( denom == dividend)
        return 1;

    while (denom <= dividend) {
        denom <<= 1;
        current <<= 1;
    }

    denom >>= 1;
    current >>= 1;

    while (current!=0) {
        if ( dividend >= denom) {
            dividend -= denom;
            answer |= current;
        }
        current >>= 1;
        denom >>= 1;
    }    
    return answer * sign;
}

int64_t mod_i64(int64_t dividend, int64_t divisor){
    return (dividend - divisor * div_i64(dividend, divisor));
}

uint64_t mod_u64(uint64_t dividend, uint64_t divisor){
    return (dividend - divisor * div_u64(dividend, divisor));
}

#endif