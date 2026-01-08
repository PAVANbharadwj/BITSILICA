#include "flash_lowlevel.h"
#include "stm32l4xx_hal.h"

extern SPI_HandleTypeDef hspi1;

#define CMD_WRITE_ENABLE    0x06
#define CMD_READ_STATUS     0x05
#define CMD_SECTOR_ERASE    0x20   // 4KB
#define CMD_PAGE_PROGRAM    0x02
#define CMD_READ_DATA       0x03

static void CS_LOW(void)
{
    HAL_GPIO_WritePin(FLASH_CS_GPIO_Port, FLASH_CS_Pin, GPIO_PIN_RESET);
}

static void CS_HIGH(void)
{
    HAL_GPIO_WritePin(FLASH_CS_GPIO_Port, FLASH_CS_Pin, GPIO_PIN_SET);
}

void FlashLL_Init(void)
{
    // nothing special, SPI already init; just ensure CS high
    CS_HIGH();
}

void FlashLL_WriteEnable(void)
{
    uint8_t cmd = CMD_WRITE_ENABLE;
    CS_LOW();
    HAL_SPI_Transmit(&hspi1, &cmd, 1, HAL_MAX_DELAY);
    CS_HIGH();
}

uint8_t FlashLL_ReadStatus(void)
{
    uint8_t cmd = CMD_READ_STATUS;
    uint8_t status = 0;

    CS_LOW();
    HAL_SPI_Transmit(&hspi1, &cmd, 1, HAL_MAX_DELAY);
    HAL_SPI_Receive(&hspi1, &status, 1, HAL_MAX_DELAY);
    CS_HIGH();
    return status;
}

void FlashLL_WaitWhileBusy(void)
{
    while (FlashLL_ReadStatus() & 0x01) // BUSY bit
    {
        // small delay optional
    }
}

void FlashLL_SectorErase(uint32_t addr)
{
    uint8_t buf[4];
    buf[0] = CMD_SECTOR_ERASE;
    buf[1] = (addr >> 16) & 0xFF;
    buf[2] = (addr >> 8) & 0xFF;
    buf[3] = addr & 0xFF;

    FlashLL_WriteEnable();
    CS_LOW();
    HAL_SPI_Transmit(&hspi1, buf, 4, HAL_MAX_DELAY);
    CS_HIGH();

    FlashLL_WaitWhileBusy();
}

void FlashLL_PageProgram(uint32_t addr, const uint8_t *data, uint16_t len)
{
    uint8_t hdr[4];
    hdr[0] = CMD_PAGE_PROGRAM;
    hdr[1] = (addr >> 16) & 0xFF;
    hdr[2] = (addr >> 8) & 0xFF;
    hdr[3] = addr & 0xFF;

    FlashLL_WriteEnable();
    CS_LOW();
    HAL_SPI_Transmit(&hspi1, hdr, 4, HAL_MAX_DELAY);
    HAL_SPI_Transmit(&hspi1, (uint8_t*)data, len, HAL_MAX_DELAY);
    CS_HIGH();

    FlashLL_WaitWhileBusy();
}

void FlashLL_ReadData(uint32_t addr, uint8_t *data, uint16_t len)
{
    uint8_t hdr[4];
    hdr[0] = CMD_READ_DATA;
    hdr[1] = (addr >> 16) & 0xFF;
    hdr[2] = (addr >> 8) & 0xFF;
    hdr[3] = addr & 0xFF;

    CS_LOW();
    HAL_SPI_Transmit(&hspi1, hdr, 4, HAL_MAX_DELAY);
    HAL_SPI_Receive(&hspi1, data, len, HAL_MAX_DELAY);
    CS_HIGH();
}
