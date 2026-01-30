/*
 * system_stm32l4xx.c
 *
 *  Created on: Nov 20, 2025
 *      Author: pavan
 */


#include "stm32l476xx.h"

/* Default MSI clock = 4 MHz */
uint32_t SystemCoreClock = 4000000UL;

void SystemInit(void)
{
    /* Enable FPU (optional, but safe) */
    SCB->CPACR |= (0xF << 20);

    /* Keep MSI ON (default at reset = 4 MHz) */

    /* Update global variable */
    SystemCoreClock = 4000000UL;
}

void SystemCoreClockUpdate(void)
{
    /* Since we keep MSI at 4 MHz, just set */
    SystemCoreClock = 4000000UL;
}
