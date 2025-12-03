#include <LPC214x.h>

void delay(unsigned int count) {
    unsigned int i, j;
    for (i = 0; i < count; i++)
        for (j = 0; j < 500; j++);
}

unsigned int adc_read(void) {
    unsigned int value;

    AD0CR = (1 << 1)      
          | (4 << 8)        
          | (1 << 21);     

    AD0CR |= (1 << 24);     

    while ((AD0GDR & (1U << 31)) == 0);  

    value = (AD0GDR >> 6) & 0x3FF;      
    return value;
}

int main(void) {
    unsigned int adc_value, led_value;
    
    PINSEL1 |= (1 << 24);

    while (1) {
        adc_value = adc_read();

        led_value = (adc_value * 10) / 1024;

        IOCLR1 = 0x03FF << 16;

        IOSET1 = ((1 << led_value) - 1) << 16;

        delay(100);
    }
}
