#include "i2c.h"
#include "ds1307.h"

#define DS1307_ID 0xD0

void DS1307_SetTime(unsigned char h, unsigned char m, unsigned char s)
{
    I2C_Start();
    I2C_Write(DS1307_ID);
    I2C_Write(0x00);
    I2C_Write(s);
    I2C_Write(m);
    I2C_Write(h);
    I2C_Stop();
}

void DS1307_GetTime(unsigned char *h, unsigned char *m, unsigned char *s)
{
    I2C_Start();
    I2C_Write(DS1307_ID);
    I2C_Write(0x00);
    I2C_Start();
    I2C_Write(DS1307_ID | 1);
    *s = I2C_Read(1);
    *m = I2C_Read(1);
    *h = I2C_Read(0);
    I2C_Stop();
}
