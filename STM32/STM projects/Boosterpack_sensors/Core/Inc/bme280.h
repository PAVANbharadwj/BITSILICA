/*
 * bme280.h
 *
 *  Created on: Nov 26, 2025
 *      Author: pavan
 */

#ifndef BME280_H_
#define BME280_H_

#include "stm32l4xx_hal.h"   // change to your MCU series
#include <stdint.h>

#define BME280_I2C_ADDR    0x77   // 7-bit address

typedef struct {
    float temperature;
    float pressure;
    float humidity;
} BME280_Data;

void BME280_Init(I2C_HandleTypeDef *hi2c);
void BME280_ReadData(BME280_Data *data);

#endif
