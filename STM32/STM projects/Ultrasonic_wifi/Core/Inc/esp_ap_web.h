#ifndef ESP_AP_WEB_H
#define ESP_AP_WEB_H

#include "stm32l4xx_hal.h"

void ESPAP_Init(UART_HandleTypeDef *huart);
void ESPAP_Reset(void);
void ESPAP_SendAT(void);
void ESPAP_SetAPMode(void);
void ESPAP_SetAP(const char* ssid, const char* pwd);
void ESPAP_EnableMUX(void);
void ESPAP_StartServer(uint16_t port);
void ESPAP_UpdateDistance(uint32_t d);
void ESPAP_HandleUARTByte(uint8_t b);

#endif // ESP_AP_WEB_H
