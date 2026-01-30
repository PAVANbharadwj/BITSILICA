/*
 * systick.h
 *
 *  Created on: Nov 20, 2025
 *      Author: pavan
 */


#ifndef SYSTICK_H
#define SYSTICK_H
#include <stdint.h>

void Systick_Init(void);
void delay_us(uint32_t us);
void delay_ms(uint32_t ms);
uint32_t millis(void);
#endif
