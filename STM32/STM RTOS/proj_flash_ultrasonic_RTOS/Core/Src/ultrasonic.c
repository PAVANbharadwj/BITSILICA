#include "ultrasonic.h"
#include "stm32l4xx_hal.h"

static void DWT_Init(void);
static void Delay_us(uint32_t us);

static void DWT_Init(void)
{
    if (!(CoreDebug->DEMCR & CoreDebug_DEMCR_TRCENA_Msk))
    {
        CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    }

    DWT->CYCCNT = 0;
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
}

static void Delay_us(uint32_t us)
{
    uint32_t cpu_freq = HAL_RCC_GetHCLKFreq();
    uint32_t cycles = (cpu_freq / 1000000U) * us;
    uint32_t start = DWT->CYCCNT;
    while ((DWT->CYCCNT - start) < cycles)
    {
        // busy wait
    }
}

void Ultrasonic_Init(void)
{
    DWT_Init();
    HAL_GPIO_WritePin(TRIG_GPIO_Port, TRIG_Pin, GPIO_PIN_RESET);
}

/**
 * Blocking measurement:
 *  - Sends 10us TRIG pulse
 *  - Measures ECHO high time using DWT cycle counter
 */
uint16_t Ultrasonic_MeasureDistance(void)
{
    uint32_t timeout_ms = 50;
    uint32_t startTick;
    uint32_t startCycles, pulseCycles, pulseUs;
    float distance;

    // Ensure TRIG low
    HAL_GPIO_WritePin(TRIG_GPIO_Port, TRIG_Pin, GPIO_PIN_RESET);
    Delay_us(2);

    // 10 us trigger pulse
    HAL_GPIO_WritePin(TRIG_GPIO_Port, TRIG_Pin, GPIO_PIN_SET);
    Delay_us(10);
    HAL_GPIO_WritePin(TRIG_GPIO_Port, TRIG_Pin, GPIO_PIN_RESET);

    // Wait for ECHO rising edge
    startTick = HAL_GetTick();
    while (HAL_GPIO_ReadPin(ECHO_GPIO_Port, ECHO_Pin) == GPIO_PIN_RESET)
    {
        if ((HAL_GetTick() - startTick) > timeout_ms)
        {
            return 0xFFFF; // timeout
        }
    }

    // Measure high time
    startCycles = DWT->CYCCNT;
    startTick = HAL_GetTick();
    while (HAL_GPIO_ReadPin(ECHO_GPIO_Port, ECHO_Pin) == GPIO_PIN_SET)
    {
        if ((HAL_GetTick() - startTick) > timeout_ms)
        {
            return 0xFFFF; // timeout
        }
    }
    pulseCycles = DWT->CYCCNT - startCycles;

    pulseUs = pulseCycles / (HAL_RCC_GetHCLKFreq() / 1000000U);

    // distance(cm) = (time * 0.0343) / 2
    distance = (pulseUs * 0.0343f) / 2.0f;

    if (distance < 2.0f || distance > 400.0f)
    {
        return 0xFFFF;
    }

    return (uint16_t)distance;
}
