#ifndef IO_PORT_H
#define IO_PORT_H

#include <stdint.h>

uint8_t io_in8(uint16_t portnum);
uint16_t io_in16(uint16_t portnum);
uint32_t io_in32(uint16_t portnum);

void io_out8(uint16_t portnum, uint8_t val);
void io_out16(uint16_t portnum, uint16_t val);
void io_out32(uint16_t portnum, uint32_t val);

//common io port numbers

//first dma contr   oller
#define DMA_1_00    0x0000
#define DMA_1_01    0x0001
#define DMA_1_02    0x0002
#define DMA_1_03    0x0003
#define DMA_1_04    0x0004
#define DMA_1_05    0x0005
#define DMA_1_06    0x0006
#define DMA_1_07    0x0007
#define DMA_1_08    0x0008
#define DMA_1_09    0x0009
#define DMA_1_0A    0x000A
#define DMA_1_0B    0x000B
#define DMA_1_0C    0x000C
#define DMA_1_0D    0x000D
#define DMA_1_0E    0x000E
#define DMA_1_0F    0x000F
#define DMA_1_10    0x0010
#define DMA_1_11    0x0011
#define DMA_1_12    0x0012
#define DMA_1_13    0x0013
#define DMA_1_14    0x0014
#define DMA_1_15    0x0015
#define DMA_1_16    0x0016
#define DMA_1_17    0x0017
#define DMA_1_18    0x0018
#define DMA_1_19    0x0019
#define DMA_1_1A    0x001A
#define DMA_1_1B    0x001B
#define DMA_1_1C    0x001C
#define DMA_1_1D    0x001D
#define DMA_1_1E    0x001E
#define DMA_1_1F    0x001F

//first pic controller
#define PIC_1_20    0x0020
#define PIC_1_21    0x0021

//programmable interval timer
#define PIT_40      0x0040
#define PIT_41      0x0041
#define PIT_42      0x0042
#define PIT_43      0x0043
#define PIT_44      0x0044
#define PIT_45      0x0045
#define PIT_46      0x0046
#define PIT_47      0x0047

//PS2 controller
#define PS2_60      0x0060
#define PS2_61      0x0061
#define PS2_62      0x0062
#define PS2_63      0x0063
#define PS2_64      0x0064

//CMOS and RTC
#define CMOS        0x0070
#define RTC         0x0071

//DMA_PAGE
#define DMA_P_80    0x0080
#define DMA_P_81    0x0081
#define DMA_P_82    0x0082
#define DMA_P_83    0x0083
#define DMA_P_84    0x0084
#define DMA_P_85    0x0085
#define DMA_P_86    0x0086
#define DMA_P_87    0x0087
#define DMA_P_88    0x0088
#define DMA_P_89    0x0089
#define DMA_P_8A    0x008A
#define DMA_P_8B    0x008B
#define DMA_P_8C    0x008C
#define DMA_P_8D    0x008D
#define DMA_P_8E    0x008E
#define DMA_P_8F    0x008F

//fast a20 register
#define FAST_A20    0x0092

//second pic controller
#define PIC_2_A0    0x00A0
#define PIC_2_A1    0x00A1

//second dma controller
#define DMA_2_C0    0x00C0
#define DMA_2_C1    0x00C1
#define DMA_2_C2    0x00C2
#define DMA_2_C3    0x00C3
#define DMA_2_C4    0x00C4
#define DMA_2_C5    0x00C5
#define DMA_2_C6    0x00C6
#define DMA_2_C7    0x00C7
#define DMA_2_C8    0x00C8
#define DMA_2_C9    0x00C9
#define DMA_2_CA    0x00CA
#define DMA_2_CB    0x00CB
#define DMA_2_CC    0x00CC
#define DMA_2_CD    0x00CD
#define DMA_2_CE    0x00CE
#define DMA_2_CF    0x00CF
#define DMA_2_D0    0x00D0
#define DMA_2_D1    0x00D1
#define DMA_2_D2    0x00D2
#define DMA_2_D3    0x00D3
#define DMA_2_D4    0x00D4
#define DMA_2_D5    0x00D5
#define DMA_2_D6    0x00D6
#define DMA_2_D7    0x00D7
#define DMA_2_D8    0x00D8
#define DMA_2_D9    0x00D9
#define DMA_2_DA    0x00DA
#define DMA_2_DB    0x00DB
#define DMA_2_DC    0x00DC
#define DMA_2_DD    0x00DD
#define DMA_2_DE    0x00DE
#define DMA_2_DF    0x00DF

//port e9 hack
#define PORT_E9     0x00E9

//secondary ATA harddisk controller
#define ATA_2_170   0x0170
#define ATA_2_171   0x0171
#define ATA_2_172   0x0172
#define ATA_2_173   0x0173
#define ATA_2_174   0x0174
#define ATA_2_175   0x0175
#define ATA_2_176   0x0176
#define ATA_2_177   0x0177

//primary ATA harddisk controller
#define ATA_1_1F0   0x01F0
#define ATA_1_1F1   0x01F1
#define ATA_1_1F2   0x01F2
#define ATA_1_1F3   0x01F3
#define ATA_1_1F4   0x01F4
#define ATA_1_1F5   0x01F5
#define ATA_1_1F6   0x01F6
#define ATA_1_1F7   0x01F7


//parallel port
#define PARLL_278   0x0278
#define PARLL_279   0x0279
#define PARLL_27A   0x027A

//second serial port
#define SERIAL2_2F8  0x02F8
#define SERIAL2_2F9  0x02F9
#define SERIAL2_2FA  0x02FA
#define SERIAL2_2FB  0x02FB
#define SERIAL2_2FC  0x02FC
#define SERIAL2_2FD  0x02FD
#define SERIAL2_2FE  0x02FE
#define SERIAL2_2FF  0x02FF

//vga port
#define VGA_IOPORT_START    0x03B0
#define VGA_IOPORT_END      0x03DF

//floppy disk controller
#define FLOPPY_3F0  0x03F0
#define FLOPPY_3F1  0x03F1
#define FLOPPY_3F2  0x03F2
#define FLOPPY_3F3  0x03F3
#define FLOPPY_3F4  0x03F4
#define FLOPPY_3F5  0x03F5
#define FLOPPY_3F6  0x03F6
#define FLOPPY_3F7  0x03F7

//first serial port
#define SERIAL1_3F8  0x03F8
#define SERIAL1_3F9  0x03F9
#define SERIAL1_3FA  0x03FA
#define SERIAL1_3FB  0x03FB
#define SERIAL1_3FC  0x03FC
#define SERIAL1_3FD  0x03FD
#define SERIAL1_3FE  0x03FE
#define SERIAL1_3FF  0x03FF

#endif