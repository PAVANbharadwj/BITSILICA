#include "stm32f4xx_hal.h"
#include "led.h"


void pa5_led_init(void){
	 GPIO_InitTypeDef GPIO_InitStruct = {0};

	 __HAL_RCC_GPIOA_CLK_ENABLE();

	 // PA5 as LED output
	GPIO_InitStruct.Pin = LED_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(LED_PORT, &GPIO_InitStruct);
}
