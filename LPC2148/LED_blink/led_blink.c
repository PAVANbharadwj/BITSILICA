#include<LPC21xx.h>
 
void delay(unsigned int w) {
    unsigned int a, b;
    for (a = 0; a < w; a++) {
        for (b = 0; b < 200; b++);
    }
}



int main(){
PINSEL2 = 0x00000000;
IODIR1 = 0xFFFFFFFF;
while(1){
	IOSET1 = 0xFFFFFFFF;
	delay(25000);
	IOCLR1 = 0xFFFFFFFF;
	delay(25000);
	}
}