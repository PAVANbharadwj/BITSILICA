#include <LPC21xx.h>

void delay(unsigned int count) {
    unsigned int i, j;
    for (i = 0; i < count; i++) {
        for (j = 0; j < 200; j++);
    }
}

int main(void) {
    IODIR1 = (1 << 16);

    IODIR0 &= ~(1 << 14);

    while (1) {
        if ((IOPIN0 & (1 << 14)) == 0) {  
            IOSET1 = (1 << 16); 
        } else {
            IOCLR1 = (1 << 16);
        }
    }
}
