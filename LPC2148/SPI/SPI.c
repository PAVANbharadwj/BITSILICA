#include <LPC214x.h>
#include <stdio.h>

#define CS (1 << 7)  // P0.7 for EEPROM CS

// EEPROM Commands
#define WREN  0x06
#define WRDI  0x04
#define RDSR  0x05
#define WRSR  0x01
#define READ  0x03
#define WRITE 0x02

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 10000; j++);
}

// UART Functions
void UART0_Init(void) {
    PINSEL0 |= 0x00000005; // P0.0=TXD0, P0.1=RXD0
    U0LCR = 0x83;
    U0DLL = 97; // 9600 baud @15MHz PCLK
    U0DLM = 0;
    U0LCR = 0x03;
}

void UART0_TxChar(char ch) {
    while (!(U0LSR & 0x20));
    U0THR = ch;
}

void UART0_TxString(char *str) {
    while (*str) UART0_TxChar(*str++);
}

char UART0_RxChar(void) {
    while (!(U0LSR & 0x01));
    return U0RBR;
}

// SPI Functions
void SPI0_Init(void) {
    PINSEL0 |= 0x00001500; // P0.4=SCK0, P0.5=MISO0, P0.6=MOSI0, P0.7=SSEL0
    IO0DIR |= CS;
    IO0SET = CS;
    S0SPCCR = 8;  // SPI clock = PCLK/8
    S0SPCR = 0x20; // Master mode
}

unsigned char SPI0_Transfer(unsigned char data) {
    S0SPDR = data;
    while (!(S0SPSR & 0x80));
    return S0SPDR;
}

// EEPROM Functions
void EEPROM_WriteEnable(void) {
    IO0CLR = CS;
    SPI0_Transfer(WREN);
    IO0SET = CS;
}

void EEPROM_WriteByte(unsigned int addr, unsigned char data) {
    EEPROM_WriteEnable();
    IO0CLR = CS;
    SPI0_Transfer(WRITE);
    SPI0_Transfer((addr >> 8) & 0xFF);
    SPI0_Transfer(addr & 0xFF);
    SPI0_Transfer(data);
    IO0SET = CS;
    delay_ms(10);
}

unsigned char EEPROM_ReadByte(unsigned int addr) {
    unsigned char val;
    IO0CLR = CS;
    SPI0_Transfer(READ);
    SPI0_Transfer((addr >> 8) & 0xFF);
    SPI0_Transfer(addr & 0xFF);
    val = SPI0_Transfer(0x00);
    IO0SET = CS;
    return val;
}

// MAIN
int main(void) {
    unsigned char data_write, data_read;
    char buf[50];

    // PLL Setup (60 MHz)
    PLL0CON = 0x01;
    PLL0CFG = 0x24;
    PLL0FEED = 0xAA; PLL0FEED = 0x55;
    while (!(PLL0STAT & (1 << 10)));
    PLL0CON = 0x03; PLL0FEED = 0xAA; PLL0FEED = 0x55;
    VPBDIV = 0x04; // 15 MHz PCLK

    UART0_Init();
    SPI0_Init();

    UART0_TxString("LPC2148 + 25LC512 SPI EEPROM\r\n");
    UART0_TxString("Enter a character to store:\r\n");

    data_write = UART0_RxChar();
    UART0_TxChar(data_write);
    UART0_TxString("\r\n");

    EEPROM_WriteByte(0x0001, data_write);
    data_read = EEPROM_ReadByte(0x0001);

    sprintf(buf, "Wrote: %c  Read: %c\r\n", data_write, data_read);
    UART0_TxString(buf);

    while (1);
}
