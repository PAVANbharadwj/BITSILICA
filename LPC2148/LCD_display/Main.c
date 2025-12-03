#include<LPC214x.h>
#include"GPIO.h"

int main(){
	pinSelect(0,1);
	pinSelect(1,1);
	pinSelect(8,3);
	pinSelect(118,1);
	while(1);
}
	