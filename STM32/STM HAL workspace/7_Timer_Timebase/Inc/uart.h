#ifndef __UART_H
#define __UART_H

#include "stm32f4xx_hal.h"
#include <string.h>
#include <stdio.h>

extern UART_HandleTypeDef huart1;   // UART1 handle accessible in main

void uart_init(void);               // Initializes USART1

#endif
