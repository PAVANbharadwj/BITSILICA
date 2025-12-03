#ifndef __I2C_H__
#define __I2C_H__

void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write(unsigned char data);
unsigned char I2C_Read(unsigned int ack);

#endif
