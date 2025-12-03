/*
 * bmi160.h
 *
 *  Created on: Nov 27, 2025
 *      Author: pavan
 */

#ifndef BMI160_H_
#define BMI160_H_

#include "stm32l4xx_hal.h"     // change for your MCU
#include <stdint.h>

#define BMI160_I2C_ADDR        0x69   // 7-bit

// Registers from your list
#define BMI160_CHIPID          0x00
#define BMI160_MAG_X_REG       0x04
#define BMI160_STATUS_REG      0x1B
#define BMI160_CMD_REG         0x7E

#define BMI_GYRO_X_REG         0x0C
#define BMI_GYRO_Y_REG         0x0E
#define BMI_GYRO_Z_REG         0x10

#define BMI_ACCEL_X_REG        0x12
#define BMI_ACCEL_Y_REG        0x14
#define BMI_ACCEL_Z_REG        0x16

// PMU mode commands
#define BMI160_CMD_ACC_NORMAL  0x11
#define BMI160_CMD_GYR_NORMAL  0x15

typedef struct {
    float ax, ay, az;   // g
    float gx, gy, gz;   // deg/sec
} BMI160_Data;

void BMI160_Init(I2C_HandleTypeDef *hi2c);
void BMI160_Read(BMI160_Data *out);

#endif

