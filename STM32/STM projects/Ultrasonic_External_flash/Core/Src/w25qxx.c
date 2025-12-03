#include "w25qxx.h"
#include "stm32l4xx_hal.h"

extern SPI_HandleTypeDef hspi2;

/* CS PIN (PB12) */
#define csLOW()   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET)
#define csHIGH()  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET)

/* ---------- SPI Helpers ---------- */

void SPI_Write(uint8_t *data, uint16_t size)
{
    HAL_SPI_Transmit(&hspi2, data, size, 100);
}

void SPI_Read(uint8_t *data, uint16_t size)
{
    HAL_SPI_Receive(&hspi2, data, size, 100);
}

/* ---------- Write Enable / Disable ---------- */

void write_enable(void)
{
    uint8_t cmd = 0x06;
    csLOW();
    SPI_Write(&cmd, 1);
    csHIGH();
}

void write_disable(void)
{
    uint8_t cmd = 0x04;
    csLOW();
    SPI_Write(&cmd, 1);
    csHIGH();
}

/* ---------- Read Status ---------- */

uint8_t Flash_ReadStatus(void)
{
    uint8_t cmd = 0x05;
    uint8_t status;

    csLOW();
    SPI_Write(&cmd, 1);
    SPI_Read(&status, 1);
    csHIGH();

    return status;
}

/* ---------- Reset Flash ---------- */

void W25Q_RESET(void)
{
    uint8_t cmd1 = 0x66;
    uint8_t cmd2 = 0x99;

    csLOW(); SPI_Write(&cmd1, 1); csHIGH();
    HAL_Delay(2);

    csLOW(); SPI_Write(&cmd2, 1); csHIGH();
    HAL_Delay(3);
}

/* ---------- Read Device ID ---------- */

uint32_t W25_ReadID(void)
{
    uint8_t cmd = 0x9F;
    uint8_t id[3];

    csLOW();
    SPI_Write(&cmd, 1);
    SPI_Read(id, 3);
    csHIGH();

    return (id[0] << 16) | (id[1] << 8) | id[2];
}

/* ---------- SECTOR ERASE (4K) ---------- */

void Flash_Erase_Sector(uint16_t sector)
{
    uint32_t addr = sector * 4096;
    uint8_t cmd[4];

    cmd[0] = 0x20;  // sector erase
    cmd[1] = (addr >> 16) & 0xFF;
    cmd[2] = (addr >> 8) & 0xFF;
    cmd[3] = addr & 0xFF;

    write_enable();

    csLOW();
    SPI_Write(cmd, 4);
    csHIGH();

    while (Flash_ReadStatus() & 0x01);

    write_disable();
}

/* ---------- Helper: Bytes Remaining in Page ---------- */

uint32_t bytes_to_write(uint32_t size, uint16_t offset)
{
    if (size + offset <= 256) return size;
    return 256 - offset;
}

/* ---------- PAGE PROGRAM WITH AUTO-SECTOR ERASE ---------- */

void flash_write(uint32_t page, uint16_t offset, uint32_t size, uint8_t *tdata)
{
    uint8_t data[260];

    /* ERASE sector before write */
    uint16_t sector = page / 16;
    Flash_Erase_Sector(sector);

    uint32_t startpage = page;
    uint32_t endpage = startpage + ((size + offset - 1) / 256);
    uint32_t numpages = endpage - startpage + 1;

    uint32_t pos = 0;

    for (uint32_t p = 0; p < numpages; p++)
    {
        uint32_t memAddr = (startpage * 256) + offset;
        uint32_t chunk = bytes_to_write(size, offset);

        write_enable();

        data[0] = 0x02;
        data[1] = (memAddr >> 16) & 0xFF;
        data[2] = (memAddr >> 8) & 0xFF;
        data[3] = memAddr & 0xFF;

        for (uint32_t j = 0; j < chunk; j++)
            data[4 + j] = tdata[pos + j];

        csLOW();
        SPI_Write(data, chunk + 4);
        csHIGH();

        while (Flash_ReadStatus() & 0x01);

        write_disable();

        pos += chunk;
        size -= chunk;
        offset = 0;
        startpage++;
    }
}

/* ---------- READ (Slow Read) ---------- */

void W25q_Read(uint32_t startpage, uint8_t offset, uint32_t size, uint8_t *rData)
{
    uint32_t memAddr = (startpage * 256) + offset;

    uint8_t cmd[4];
    cmd[0] = 0x03;
    cmd[1] = (memAddr >> 16) & 0xFF;
    cmd[2] = (memAddr >> 8) & 0xFF;
    cmd[3] = memAddr & 0xFF;

    csLOW();
    SPI_Write(cmd, 4);
    SPI_Read(rData, size);
    csHIGH();
}

/* ---------- Optional Helpers ---------- */

uint32_t bytes_to_modify(uint32_t size, uint16_t offset)
{
    return bytes_to_write(size, offset);
}

void Flash_Write_Update(uint32_t Page, uint16_t offset, uint32_t size, uint8_t *data)
{
    flash_write(Page, offset, size, data);
}
