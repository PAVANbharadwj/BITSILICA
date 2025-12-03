#include "esp_ap_web.h"
#include <string.h>
#include <stdio.h>

#define RXBUF_SIZE 1024

static UART_HandleTypeDef *esp_huart;
static volatile uint32_t latest_distance_cm = 0;

/* ring buffer */
static uint8_t rxbuf[RXBUF_SIZE];
static volatile uint16_t rx_head = 0;
static volatile uint16_t rx_tail = 0;

/* -------- Ring Buffer Helpers ---------- */
static void rx_push(uint8_t b) {
    rxbuf[rx_head++] = b;
    if (rx_head >= RXBUF_SIZE) rx_head = 0;
}

static uint16_t rx_count(void) {
    if (rx_head >= rx_tail) return (rx_head - rx_tail);
    return (RXBUF_SIZE - rx_tail) + rx_head;
}

static uint8_t rx_peek_char(uint16_t idx) {
    uint16_t pos = rx_tail + idx;
    if (pos >= RXBUF_SIZE) pos -= RXBUF_SIZE;
    return rxbuf[pos];
}

static uint8_t rx_pop(void) {
    uint8_t b = rxbuf[rx_tail++];
    if (rx_tail >= RXBUF_SIZE) rx_tail = 0;
    return b;
}

/* -------- UART Send -------- */
static void esp_send_raw(const char *s) {
    HAL_UART_Transmit(esp_huart, (uint8_t *)s, strlen(s), 2000);
}

/* -------- Init -------- */
void ESPAP_Init(UART_HandleTypeDef *huart) {
    esp_huart = huart;
    /* DO NOT start UART receive here.
       main.c starts:
       HAL_UART_Receive_IT(&huart2, &esp_rx_tmp, 1);
    */
}

/* -------- Basic Commands -------- */
void ESPAP_Reset(void) {
    esp_send_raw("AT+RST\r\n");
}

void ESPAP_SendAT(void) {
    esp_send_raw("AT\r\n");
}

void ESPAP_SetAPMode(void) {
    esp_send_raw("AT+CWMODE=2\r\n");
}

void ESPAP_SetAP(const char* ssid, const char* pwd) {
    char cmd[128];

    if (!pwd || pwd[0]=='\0')
        snprintf(cmd, sizeof(cmd), "AT+CWSAP=\"%s\",\"\",5,3\r\n", ssid);
    else
        snprintf(cmd, sizeof(cmd), "AT+CWSAP=\"%s\",\"%s\",5,3\r\n", ssid, pwd);

    esp_send_raw(cmd);
    HAL_Delay(3000); // important
}

void ESPAP_EnableMUX(void) {
    esp_send_raw("AT+CIPMUX=1\r\n");
}

void ESPAP_StartServer(uint16_t port) {
    char cmd[64];
    snprintf(cmd, sizeof(cmd), "AT+CIPSERVER=1,%u\r\n", port);
    esp_send_raw(cmd);
    HAL_Delay(500);
}

void ESPAP_UpdateDistance(uint32_t d) {
    latest_distance_cm = d;
}

/* -------- Send Webpage -------- */
static void reply_with_distance(int linkid) {
    char body[256];

    int len = snprintf(
        body, sizeof(body),
        "<html>"
        "<head><meta http-equiv=\"refresh\" content=\"1\"></head>"
        "<body><h2>Object at: %lu cm</h2></body>"
        "</html>",
        (unsigned long)latest_distance_cm
    );

    char cmd[64];
    snprintf(cmd, sizeof(cmd), "AT+CIPSEND=%d,%d\r\n", linkid, len);

    esp_send_raw(cmd);
    HAL_Delay(60);

    HAL_UART_Transmit(esp_huart, (uint8_t *)body, len, 1000);

    HAL_Delay(20);

    snprintf(cmd, sizeof(cmd), "AT+CIPCLOSE=%d\r\n", linkid);
    esp_send_raw(cmd);
}

/* -------- Process +IPD -------- */
static void process_rx_stream(void) {
    while (rx_count() > 5) {
        uint16_t cnt = rx_count();
        uint16_t i;
        uint8_t found = 0;

        for (i = 0; i + 4 < cnt; i++) {
            if (rx_peek_char(i)=='+' &&
                rx_peek_char(i+1)=='I' &&
                rx_peek_char(i+2)=='P' &&
                rx_peek_char(i+3)=='D' &&
                rx_peek_char(i+4)==',') {
                found = 1;
                break;
            }
        }

        if (!found) {
            if (cnt > 5)
                for (uint16_t k = 0; k < cnt - 5; k++) rx_pop();
            break;
        }

        for (uint16_t k = 0; k < i; k++) rx_pop();
        for (int k = 0; k < 5; k++) rx_pop();

        int linkid = 0;
        while (rx_count() && rx_peek_char(0)>='0' && rx_peek_char(0)<='9')
            linkid = linkid * 10 + (rx_pop() - '0');

        if (rx_count() && rx_peek_char(0)==',') rx_pop();

        while (rx_count()) {
            if (rx_pop()==':') break;
        }

        reply_with_distance(linkid);
    }
}

/* -------- Byte Callback -------- */
void ESPAP_HandleUARTByte(uint8_t b) {
    rx_push(b);
    process_rx_stream();
}
