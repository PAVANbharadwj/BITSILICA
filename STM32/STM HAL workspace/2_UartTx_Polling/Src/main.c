#include "stm32f4xx_hal.h"
#include <string.h>

UART_HandleTypeDef huart1;

void uart_init(void);

char tx_message[] = "Hello STM32\r\n";
uint8_t rx_buffer[50];
uint8_t rx_index = 0;

int main(void)
{
    HAL_Init();
    uart_init();

    HAL_UART_Transmit(&huart1, (uint8_t *)tx_message, strlen(tx_message), 100);

    while (1)
    {
        // Transmit one character at a time
        for (uint8_t i = 0; i < strlen(tx_message); i++)
        {
            HAL_UART_Transmit(&huart1, (uint8_t *)&tx_message[i], 1, 100);
            HAL_UART_Receive(&huart1, &rx_buffer[rx_index], 1, 100);
            rx_index++;
        }

        // Delay before sending again
        HAL_Delay(1000);
    }
}

// SysTick handler (required by HAL)
void SysTick_Handler(void)
{
    HAL_IncTick();
}

// === USART1 Initialization ===
void uart_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_USART1_CLK_ENABLE();

    // PA9 -> TX, PA10 -> RX
    GPIO_InitStruct.Pin = GPIO_PIN_9 | GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    huart1.Instance = USART1;
    huart1.Init.BaudRate = 115200;
    huart1.Init.WordLength = UART_WORDLENGTH_8B;
    huart1.Init.StopBits = UART_STOPBITS_1;
    huart1.Init.Parity = UART_PARITY_NONE;
    huart1.Init.Mode = UART_MODE_TX_RX;
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;

    HAL_UART_Init(&huart1);
}
