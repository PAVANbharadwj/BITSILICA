#ifndef INC_STM32L476XX_USART_DRIVER_H_
#define INC_STM32L476XX_USART_DRIVER_H_

#include <stdint.h>
#include "stm32l476xx.h"

/* ====== ADD THESE DEFINITIONS ====== */

/* USART missing bits */
#define USART_CR1_M0      (1U << 12)
#define USART_CR1_PCE     (1U << 10)
#define USART_CR1_PS      (1U << 9)
#define USART_CR1_TCIE    (1U << 6)

/* Flow control options */
#define USART_HW_FLOW_CTRL_NONE   0
#define USART_HW_FLOW_CTRL_CTS    1
#define USART_HW_FLOW_CTRL_RTS    2

/* RCC missing bits */



typedef struct {
    uint8_t  USART_Mode;
    uint32_t USART_Baud;
    uint8_t  USART_NoOfStopBits;
    uint8_t  USART_WordLength;
    uint8_t  USART_ParityControl;
    uint8_t  USART_HWFlowControl;
} USART_Config_t;

typedef struct {
    USART_TypeDef   *pUSARTx;
    USART_Config_t   USART_Config;
    uint8_t         *pTxBuffer;
    uint8_t         *pRxBuffer;
    uint32_t         TxLen;
    uint32_t         RxLen;
    uint8_t          TxBusyState;
    uint8_t          RxBusyState;
} USART_Handle_t;

/* Modes, Baud, etc. (same as earlier) */
#define USART_MODE_ONLY_TX      0
#define USART_MODE_ONLY_RX      1
#define USART_MODE_TXRX         2

#define USART_STD_BAUD_9600     9600

#define USART_PARITY_DISABLE    0
#define USART_PARITY_EN_EVEN    1
#define USART_PARITY_EN_ODD     2

#define USART_WORDLEN_8BITS     0
#define USART_WORDLEN_9BITS     1

#define USART_STOPBITS_1        0

#define USART_HW_FLOW_CTRL_NONE     0

#define USART_FLAG_TXE         USART_ISR_TXE
#define USART_FLAG_RXNE        USART_ISR_RXNE
#define USART_FLAG_TC          USART_ISR_TC

#define USART_BUSY_IN_RX       1
#define USART_BUSY_IN_TX       2
#define USART_READY            0

#define USART_EVENT_TX_CMPLT    0
#define USART_EVENT_RX_CMPLT    1

/* API prototypes */
void USART_PeriClockControl(USART_TypeDef *pUSARTx, uint8_t EnOrDi);
void USART_Init(USART_Handle_t *pUSARTHandle);
void USART_DeInit(USART_TypeDef *pUSARTx);
void USART_SendData(USART_Handle_t *pUSARTHandle, uint8_t *pTxBuffer, uint32_t len);
void USART_ReceiveData(USART_Handle_t *pUSARTHandle, uint8_t *pRxBuffer, uint32_t len);
uint8_t USART_SendDataIT(USART_Handle_t *pUSARTHandle, uint8_t *pTxBuffer, uint32_t len);
uint8_t USART_ReceiveDataIT(USART_Handle_t *pUSARTHandle, uint8_t *pRxBuffer, uint32_t len);
void USART_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void USART_IRQHandling(USART_Handle_t *pUSARTHandle);

uint8_t USART_GetFlagStatus(USART_TypeDef *pUSARTx, uint32_t FlagName);
void USART_ClearFlag(USART_TypeDef *pUSARTx, uint32_t FlagName);
void USART_PeripheralControl(USART_TypeDef *pUSARTx, uint8_t EnOrDi);
void USART_SetBaudRate(USART_TypeDef *pUSARTx, uint32_t BaudRate);

void USART_ApplicationEventCallback(USART_Handle_t *pUSARTHandle, uint8_t ApEv);

#endif
