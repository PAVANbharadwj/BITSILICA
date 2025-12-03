#ifndef INC_W25QXX_H_
#define INC_W25QXX_H_

#include <stdint.h>
#include <stdbool.h>

/* RESET + ID */
void W25Q_RESET(void);
uint32_t W25_ReadID(void);

/* Read / Write */
void W25q_Read(uint32_t startpage, uint8_t offset, uint32_t size, uint8_t *rData);
void flash_write(uint32_t page, uint16_t offset, uint32_t size, uint8_t *tdata);

/* Erase & Status */
void Flash_Erase_Sector(uint16_t sector);
void write_enable(void);
void write_disable(void);
uint8_t Flash_ReadStatus(void);

/* Helpers */
uint32_t bytes_to_write(uint32_t size, uint16_t offset);
uint32_t bytes_to_modify(uint32_t size, uint16_t offset);
void Flash_Write_Update(uint32_t Page, uint16_t offset, uint32_t size, uint8_t *data);

#endif /* INC_W25QXX_H_ */
