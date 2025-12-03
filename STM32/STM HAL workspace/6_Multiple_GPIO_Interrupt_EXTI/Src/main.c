#include "stm32f4xx_hal.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#define BTN_PORT  GPIOC
#define BTN_PIN   GPIO_PIN_13
#define BTN2_PORT GPIOA
#define BTN2_PIN  GPIO_PIN_0
#define LED_PORT  GPIOA
#define LED_PIN   GPIO_PIN_5

void gpio_interrupt_init(void);

int main(void)
{
    HAL_Init();
    gpio_interrupt_init();



    while (1)
    {

    }
}

void SysTick_Handler(void)
{
    HAL_IncTick();
}

void gpio_interrupt_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    // PC13 as EXTI (Button 1)
    GPIO_InitStruct.Pin = BTN_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING; // active low button
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(BTN_PORT, &GPIO_InitStruct);

    // PA0 as EXTI (Button 2)
    GPIO_InitStruct.Pin = BTN2_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(BTN2_PORT, &GPIO_InitStruct);

    // PA5 as LED output
    GPIO_InitStruct.Pin = LED_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(LED_PORT, &GPIO_InitStruct);

    // Enable NVIC interrupts
    HAL_NVIC_SetPriority(EXTI0_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(EXTI0_IRQn);

    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

// === EXTI Callback (called for both buttons) ===
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == GPIO_PIN_13)
    {
        HAL_GPIO_TogglePin(LED_PORT, LED_PIN);
        printf("Button on PC13 pressed!\r\n");
    }
    else if (GPIO_Pin == GPIO_PIN_0)
    {
        HAL_GPIO_TogglePin(LED_PORT, LED_PIN);
        printf("Button on PA0 pressed!\r\n");
    }
}

// === Interrupt Handlers ===
void EXTI0_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
}

void EXTI15_10_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
}


