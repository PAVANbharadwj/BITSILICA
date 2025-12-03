/*
 * timer_ic.c
 *
 *  Created on: Nov 20, 2025
 *      Author: pavan
 */


#include "timer_ic.h"
#include "rcc.h"
#include "stm32l476xx.h"
#include "systick.h"
#include "gpio.h"

/* TIM3 CH1 on PA6 AF2 for TIM3 */
void TIM3_IC_Init(void)
{
    RCC_EnableGPIOA();
    RCC_EnableTIM3();
    /* Configure PA6 as AF2 */
    GPIOA->MODER &= ~(0x3 << (6*2));
    GPIOA->MODER |=  (0x2 << (6*2)); /* AF mode */
    GPIOA->AFR[0] &= ~(0xF << (6*4));
    GPIOA->AFR[0] |=  (2 << (6*4)); /* AF2 = TIM3 */

    /* Reset TIM3 */
    TIM3->CR1 = 0;
    TIM3->PSC = 16-1; /* prescaler -> 1 MHz timer tick (assuming 16MHz core). Adjust if core freq differs. */
    TIM3->ARR = 0xFFFF;
    /* CC1 configured as input, mapped on TI1 */
    TIM3->CCMR1 &= ~TIM_CCMR1_CC1S;
    TIM3->CCMR1 |= (1 << 0); /* CC1S = 01: CC1 channel is configured as input, IC1 is mapped on TI1 */
    /* capture on rising edge by default */
    TIM3->CCER &= ~(TIM_CCER_CC1P | TIM_CCER_CC1NP);
    /* enable capture */
    TIM3->CCER |= TIM_CCER_CC1E;
    /* enable counter */
    TIM3->CR1 |= TIM_CR1_CEN;
}

static volatile uint32_t last_rise = 0;
static volatile uint32_t echo_time = 0;

uint32_t TIM3_GetCapture_us(void)
{
    return echo_time;
}

void TIM3_StartCapture(void)
{
    /* Snapshot: we'll busy poll for rising then falling edges */
    /* Clear count */
    TIM3->CNT = 0;
    last_rise = 0;
    echo_time = 0;
}

void TIM3_StopCapture(void)
{
    /* nothing specific */
}

/* Helper polling function used in ultrasonic driver to wait for edges */
uint32_t TIM3_WaitForRisingThenFalling_us(uint32_t timeout_ms)
{
    uint32_t start = millis();
    /* Wait for rising edge */
    while(!(TIM3->SR & TIM_SR_CC1IF))
    {
        if((millis() - start) > timeout_ms) return 0;
    }
    uint32_t t_rise = TIM3->CCR1;
    TIM3->SR &= ~TIM_SR_CC1IF;
    /* Wait for falling: configure to detect falling edge temporarily */
    TIM3->CCER |= TIM_CCER_CC1P; /* capture on falling (set polarity bit) */
    /* Wait for next capture */
    start = millis();
    while(!(TIM3->SR & TIM_SR_CC1IF))
    {
        if((millis() - start) > timeout_ms) { TIM3->CCER &= ~TIM_CCER_CC1P; return 0; }
    }
    uint32_t t_fall = TIM3->CCR1;
    TIM3->SR &= ~TIM_SR_CC1IF;
    /* restore rising detection */
    TIM3->CCER &= ~TIM_CCER_CC1P;
    /* compute delta (handle overflow) */
    uint32_t delta;
    if(t_fall >= t_rise) delta = t_fall - t_rise;
    else delta = (0xFFFF - t_rise) + t_fall + 1;
    /* timer tick is 1us if PSC is set accordingly */
    return delta;
}
