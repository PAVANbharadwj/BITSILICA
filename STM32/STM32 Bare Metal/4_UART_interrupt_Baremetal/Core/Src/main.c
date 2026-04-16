#include "main.h"

#define RX_BUF_SIZE 16

volatile char tx_char = 'A';
volatile char rx_buffer[RX_BUF_SIZE];
volatile uint8_t rx_index = 0;

void delay(volatile uint32_t d)
{
    while (d--);
}

void USART2_Init(void)
{
    RCC->AHB2ENR  |= (1 << 0);
    RCC->APB1ENR1 |= (1 << 17);

    GPIOA->MODER &= ~((3 << (2 * 2)) | (3 << (3 * 2)));
    GPIOA->MODER |=  ((2 << (2 * 2)) | (2 << (3 * 2)));

    GPIOA->AFR[0] &= ~((0xF << (2 * 4)) | (0xF << (3 * 4)));
    GPIOA->AFR[0] |=  ((7   << (2 * 4)) | (7   << (3 * 4)));

    USART2->CR1 = 0;
    USART2->CR2 = 0;
    USART2->CR3 = 0;

    USART2->BRR = 16000000 / 9600;

    USART2->CR1 |= (1 << 5);

    USART2->CR1 |= (1 << 3) | (1 << 2);

    USART2->CR1 |= (1 << 0);

    NVIC_EnableIRQ(USART2_IRQn);
}

void USART2_SendChar(char c)
{
    while (!(USART2->ISR & (1 << 7)));
    USART2->TDR = c;
}

void USART2_IRQHandler(void)
{
    if (USART2->ISR & (1 << 5))
    {
        rx_buffer[rx_index++] = USART2->RDR;

        if (rx_index >= RX_BUF_SIZE - 1)
            rx_index = 0;

        rx_buffer[rx_index] = '\0';
    }
}

int main(void)
{
    USART2_Init();

    while (1)
    {
        USART2_SendChar(tx_char);
        tx_char = (tx_char+1)%128;
        delay(300000);
    }
}
