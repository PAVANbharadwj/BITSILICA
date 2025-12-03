/*
 * gpio.c
 *
 *  Created on: Nov 20, 2025
 *      Author: pavan
 */


#include "gpio.h"

void GPIOA_Config_Output(uint32_t pin)
{
    uint32_t pos = pin;
    /* moder: 01 -> general purpose output */
    GPIOA->MODER &= ~(0x3 << (pos*2));
    GPIOA->MODER |=  (0x1 << (pos*2));
    /* push-pull default */
    GPIOA->OTYPER &= ~(1 << pos);
    /* speed: medium */
    GPIOA->OSPEEDR &= ~(0x3 << (pos*2));
    GPIOA->OSPEEDR |=  (0x1 << (pos*2));
    /* no pull-up/down */
    GPIOA->PUPDR &= ~(0x3 << (pos*2));
}

void GPIOA_Config_Input(uint32_t pin)
{
    uint32_t pos = pin;
    GPIOA->MODER &= ~(0x3 << (pos*2)); /* 00 = input */
    GPIOA->PUPDR &= ~(0x3 << (pos*2));
}

void GPIOA_WritePin(uint32_t pin, uint8_t val)
{
    if(val) GPIOA->BSRR = (1U << pin);
    else    GPIOA->BSRR = (1U << (pin + 16));
}

uint8_t GPIOA_ReadPin(uint32_t pin)
{
    return (GPIOA->IDR & (1U << pin)) ? 1 : 0;
}
