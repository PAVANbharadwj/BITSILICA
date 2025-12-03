#ifndef __EEPROM_H__
#define __EEPROM_H__

void EEPROM_Write(unsigned char addr, unsigned char *data, unsigned int len);
void EEPROM_Read(unsigned char addr, unsigned char *data, unsigned int len);

#endif
