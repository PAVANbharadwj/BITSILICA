#include "stm32f4xx_hal.h"
#include "adc.h"

volatile uint32_t adc_value = 0;

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
        adc_value = ADC1_ReadValue();   // continuously updated
        HAL_Delay(100);
    }
}
