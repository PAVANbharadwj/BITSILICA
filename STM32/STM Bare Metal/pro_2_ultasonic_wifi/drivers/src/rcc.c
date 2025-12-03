/*
 * rcc.c
 *
 *  Created on: Nov 20, 2025
 *      Author: pavan
 */


#include "rcc.h"

/* Minimal clock setup: leave default MSI or HSI. Only enable peripheral clocks used. */
void RCC_InitSystemClock(void)
{
    /* For simplicity, keep default clock (MSI). */
}

/* Peripheral enables */
void RCC_EnableGPIOA(void) { RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN; __DSB(); }
void RCC_EnableUSART2(void) { RCC->APB1ENR1 |= RCC_APB1ENR1_USART2EN; __DSB(); }
void RCC_EnableTIM3(void) { RCC->APB1ENR1 |= RCC_APB1ENR1_TIM3EN; __DSB(); }
