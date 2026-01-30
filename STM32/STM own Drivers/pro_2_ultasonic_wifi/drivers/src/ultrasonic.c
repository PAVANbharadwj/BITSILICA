/*
 * ultrasonic.c
 *
 *  Created on: Nov 20, 2025
 *      Author: pavan
 */


#include "ultrasonic.h"
#include "gpio.h"
#include "timer_ic.h"
#include "systick.h"
#include "stm32l476xx.h"
#include "rcc.h"


/* TRIG -> PA5, ECHO handled by TIM3 CH1 on PA6 */
#define TRIG_PIN 5

void Ultrasonic_Init(void)
{
    RCC_EnableGPIOA();
    GPIOA_Config_Output(TRIG_PIN);
    GPIOA_WritePin(TRIG_PIN, 0);
    TIM3_IC_Init();
}

/* Send 10us pulse on TRIG, capture echo width in us, convert to cm */
uint32_t Ultrasonic_ReadDistance_cm(void)
{
    /* trigger */
    GPIOA_WritePin(TRIG_PIN, 0);
    delay_us(2);
    GPIOA_WritePin(TRIG_PIN, 1);
    delay_us(10);
    GPIOA_WritePin(TRIG_PIN, 0);

    /* Wait for echo via TIM3 polling helper */
    uint32_t width_us = TIM3_WaitForRisingThenFalling_us(60); /* max timeout 60ms ~ 10m */
    if(width_us == 0) return 0;
    /* distance = (time_us * speed_of_sound_cm_per_us)/2; speed ~0.0343 cm/us -> 0.0343*? Wait we want cm so:
       speed = 343 m/s = 34300 cm/s -> 0.0343 cm/us. So:
       distance_cm = width_us * 0.0343 / 2
       To avoid floats: multiply and divide: (width_us * 343) / (2 * 10000) -> but clearer use float.
    */
    float dist = (width_us * 0.0343f) / 2.0f;
    return (uint32_t)(dist + 0.5f);
}
