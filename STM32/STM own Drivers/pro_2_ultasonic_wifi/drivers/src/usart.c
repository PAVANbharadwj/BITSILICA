/*
 * usart.c
 *
 *  Created on: Nov 20, 2025
 *      Author: pavan
 */


#include "usart.h"
#include "rcc.h"
#include "gpio.h"
#include "stm32l476xx.h"
#include "systick.h"

#define RX_BUF_SIZE 512
static volatile uint8_t rx_buf[RX_BUF_SIZE];
static volatile uint16_t rx_head = 0, rx_tail = 0;

void USART2_Init(uint32_t baud)
{
    RCC_EnableGPIOA();
    RCC_EnableUSART2();

    /* PA2 -> USART2_TX (AF7), PA3 -> USART2_RX (AF7) */
    /* Set AF mode */
    /* MODER */
    GPIOA->MODER &= ~( (0x3<<(2*2)) | (0x3<<(3*2)) );
    GPIOA->MODER |=  ( (0x2<<(2*2)) | (0x2<<(3*2)) ); /* AF mode */
    /* AFR */
    GPIOA->AFR[0] &= ~((0xF<< (2*4)) | (0xF<< (3*4)));
    GPIOA->AFR[0] |=  (7 << (2*4)) | (7 << (3*4)); /* AF7 */

    /* Configure USART2 */
    USART2->CR1 &= ~USART_CR1_UE;
    /* Set baud: PCLK1 / (8*(2-OVER8)) etc. For simplicity use oversampling by 16 */
    uint32_t pclk = 4000000U; /* default APB1 for L476 approx 4MHz MSI — this is approximate; if you changed clocks adjust. */
#ifdef SystemCoreClock
    (void)SystemCoreClock;
#endif
    /* compute USARTDIV = pclk / baud */
    uint32_t usartdiv = (pclk + (baud/2U)) / baud;
    USART2->BRR = usartdiv;
    /* 8N1 */
    USART2->CR1 = USART_CR1_TE | USART_CR1_RE | USART_CR1_RXNEIE;
    USART2->CR2 = 0;
    USART2->CR3 = 0;
    USART2->CR1 |= USART_CR1_UE;

    /* NVIC for USART2 */
    NVIC_SetPriority(USART2_IRQn, 2);
    NVIC_EnableIRQ(USART2_IRQn);
}

void USART2_SendChar(char c)
{
    while(!(USART2->ISR & USART_ISR_TXE));
    USART2->TDR = (uint8_t)c;
}

void USART2_Send(const char *s)
{
    while(*s) USART2_SendChar(*s++);
}

int USART2_SendBuf(const uint8_t *buf, uint16_t len)
{
    for(uint16_t i=0;i<len;i++) USART2_SendChar((char)buf[i]);
    return len;
}

uint16_t USART2_Available(void)
{
    return (RX_BUF_SIZE + rx_head - rx_tail) % RX_BUF_SIZE;
}

int USART2_ReadCharBlocking(char *c, uint32_t timeout_ms)
{
    uint32_t start = millis();
    while(USART2_Available() == 0)
    {
        if((millis() - start) > timeout_ms) return 0;
    }
    *c = (char)rx_buf[rx_tail];
    rx_tail = (rx_tail + 1) % RX_BUF_SIZE;
    return 1;
}

void USART2_FlushRX(void) { rx_head = rx_tail = 0; }

/* IRQ handler */
void USART2_IRQHandler(void)
{
    uint32_t sr = USART2->ISR;
    if(sr & USART_ISR_RXNE)
    {
        uint8_t d = (uint8_t)(USART2->RDR & 0xFF);
        uint16_t next = (rx_head + 1) % RX_BUF_SIZE;
        if(next != rx_tail) { rx_buf[rx_head] = d; rx_head = next; } /* drop on overflow */
    }
}
