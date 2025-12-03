#include "i2c.h"
#include "eeprom.h"

#define EEPROM_ID 0xA0

void EEPROM_Write(unsigned char addr, unsigned char *data, unsigned int len)
{
		int i;
    I2C_Start();
    I2C_Write(EEPROM_ID);
    I2C_Write(addr);
    for(i=0; i<len; i++)
        I2C_Write(data[i]);
    I2C_Stop();
}

void EEPROM_Read(unsigned char addr, unsigned char *data, unsigned int len)
{
		int i;
    I2C_Start();
    I2C_Write(EEPROM_ID);
    I2C_Write(addr);
    I2C_Start();
    I2C_Write(EEPROM_ID | 1);
    for(i=0; i<len; i++)
        data[i] = I2C_Read(i < len-1);
    I2C_Stop();
}
