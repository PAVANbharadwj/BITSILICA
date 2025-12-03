#include <lpc214x.h>

void UART0_Init(void);
void UART0_TxChar(char c);
void UART0_TxString(char *str);
char UART0_RxChar(void);
void delay_ms(unsigned int ms);

int main(void)
{
    char ch;
    UART0_Init();
    UART0_TxString("Bluetooth UART Communication Started\r\n");

    while(1)
    {
        UART0_TxString("Sensor Data: 25.5C\r\n"); // Simulated sensor data
        delay_ms(1000);

        if((U0LSR & 0x01)) // Check if data received
        {
            ch = UART0_RxChar();
            UART0_TxString("Received: ");
            UART0_TxChar(ch);
            UART0_TxString("\r\n");
        }
    }
}

void UART0_Init(void)
{
    PINSEL0 |= 0x00000005;   // P0.0 = TXD0, P0.1 = RXD0
    U0LCR = 0x83;            // 8-bit data, 1 stop bit, no parity, enable DLAB
    U0DLL = 97;              // Baud rate 9600 for 15MHz PCLK
    U0DLM = 0;
    U0LCR = 0x03;            // Disable DLAB
}

void UART0_TxChar(char c)
{
    while(!(U0LSR & 0x20));  // Wait until THR empty
    U0THR = c;
}

void UART0_TxString(char *str)
{
    while(*str)
        UART0_TxChar(*str++);
}

char UART0_RxChar(void)
{
    while(!(U0LSR & 0x01));  // Wait for data ready
    return U0RBR;
}

void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for(i=0; i<ms; i++)
        for(j=0; j<6000; j++);
}
