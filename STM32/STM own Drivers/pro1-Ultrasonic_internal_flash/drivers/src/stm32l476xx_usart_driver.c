#include "stm32l476xx_usart_driver.h"

/* Peripheral Clock Control */
void USART_PeriClockControl(USART_TypeDef *pUSARTx, uint8_t EnOrDi)
{
    if(EnOrDi == ENABLE)
    {
        if(pUSARTx == USART1) RCC->APB2ENR |= (1U<<14); /* USART1_PCLK_EN */
        else if(pUSARTx == USART2) RCC->APB1ENR1 |= (1U<<17);
        else if(pUSARTx == USART3) RCC->APB1ENR1 |= (1U<<18);
        else if(pUSARTx == UART4)  RCC->APB1ENR1 |= (1U<<19);
        else if(pUSARTx == UART5)  RCC->APB1ENR1 |= (1U<<20);
    }
    else
    {
        if(pUSARTx == USART1) RCC->APB2ENR &= ~(1U<<14);
        else if(pUSARTx == USART2) RCC->APB1ENR1 &= ~(1U<<17);
        else if(pUSARTx == USART3) RCC->APB1ENR1 &= ~(1U<<18);
        else if(pUSARTx == UART4)  RCC->APB1ENR1 &= ~(1U<<19);
        else if(pUSARTx == UART5)  RCC->APB1ENR1 &= ~(1U<<20);
    }
}

/* Basic RCC PCLK helper — assume SYSCLK 80MHz if PLL configured */
static uint32_t RCC_GetPCLKFreq(USART_TypeDef *pUSARTx)
{
    /* crude but practical: detect APB prescalers (from CFGR) */
    uint32_t sysclk = 80000000U;
    uint32_t hclk = sysclk;
    uint32_t ppre1 = (RCC->CFGR >> 8) & 0x7;
    uint32_t ppre2 = (RCC->CFGR >> 11) & 0x7;
    uint32_t apb1_div = (ppre1 < 4) ? 1U : (1U << (ppre1 - 3));
    uint32_t apb2_div = (ppre2 < 4) ? 1U : (1U << (ppre2 - 3));
    if(pUSARTx == USART1) return hclk / apb2_div;
    return hclk / apb1_div;
}

/* Init */
void USART_Init(USART_Handle_t *pUSARTHandle)
{
    uint32_t tempCR1 = 0, tempCR2 = 0, tempCR3 = 0;

    USART_PeriClockControl(pUSARTHandle->pUSARTx, ENABLE);
    USART_PeripheralControl(pUSARTHandle->pUSARTx, DISABLE);

    /* Mode */
    if(pUSARTHandle->USART_Config.USART_Mode == USART_MODE_ONLY_RX) tempCR1 |= USART_CR1_RE;
    else if(pUSARTHandle->USART_Config.USART_Mode == USART_MODE_ONLY_TX) tempCR1 |= USART_CR1_TE;
    else tempCR1 |= (USART_CR1_TE | USART_CR1_RE);

    /* Word length */
    if(pUSARTHandle->USART_Config.USART_WordLength == USART_WORDLEN_8BITS) tempCR1 &= ~(USART_CR1_M0);
    else tempCR1 |= USART_CR1_M0;

    /* Parity */
    if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_DISABLE) tempCR1 &= ~USART_CR1_PCE;
    else if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_EN_EVEN) tempCR1 |= USART_CR1_PCE;
    else tempCR1 |= (USART_CR1_PCE | USART_CR1_PS);

    pUSARTHandle->pUSARTx->CR1 = tempCR1;

    /* Stop bits */
    tempCR2 &= ~USART_CR2_STOP;
    tempCR2 |= (pUSARTHandle->USART_Config.USART_NoOfStopBits << USART_CR2_STOP_Pos);
    pUSARTHandle->pUSARTx->CR2 = tempCR2;

    /* CR3 */
    if(pUSARTHandle->USART_Config.USART_HWFlowControl == USART_HW_FLOW_CTRL_NONE) tempCR3 &= ~(USART_CR3_CTSE | USART_CR3_RTSE);
    else if(pUSARTHandle->USART_Config.USART_HWFlowControl == USART_HW_FLOW_CTRL_CTS) tempCR3 |= USART_CR3_CTSE;
    else if(pUSARTHandle->USART_Config.USART_HWFlowControl == USART_HW_FLOW_CTRL_RTS) tempCR3 |= USART_CR3_RTSE;
    else tempCR3 |= (USART_CR3_CTSE | USART_CR3_RTSE);
    pUSARTHandle->pUSARTx->CR3 = tempCR3;

    /* Baud */
    USART_SetBaudRate(pUSARTHandle->pUSARTx, pUSARTHandle->USART_Config.USART_Baud);

    USART_PeripheralControl(pUSARTHandle->pUSARTx, ENABLE);
}

/* DeInit */
void USART_DeInit(USART_TypeDef *pUSARTx)
{
    if(pUSARTx == USART1) { RCC->APB2ENR |= (1U<<14); RCC->APB2RSTR |= (1U<<14); RCC->APB2RSTR &= ~(1U<<14); }
    else if(pUSARTx == USART2) { RCC->APB1ENR1 |= (1U<<17); RCC->APB1RSTR1 |= (1U<<17); RCC->APB1RSTR1 &= ~(1U<<17); }
    else if(pUSARTx == USART3) { RCC->APB1ENR1 |= (1U<<18); RCC->APB1RSTR1 |= (1U<<18); RCC->APB1RSTR1 &= ~(1U<<18); }
}

/* Blocking send */
void USART_SendData(USART_Handle_t *pUSARTHandle, uint8_t *pTxBuffer, uint32_t len)
{
    while(len > 0)
    {
        while(!(USART_GetFlagStatus(pUSARTHandle->pUSARTx, USART_FLAG_TXE)));
        pUSARTHandle->pUSARTx->TDR = *pTxBuffer;
        pTxBuffer++;
        len--;
    }
    while(!(USART_GetFlagStatus(pUSARTHandle->pUSARTx, USART_FLAG_TC)));
}

/* Blocking receive */
void USART_ReceiveData(USART_Handle_t *pUSARTHandle, uint8_t *pRxBuffer, uint32_t len)
{
    while(len > 0)
    {
        while(!(USART_GetFlagStatus(pUSARTHandle->pUSARTx, USART_FLAG_RXNE)));
        *pRxBuffer = (uint8_t)pUSARTHandle->pUSARTx->RDR;
        pRxBuffer++;
        len--;
    }
}

/* Flag helpers */
uint8_t USART_GetFlagStatus(USART_TypeDef *pUSARTx, uint32_t FlagName)
{
    return ( (pUSARTx->ISR & FlagName) ? SET : RESET );
}

void USART_ClearFlag(USART_TypeDef *pUSARTx, uint32_t FlagName)
{
    /* writing 1 to ICR clears flags */
    pUSARTx->ICR = FlagName;
}

/* Peripheral control */
void USART_PeripheralControl(USART_TypeDef *pUSARTx, uint8_t EnOrDi)
{
    if(EnOrDi == ENABLE) pUSARTx->CR1 |= USART_CR1_UE;
    else pUSARTx->CR1 &= ~USART_CR1_UE;
}

/* Baud */
void USART_SetBaudRate(USART_TypeDef *pUSARTx, uint32_t BaudRate)
{
    uint32_t pclk = RCC_GetPCLKFreq(pUSARTx);
    pUSARTx->BRR = (pclk + BaudRate/2U) / BaudRate;
}

/* IRQ config */
void USART_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
    {
        if(IRQNumber < 32) *NVIC_ISER0 |= (1U << IRQNumber);
        else if(IRQNumber < 64) *NVIC_ISER1 |= (1U << (IRQNumber - 32));
        else *NVIC_ISER2 |= (1U << (IRQNumber - 64));
    }
    else
    {
        if(IRQNumber < 32) *NVIC_ICER0 |= (1U << IRQNumber);
        else if(IRQNumber < 64) *NVIC_ICER1 |= (1U << (IRQNumber - 32));
        else *NVIC_ICER2 |= (1U << (IRQNumber - 64));
    }

    uint8_t iprx = IRQNumber / 4;
    uint8_t section = IRQNumber % 4;
    uint8_t shift = (8*section) + (8 - NO_PR_BITS_IMPLEMENTED);
    *(NVIC_PR_BASE_ADDR + iprx) |= (IRQPriority << shift);
}

/* IRQ handler simplified (keeps parity with your earlier implementation) */
void USART_IRQHandling(USART_Handle_t *pUSARTHandle)
{
    uint32_t isr = pUSARTHandle->pUSARTx->ISR;
    uint32_t cr1 = pUSARTHandle->pUSARTx->CR1;

    /* TXE */
    if ((isr & USART_ISR_TXE) && (cr1 & USART_CR1_TXEIE))
    {
        if (pUSARTHandle->TxLen > 0)
        {
            pUSARTHandle->pUSARTx->TDR = *(pUSARTHandle->pTxBuffer);
            pUSARTHandle->pTxBuffer++;
            pUSARTHandle->TxLen--;
        }
        if (pUSARTHandle->TxLen == 0)
        {
            pUSARTHandle->pUSARTx->CR1 &= ~USART_CR1_TXEIE;
            pUSARTHandle->pUSARTx->CR1 |= USART_CR1_TCIE;
        }
    }

    /* TC */
    if ((isr & USART_ISR_TC) && (cr1 & USART_CR1_TCIE))
    {
        pUSARTHandle->pUSARTx->ICR = USART_ISR_TC; /* clear */
        pUSARTHandle->TxBusyState = USART_READY;
        pUSARTHandle->pUSARTx->CR1 &= ~USART_CR1_TCIE;
        USART_ApplicationEventCallback(pUSARTHandle, USART_EVENT_TX_CMPLT);
    }

    /* RXNE */
    if ((isr & USART_ISR_RXNE) && (cr1 & USART_CR1_RXNEIE))
    {
        pUSARTHandle->pRxBuffer[0] = (uint8_t)(pUSARTHandle->pUSARTx->RDR & 0xFF);
        pUSARTHandle->pRxBuffer++;
        pUSARTHandle->RxLen--;

        if (pUSARTHandle->RxLen == 0)
        {
            pUSARTHandle->RxBusyState = USART_READY;
            pUSARTHandle->pUSARTx->CR1 &= ~USART_CR1_RXNEIE;
            USART_ApplicationEventCallback(pUSARTHandle, USART_EVENT_RX_CMPLT);
        }
    }
}
