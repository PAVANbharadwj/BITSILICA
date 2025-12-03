#include <lpc214x.h>
#include "lcd.h"
#include "i2c.h"
#include "ds1307.h"
#include "eeprom.h"

void delay_ms(unsigned int ms);

int main(void)
{
    unsigned char h, m, s;
    unsigned char data[3];

    lcd_init();
    lcd_cmd(0x80);
    lcd_str("I2C Devices Demo");
    delay_ms(1000);
    lcd_cmd(0x01);

    I2C_Init();   // Initialize I2C before use

    while(1)
    {
        DS1307_GetTime(&h, &m, &s);

        data[0] = h;
        data[1] = m;
        data[2] = s;

        EEPROM_Write(0x00, data, 3);

        lcd_cmd(0x80);
        lcd_str("Time:");
        lcd_data((h/10)+'0');
        lcd_data((h%10)+'0');
        lcd_data(':');
        lcd_data((m/10)+'0');
        lcd_data((m%10)+'0');
        lcd_data(':');
        lcd_data((s/10)+'0');
        lcd_data((s%10)+'0');

        delay_ms(1000);
    }
}
