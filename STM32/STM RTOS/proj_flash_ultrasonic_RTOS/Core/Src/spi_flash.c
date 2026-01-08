#include "spi_flash.h"
#include "stm32l4xx_hal.h"

extern SPI_HandleTypeDef hspi1;

/* W25Qxx commands */
#define CMD_READ_ID        0x9F
#define CMD_WRITE_ENABLE   0x06
#define CMD_READ_STATUS1   0x05
#define CMD_SECTOR_ERASE   0x20    // 4 KB
#define CMD_PAGE_PROGRAM   0x02
#define CMD_READ_DATA      0x03

static void CS_LOW(void)
{
    HAL_GPIO_WritePin(FLASH_CS_GPIO_Port, FLASH_CS_Pin, GPIO_PIN_RESET);
}

static void CS_HIGH(void)
{
    HAL_GPIO_WritePin(FLASH_CS_GPIO_Port, FLASH_CS_Pin, GPIO_PIN_SET);
}

static void SPIFlash_WriteEnable(void)
{
    uint8_t cmd = CMD_WRITE_ENABLE;
    CS_LOW();
    HAL_SPI_Transmit(&hspi1, &cmd, 1, HAL_MAX_DELAY);
    CS_HIGH();
}

static uint8_t SPIFlash_ReadStatus1(void)
{
    uint8_t cmd = CMD_READ_STATUS1;
    uint8_t status = 0;

    CS_LOW();
    HAL_SPI_Transmit(&hspi1, &cmd, 1, HAL_MAX_DELAY);
    HAL_SPI_Receive(&hspi1, &status, 1, HAL_MAX_DELAY);
    CS_HIGH();
    return status;
}

static void SPIFlash_WaitBusy(void)
{
    while (SPIFlash_ReadStatus1() & 0x01) {
        // BUSY bit set
    }
}

void SPIFlash_Init(SPIFlash_Info_t *info)
{
    uint8_t cmd = CMD_READ_ID;
    uint8_t id[3] = {0};

    CS_HIGH(); // idle
    HAL_Delay(1);

    CS_LOW();
    HAL_SPI_Transmit(&hspi1, &cmd, 1, HAL_MAX_DELAY);
    HAL_SPI_Receive(&hspi1, id, 3, HAL_MAX_DELAY);
    CS_HIGH();

    if (info) {
        info->manufacturer  = id[0];
        info->memory_type   = id[1];
        info->capacity_code = id[2];
        // Winbond capacity code: size_bytes = 1 << capacity_code
        info->size_bytes    = (id[2] < 32) ? (1UL << id[2]) : 0;
        info->sector_size   = 4096U;
        info->page_size     = 256U;
    }
}

void SPIFlash_EraseSector(uint32_t addr)
{
    uint8_t buf[4];

    buf[0] = CMD_SECTOR_ERASE;
    buf[1] = (addr >> 16) & 0xFF;
    buf[2] = (addr >> 8)  & 0xFF;
    buf[3] =  addr        & 0xFF;

    SPIFlash_WriteEnable();

    CS_LOW();
    HAL_SPI_Transmit(&hspi1, buf, 4, HAL_MAX_DELAY);
    CS_HIGH();

    SPIFlash_WaitBusy();
}

void SPIFlash_WritePage(uint32_t addr, const uint8_t *data, uint16_t len)
{
    uint8_t hdr[4];

    if (len == 0 || len > 256) return;

    hdr[0] = CMD_PAGE_PROGRAM;
    hdr[1] = (addr >> 16) & 0xFF;
    hdr[2] = (addr >> 8)  & 0xFF;
    hdr[3] =  addr        & 0xFF;

    SPIFlash_WriteEnable();

    CS_LOW();
    HAL_SPI_Transmit(&hspi1, hdr, 4, HAL_MAX_DELAY);
    HAL_SPI_Transmit(&hspi1, (uint8_t*)data, len, HAL_MAX_DELAY);
    CS_HIGH();

    SPIFlash_WaitBusy();
}

void SPIFlash_Read(uint32_t addr, uint8_t *data, uint32_t len)
{
    uint8_t hdr[4];

    hdr[0] = CMD_READ_DATA;
    hdr[1] = (addr >> 16) & 0xFF;
    hdr[2] = (addr >> 8)  & 0xFF;
    hdr[3] =  addr        & 0xFF;

    CS_LOW();
    HAL_SPI_Transmit(&hspi1, hdr, 4, HAL_MAX_DELAY);
    HAL_SPI_Receive(&hspi1, data, len, HAL_MAX_DELAY);
    CS_HIGH();
}

