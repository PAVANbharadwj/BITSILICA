/*
 * esp8266.h
 *
 *  Created on: Nov 20, 2025
 *      Author: pavan
 */

#ifndef ESP8266_H
#define ESP8266_H
#include <stdint.h>

int ESP_Init(const char* ssid, const char* pass);
int ESP_StartTCPServer(uint16_t port);
int ESP_SendDataTCP(const char* data, uint32_t len);
int ESP_SendSimple(const char* s); /* send raw AT command with CRLF and wait OK */
int ESP_SendHTTPPage(const char* page);
int read_response(const char *match, uint32_t timeout_ms);
#endif

