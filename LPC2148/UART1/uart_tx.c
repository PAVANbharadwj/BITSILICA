#include<LPC214x.h>

int main(){
	PINSEL0 |= 0x00000005;
	U0LCR = 0x83;
	U0DLL = 97;
	U0LCR = 0x03;
	
	while(1){
		while(!(U0LSR & 0x20));
		U0THR = 'a';
	}
}