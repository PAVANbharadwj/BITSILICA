#include "ultrasonic.h"

static TIM_HandleTypeDef *hTim_local;
static GPIO_TypeDef* TRIG_PORT;
static uint16_t TRIG_PIN;

static volatile uint32_t ic_rising = 0;
static volatile uint32_t ic_falling = 0;
static volatile uint8_t capture_done = 0;

void DWT_Delay_Init(void)
{
    if (!(CoreDebug->DEMCR & CoreDebug_DEMCR_TRCENA_Msk))
        CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;

    DWT->CYCCNT = 0;
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
}

void DWT_Delay_us(uint32_t microseconds)
{
    uint32_t cycles = (HAL_RCC_GetHCLKFreq() / 1000000UL) * microseconds;
    uint32_t start = DWT->CYCCNT;
    while ((DWT->CYCCNT - start) < cycles) {}
}

void Ultrasonic_Init(TIM_HandleTypeDef *htim, GPIO_TypeDef* trig_port, uint16_t trig_pin)
{
    hTim_local = htim;
    TRIG_PORT  = trig_port;
    TRIG_PIN   = trig_pin;
}

uint32_t Ultrasonic_Measure(void)
{
    capture_done = 0;
    ic_rising = ic_falling = 0;

    /* send 10us trigger pulse */
    HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_SET);
    DWT_Delay_us(10);
    HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET);

    uint32_t start = HAL_GetTick();
    while (!capture_done)
    {
        if (HAL_GetTick() - start > 100)
            return 0xFFFFFFFF;
    }

    uint32_t ticks;
    if (ic_falling >= ic_rising)
        ticks = ic_falling - ic_rising;
    else
        ticks = (0xFFFF - ic_rising) + ic_falling + 1;

    uint32_t echo_us = ticks; // timer = 1MHz => 1 tick = 1µs
    uint32_t distance_cm = (echo_us * 343UL) / 2000UL;

    return distance_cm;
}

void Ultrasonic_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance != TIM3)
        return;

    static uint8_t rising = 1;
    uint32_t val = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);

    if (rising)
    {
        ic_rising = val;
        __HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
        rising = 0;
    }
    else
    {
        ic_falling = val;
        __HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
        rising = 1;
        capture_done = 1;
    }
}
