#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "stm32l4xx_hal.h"

void Ultrasonic_Init(TIM_HandleTypeDef *htim, GPIO_TypeDef* trig_port, uint16_t trig_pin);
uint32_t Ultrasonic_Measure(void); // returns distance in cm or 0xFFFFFFFF on timeout

void DWT_Delay_Init(void);
void DWT_Delay_us(uint32_t us);

void Ultrasonic_IC_CaptureCallback(TIM_HandleTypeDef *htim);

#endif // ULTRASONIC_H
