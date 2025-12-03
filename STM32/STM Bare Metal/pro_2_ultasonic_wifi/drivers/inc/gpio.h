/*
 * gpio.h
 *
 *  Created on: Nov 20, 2025
 *      Author: pavan
 */

#ifndef GPIO_H
#define GPIO_H
#include <stdint.h>
#include "stm32l476xx.h"

void GPIOA_Config_Output(uint32_t pin);
void GPIOA_Config_Input(uint32_t pin);
void GPIOA_WritePin(uint32_t pin, uint8_t val);
uint8_t GPIOA_ReadPin(uint32_t pin);
#endif

