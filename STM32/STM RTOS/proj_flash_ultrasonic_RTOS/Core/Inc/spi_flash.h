/*
 * spi_flash.h
 *
 *  Created on: Dec 10, 2025
 *      Author: pavan
 */

#ifndef SPI_FLASH_H
#define SPI_FLASH_H

#include "main.h"
#include <stdint.h>

typedef struct {
    uint8_t  manufacturer;
    uint8_t  memory_type;
    uint8_t  capacity_code;
    uint32_t size_bytes;   // computed from capacity_code
    uint32_t sector_size;  // 4 KB
    uint32_t page_size;    // 256 B
} SPIFlash_Info_t;

void SPIFlash_Init(SPIFlash_Info_t *info);

void SPIFlash_EraseSector(uint32_t addr);                 // 4 KB
void SPIFlash_WritePage(uint32_t addr, const uint8_t *data, uint16_t len);
void SPIFlash_Read(uint32_t addr, uint8_t *data, uint32_t len);

#endif // SPI_FLASH_H

