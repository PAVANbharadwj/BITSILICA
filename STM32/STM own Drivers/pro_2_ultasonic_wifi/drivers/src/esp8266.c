/*
 * esp8266.c
 *
 *  Created on: Nov 20, 2025
 *      Author: pavan
 */


#include "esp8266.h"
#include "usart.h"
#include "systick.h"
#include <string.h>
#include <stdio.h>

static char resp_buf[256];

int read_response(const char *match, uint32_t timeout_ms)
{
    uint32_t start = millis();
    uint16_t idx = 0;
    while((millis()-start) < timeout_ms)
    {
        while(USART2_Available())
        {
            char c;
            USART2_ReadCharBlocking(&c, 1);
            if(idx < sizeof(resp_buf)-1) resp_buf[idx++] = c;
            resp_buf[idx] = 0;
            if(match && strstr(resp_buf, match)) return 1;
        }
    }
    return 0;
}

int ESP_SendSimple(const char* s)
{
    USART2_Send(s);
    USART2_Send("\r\n");
    if(read_response("OK", 3000)) return 1;
    return 0;
}

int ESP_Init(const char* ssid, const char* pass)
{
    USART2_FlushRX();
    /* Basic checks & reset */
    ESP_SendSimple("AT");
    ESP_SendSimple("ATE0"); /* disable echo */
    ESP_SendSimple("AT+GMR"); /* firmware info (ignore) */

    /* Set multi connection mode 1 (multiple) or 0 (single) - we'll use single to simplify (0) */
    ESP_SendSimple("AT+CWMODE=1"); /* station mode */

    /* Connect to AP */
    char cmd[160];
    snprintf(cmd, sizeof(cmd), "AT+CWJAP=\"%s\",\"%s\"", ssid, pass);
    USART2_Send(cmd);
    USART2_Send("\r\n");
    if(!read_response("WIFI CONNECTED", 15000)) return 0;
    /* Get IP */
    ESP_SendSimple("AT+CIFSR");
    /* Ready */
    return 1;
}

int ESP_SendHTTPPage(const char* page)
{
    char cmd[64];
    uint32_t len = strlen(page);

    snprintf(cmd, sizeof(cmd), "AT+CIPSEND=%u", (unsigned)len);
    USART2_Send(cmd);
    USART2_Send("\r\n");

    if(!read_response(">", 3000)) return 0;

    USART2_Send(page);

    if(!read_response("SEND OK", 3000)) return 0;

    return 1;
}

int ESP_StartTCPServer(uint16_t port)
{
    /* Enable multiple connections (needed by some firmwares) */
    ESP_SendSimple("AT+CIPMUX=0"); /* single connection */
    /* Start server not needed for single-connection, but start transparent server using AT+CIPSERVER=1,port */
    char cmd[64];
    snprintf(cmd, sizeof(cmd), "AT+CIPSERVER=1,%u", (unsigned)port);
    USART2_Send(cmd);
    USART2_Send("\r\n");
    if(!read_response("OK", 3000)) return 0;
    return 1;
}

/* For single-connection server, to send data use AT+CIPSEND=<len> then data */
int ESP_SendDataTCP(const char* data, uint32_t len)
{
    char cmd[32];
    snprintf(cmd, sizeof(cmd), "AT+CIPSEND=%u", (unsigned)len);
    USART2_Send(cmd);
    USART2_Send("\r\n");
    if(!read_response(">", 3000)) return 0;
    /* send payload */
    USART2_SendBuf((const uint8_t*)data, len);
    /* read send OK */
    if(!read_response("SEND OK", 3000)) return 0;
    return 1;
}
