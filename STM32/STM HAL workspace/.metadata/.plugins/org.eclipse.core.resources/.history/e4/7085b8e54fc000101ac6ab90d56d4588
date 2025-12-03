#include "stm32f4xx_hal.h"
#include "adc.h"

void SysTick_Handler(void)
{
    HAL_IncTick();
}

int main(void)
{
    HAL_Init();
    ADC1_Init();
    ADC1_Start();

    while (1)
    {
        // adc_value is automatically updated in interrupt
        HAL_Delay(500);
        // You can inspect adc_value in Live Expressions
    }
}
