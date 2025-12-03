#include<LPC214x.h>
#include<stdint.h>

void delay_ms(uint16_t j){
	uint16_t x,i;
	for(i=0;i<j;j++){
		for(x=0;x<6000;x++);
	}
}

int main(void){
while(1){
	IO0DIR = (IO0DIR | 0x0000000F);
	IO0PIN = 1<<0;
	delay_ms(500);
	IO0PIN = 1<<1;
	delay_ms(500);
	IO0PIN = 1<<1;
	delay_ms(500);
}
}

	