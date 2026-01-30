/*
 * timer_ic.h
 *
 *  Created on: Nov 20, 2025
 *      Author: pavan
 */

#ifndef TIMER_IC_H
#define TIMER_IC_H
#include <stdint.h>

void TIM3_IC_Init(void);
uint32_t TIM3_GetCapture_us(void);
void TIM3_StartCapture(void);
void TIM3_StopCapture(void);
uint32_t TIM3_WaitForRisingThenFalling_us(uint32_t timeout_ms);

#endif

