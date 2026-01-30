/*
 * systick.c
 *
 *  Created on: Nov 20, 2025
 *      Author: pavan
 */


#include "systick.h"
#include "stm32l476xx.h"

static volatile uint32_t ms_ticks = 0;

/* Configure Systick for 1MHz tick (1us) if CPU clock ~ 16MHz default MSI.
   For portability, implement a basic SysTick using CPU freq approx:
   We'll configure SysTick to generate 1ms interrupts and use DWT for microsecond if available,
   but to keep it simple and reliable in bare metal, we'll use a busy-wait loop calibrated with CPU cycles.
   For clarity: We'll implement a SysTick that increments ms_ticks each ms. delay_us uses a simple loop.
*/

void Systick_Init(void)
{
    /* Configure SysTick for 1ms tick using system core clock */
    /* Assume SystemCoreClock is defined; fallback to 16000000 */
#ifdef SystemCoreClock
    uint32_t core = SystemCoreClock;
#else
    uint32_t core = 16000000U;
#endif
    SysTick->LOAD = (core/1000U) - 1U;
    SysTick->VAL = 0;
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
    /* enable SysTick IRQ in NVIC */
    NVIC_SetPriority(SysTick_IRQn, 3);
}

void SysTick_Handler(void)
{
    ms_ticks++;
}

void delay_ms(uint32_t ms)
{
    uint32_t start = ms_ticks;
    while((ms_ticks - start) < ms) { __WFI(); }
}

/* simple microsecond delay using loop calibrated with rough cycles (approx). For better accuracy use DWT. */
void delay_us(uint32_t us)
{
    /* approx NOP loops; tuned for 16MHz ~ 4 cycles per loop -> adjust if inaccurate */
    volatile uint32_t count = us * 16U / 5U;
    while(count--) __asm volatile ("nop");
}

uint32_t millis(void) { return ms_ticks; }
