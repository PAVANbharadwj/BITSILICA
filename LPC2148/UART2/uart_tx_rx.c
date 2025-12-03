#include<LPC21xx.h>


unsigned char data;

int main(void){
	PINSEL0 |= 0x00000005;
	U0LCR = 0x83;
	U0DLL = 97;
	U0LCR = 0x03;
	
	while(1){
		while(!(U0LSR & 0x01));
		data = U0RBR;
		while(!(U0LSR & 0x20));
		U0THR= data;
	}
}