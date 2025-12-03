#include <lpc214x.h>
#include "i2c.h"

void I2C_Init(void)
{
    PINSEL0 |= 0x00000050;   // P0.2=SCL0, P0.3=SDA0
    I2C0SCLH = 75;           // For 100kHz @ 15MHz PCLK
    I2C0SCLL = 75;
    I2C0CONSET = 0x40;       // Enable I2C
}

void I2C_Start(void)
{
    I2C0CONSET = 0x20;       // START
    I2C0CONCLR = 0x08;
    while (!(I2C0CONSET & 0x08));
}

void I2C_Stop(void)
{
    I2C0CONSET = 0x10;       // STOP
    I2C0CONCLR = 0x08;
}

void I2C_Write(unsigned char data)
{
    I2C0DAT = data;
    I2C0CONCLR = 0x28;
    while (!(I2C0CONSET & 0x08));
}

unsigned char I2C_Read(unsigned int ack)
{
    if (ack)
        I2C0CONSET = 0x04;
    else
        I2C0CONCLR = 0x04;
    I2C0CONCLR = 0x08;
    while (!(I2C0CONSET & 0x08));
    return I2C0DAT;
}
