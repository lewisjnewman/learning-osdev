#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

#include <conversions.h>

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

uint32_t strlen(char* str){
    uint32_t len = 0;
    while(*str++ !='\0') len++;
    return len;
}

void strreverse(char* str){
    uint32_t size = strlen(str);

    uint32_t start = 0;
    uint32_t end = size-1;
    while(start < end){
        char tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        start++; end--;
    }
}

//about as dangerous as it could get
void strcpy(char* dst, char* src){
    while((*dst++=*src++) != '\0');
}



//format string types
#define FMT_STRING  0x01    //string in varags
#define FMT_CHAR    0x02    //char in varargs
#define FMT_INT     0x03    //signed 32bit integer in varargs
#define FMT_UINT    0x04    //unsigned 32bit integer in varargs
#define FMT_LONG    0x05    //signed 64bit integer in varargs
#define FMT_ULONG   0x06    //unsigned 64bit integer in varargs
#define FMT_FLOAT   0x07    //32bit floating point value
#define FMT_DOUBLE  0x08    //64bit floating point value
#define FMT_ESCAPE  0x09    //escaped percentage sign
#define FMT_HEX     0x0A    //32bit hex value
#define FMT_LHEX    0x0B    //64bit hex value


const char* parse_format(const char* fmt, uint32_t* fmt_type){

    switch(*fmt++){
        case 's':
            *fmt_type = FMT_STRING;
            break;
        case 'c':
            *fmt_type = FMT_CHAR;
            break;
        case 'd':
            *fmt_type = FMT_INT;
            break;
        case 'u':
            *fmt_type = FMT_UINT;
            break;
        case 'l':
            switch(*fmt++){
                case 'd':
                    *fmt_type = FMT_LONG;
                    break;
                case 'u':
                    *fmt_type = FMT_ULONG;
                    break;
                case 'f':
                    *fmt_type = FMT_DOUBLE;
                    break;
                case 'x':
                    *fmt_type = FMT_LHEX;
                    break;
                default:
                    *fmt_type = -1;
                    break;
            }
            break;
        case 'f':
            *fmt_type = FMT_FLOAT;
            break;
        case '%':
            *fmt_type = FMT_ESCAPE;
            break;
        case 'x':
            *fmt_type = FMT_HEX;
            break;
        default:
            *fmt_type = -1;
            break;
    }

    return fmt;
}

uint32_t b_sprintf(char* dst, const char* fmt, ...){

    va_list args;
    va_start(args, fmt);

    uint32_t chars_written = 0;

    while(*fmt != '\0'){
        
        uint32_t fmt_type;

        //not the start of a fmt string
        if(*fmt++ != '%'){
            *dst++ = *(fmt-1);
            chars_written++;
            continue;
        }
        //else - this is the start of a format string, parse it

        fmt = parse_format(fmt, &fmt_type);

        switch(fmt_type){

            //vars for inside switch statement
            const char* str;
            char c;
            int32_t integer;
            uint32_t uinteger;
            uint32_t uinteger_h;
            int64_t linteger;
            uint64_t ulinteger;
            //float floating_point;
            //double long_floating_point;

            //used as an iterator
            uint32_t it = 0;

            //for conversion functions
            const int STR_BUF_SIZE = 64;
            char str_buf[STR_BUF_SIZE];
            memset(str_buf, 0, 64);


            case FMT_STRING:
                str = va_arg(args, const char*);
                while(*str != '\0'){
                    *dst++ = *str++;
                    chars_written++;
                }
                break;

            case FMT_CHAR:
                c = va_arg(args, int);
                *dst++ = c;
                chars_written++;
                break;

            case FMT_INT:
                integer = va_arg(args, int32_t);
                int32_to_str(integer, str_buf);
                for(it = 0; it < strlen(str_buf); it++){
                    *dst++ = str_buf[it];
                    chars_written++;
                }
                break;
                
            case FMT_UINT:
                uinteger = va_arg(args, uint32_t);
                uint32_to_str(uinteger, str_buf);
                for(it = 0; it < strlen(str_buf); it++){
                    *dst++ = str_buf[it];
                    chars_written++;
                }
                break;

            case FMT_LONG:
                linteger = va_arg(args, int64_t);
                int64_to_str(linteger, str_buf);
                for(it = 0; it < strlen(str_buf); it++){
                    *dst++ = str_buf[it];
                    chars_written++;
                }
                break;

            case FMT_ULONG:
                ulinteger = va_arg(args, int64_t);
                uint64_to_str(ulinteger, str_buf);
                for(it = 0; it < strlen(str_buf); it++){
                    *dst++ = str_buf[it];
                    chars_written++;
                }
                break;

            case FMT_FLOAT:
                break;

            case FMT_DOUBLE:
                break;

            case FMT_ESCAPE:
                *dst++ = '%';
                break;

            case FMT_HEX:
                uinteger = va_arg(args, uint32_t);
                bits32_to_hex(uinteger, str_buf);
                for(it = 0; it < strlen(str_buf); it++){
                    *dst++ = str_buf[it];
                    chars_written++;
                }                
                break;

            case FMT_LHEX:
                uinteger = va_arg(args, uint32_t);
                uinteger_h = va_arg(args, uint32_t);
                ulinteger = ((uint64_t)uinteger_h<<32) | uinteger;
                bits64_to_hex(ulinteger, str_buf);
                for(it = 0; it < strlen(str_buf); it++){
                    *dst++ = str_buf[it];
                    chars_written++;
                }       
                break;

            case -1:
            default:
                va_end(args);
                return -1;
        }
    }

    *dst++ = '\0';

    va_end(args);
    return chars_written;
}