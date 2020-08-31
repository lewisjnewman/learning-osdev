#ifndef ATA_H
#define ATA_H

//sectors are usually 512 bytes
#define SECTOR_SIZE 512

void ATA_PIO_read_sectors(void* dst, uint32_t start, uint8_t num);
void ATA_PIO_write_sectors(void* src, uint32_t start, uint8_t num);

#endif