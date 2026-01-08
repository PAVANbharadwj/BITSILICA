#ifndef FLASH_LOWLEVEL_H
#define FLASH_LOWLEVEL_H

#include "main.h"
#include <stdint.h>

void FlashLL_Init(void);
void FlashLL_WriteEnable(void);
uint8_t FlashLL_ReadStatus(void);
void FlashLL_WaitWhileBusy(void);
void FlashLL_SectorErase(uint32_t addr);               // 4KB sector
void FlashLL_PageProgram(uint32_t addr, const uint8_t *data, uint16_t len);
void FlashLL_ReadData(uint32_t addr, uint8_t *data, uint16_t len);

#endif // FLASH_LOWLEVEL_H
