#include<LPC214x.h>
#include"GPIO.h"

int main(){
	while(1){
		pinWrite(11,1);
		pinWrite(116,0);
		delay();
		pinWrite(11,0);
		pinWrite(116,1);
		delay();
	}
}





