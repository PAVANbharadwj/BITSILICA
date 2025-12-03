/*
 * bme280.c
 *
 *  Created on: Nov 26, 2025
 *      Author: pavan
 */


#include "bme280.h"

// Local copy of I2C handle
static I2C_HandleTypeDef *bme_i2c;

// Compensation variables
static uint16_t dig_T1;
static int16_t  dig_T2, dig_T3;
static uint16_t dig_P1;
static int16_t  dig_P2, dig_P3, dig_P4, dig_P5, dig_P6, dig_P7, dig_P8, dig_P9;
static uint8_t  dig_H1, dig_H3;
static int16_t  dig_H2, dig_H4, dig_H5;
static int8_t   dig_H6;

static int32_t t_fine;

/* ----------------------------------------- */
/*        Low-Level I2C Helpers              */
/* ----------------------------------------- */

static void bme_write8(uint8_t reg, uint8_t value)
{
    uint8_t buf[2] = { reg, value };
    HAL_I2C_Master_Transmit(bme_i2c, BME280_I2C_ADDR << 1, buf, 2, HAL_MAX_DELAY);
}

static void bme_read(uint8_t reg, uint8_t *buf, uint8_t len)
{
    HAL_I2C_Master_Transmit(bme_i2c, BME280_I2C_ADDR << 1, &reg, 1, HAL_MAX_DELAY);
    HAL_I2C_Master_Receive(bme_i2c, BME280_I2C_ADDR << 1, buf, len, HAL_MAX_DELAY);
}

/* ----------------------------------------- */
/*         Read Calibration Tables           */
/* ----------------------------------------- */

static void bme_read_calib(void)
{
    uint8_t buf1[26];
    bme_read(0x88, buf1, 26);

    dig_T1 = (buf1[1] << 8) | buf1[0];
    dig_T2 = (buf1[3] << 8) | buf1[2];
    dig_T3 = (buf1[5] << 8) | buf1[4];

    dig_P1 = (buf1[7] << 8) | buf1[6];
    dig_P2 = (buf1[9] << 8) | buf1[8];
    dig_P3 = (buf1[11] << 8) | buf1[10];
    dig_P4 = (buf1[13] << 8) | buf1[12];
    dig_P5 = (buf1[15] << 8) | buf1[14];
    dig_P6 = (buf1[17] << 8) | buf1[16];
    dig_P7 = (buf1[19] << 8) | buf1[18];
    dig_P8 = (buf1[21] << 8) | buf1[20];
    dig_P9 = (buf1[23] << 8) | buf1[22];

    dig_H1 = buf1[25];

    uint8_t buf2[7];
    bme_read(0xE1, buf2, 7);

    dig_H2 = (buf2[1] << 8) | buf2[0];
    dig_H3 = buf2[2];
    dig_H4 = (buf2[3] << 4) | (buf2[4] & 0x0F);
    dig_H5 = (buf2[5] << 4) | (buf2[4] >> 4);
    dig_H6 = buf2[6];
}

/* ----------------------------------------- */
/*              Init BME280                  */
/* ----------------------------------------- */

void BME280_Init(I2C_HandleTypeDef *hi2c)
{
    bme_i2c = hi2c;

    // Reset
    bme_write8(0xE0, 0xB6);
    HAL_Delay(5);

    // Humidity oversampling ×1
    bme_write8(0xF2, 0x01);

    // Normal mode, T/P oversampling ×1
    bme_write8(0xF4, 0x27);

    // Standby 1000ms
    bme_write8(0xF5, 0xA0);

    bme_read_calib();
}

/* ----------------------------------------- */
/*             Compensation Code             */
/* ----------------------------------------- */

static float bme_read_temperature(int32_t adc_T)
{
    int32_t var1, var2;
    var1 = ((((adc_T >> 3) - ((int32_t)dig_T1 << 1))) * dig_T2) >> 11;
    var2 = (((((adc_T >> 4) - dig_T1) *
              ((adc_T >> 4) - dig_T1)) >> 12) *
              dig_T3) >> 14;

    t_fine = var1 + var2;
    float T = (t_fine * 5 + 128) >> 8;
    return T / 100.0f;
}

static float bme_read_pressure(int32_t adc_P)
{
    int64_t var1, var2, p;

    var1 = (int64_t)t_fine - 128000;
    var2 = var1 * var1 * dig_P6;
    var2 += (var1 * dig_P5) * 131072;
    var2 += ((int64_t)dig_P4) * 34359738368LL;

    var1 = ((var1 * var1 * dig_P3) >> 8) + ((var1 * dig_P2) << 12);
    var1 = (((((int64_t)1) << 47) + var1)) * dig_P1 >> 33;

    if (var1 == 0) return 0;

    p = 1048576 - adc_P;
    p = (((p << 31) - var2) * 3125) / var1;

    var1 = (dig_P9 * (p >> 13) * (p >> 13)) >> 25;
    var2 = (dig_P8 * p) >> 19;

    p = ((p + var1 + var2) >> 8) + ((int64_t)dig_P7 << 4);

    return (float)p / 256.0f;
}

static float bme_read_humidity(int32_t adc_H)
{
    int32_t v_x1 = t_fine - 76800;

    v_x1 = (((((adc_H << 14) -
               (dig_H4 << 20) -
               (dig_H5 * v_x1)) + 16384) >> 15) *
               (((((v_x1 * dig_H6) >> 10) *
               (((v_x1 * dig_H3) >> 11) + 32768)) >> 10) + 2097152) *
               dig_H2 + 8192) >> 14;

    v_x1 -= (((((v_x1 >> 15) * (v_x1 >> 15)) >> 7) * dig_H1) >> 4);

    if (v_x1 < 0) v_x1 = 0;
    if (v_x1 > 419430400) v_x1 = 419430400;

    return (v_x1 >> 12) / 1024.0f;
}

/* ----------------------------------------- */
/*         Read T, P, H at once              */
/* ----------------------------------------- */

void BME280_ReadData(BME280_Data *out)
{
    uint8_t raw[8];
    bme_read(0xF7, raw, 8);

    int32_t adc_P = (raw[0] << 12) | (raw[1] << 4) | (raw[2] >> 4);
    int32_t adc_T = (raw[3] << 12) | (raw[4] << 4) | (raw[5] >> 4);
    int32_t adc_H = (raw[6] << 8)  | raw[7];

    out->temperature = bme_read_temperature(adc_T);
    out->pressure    = bme_read_pressure(adc_P);
    out->humidity    = bme_read_humidity(adc_H);
}
