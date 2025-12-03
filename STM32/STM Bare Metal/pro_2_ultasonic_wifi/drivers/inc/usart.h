/*
 * usart.h
 *
 *  Created on: Nov 20, 2025
 *      Author: pavan
 */

#ifndef USART_H
#define USART_H
#include <stdint.h>

void USART2_Init(uint32_t baud);
void USART2_SendChar(char c);
void USART2_Send(const char *s);
int  USART2_SendBuf(const uint8_t *buf, uint16_t len);
uint16_t USART2_Available(void);
int USART2_ReadCharBlocking(char *c, uint32_t timeout_ms);
void USART2_FlushRX(void);
#endif

