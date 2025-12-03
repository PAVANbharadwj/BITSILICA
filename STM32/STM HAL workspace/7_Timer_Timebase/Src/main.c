#include "stm32f4xx_hal.h"

#include <stdio.h>
#include"uart.h"
#include "tim.h"




int main(void)
{
    HAL_Init();
    tim_timebase_init();
    uart_init();


    while (1)
    {
    	printf("A second elasped\r\n");
    }
}

void SysTick_Handler(void)
{
    HAL_IncTick();
}




