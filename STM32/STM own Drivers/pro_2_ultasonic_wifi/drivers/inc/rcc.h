/*
 * rcc.h
 *
 *  Created on: Nov 20, 2025
 *      Author: pavan
 */

#ifndef RCC_H
#define RCC_H
#include <stdint.h>
#include "stm32l476xx.h"

void RCC_InitSystemClock(void);
void RCC_EnableGPIOA(void);
void RCC_EnableUSART2(void);
void RCC_EnableTIM3(void);
#endif

