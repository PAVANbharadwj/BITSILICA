#ifndef __ADC_H
#define __ADC_H

#include "stm32f4xx_hal.h"

extern ADC_HandleTypeDef hadc1;
extern volatile uint32_t adc_value;  // Updated via interrupt

void ADC1_Init(void);                // Initialize ADC1
void ADC1_Start(void);               // Start conversion in interrupt mode

#endif
