void pinWrite(int pinNr , int pinValue);
void delay(void);
void portWrite(int portNr, int portValue);
int pinRead(int pinNr);
int portRead(int portNr);
void pinSelect(int pinNr,int spFunction);


void pinWrite(int pinNr,int pinValue){
	if(pinNr <100){
		IODIR0 |= (0x01<<pinNr);
		if(pinValue==0)
		IOCLR0 |= (0x01<<pinNr);
		else
		IOSET0 |= (0x01<<pinNr);
	}
	else{
		pinNr -=100;
		IODIR1 |= (0x01<<pinNr);
		if(pinValue==0)
		IOCLR1 |= (0x01<<pinNr);
		else
		IOSET1 |= (0x01<<pinNr);
		
	}
}
void portWrite(int portNr, int portValue){
	unsigned int i;
	if(portNr <10){
		if(portNr==0){
			for(i=0;i<8;i++){
				if(portValue & (0x01<<i)){
					pinWrite(i,0);
				}
				else{
					pinWrite(i,1);
				}
			}
		}
		else if(portNr==1){
			for(i=0;i<8;i++){
				if(portValue & (0x01<<i)){
					pinWrite(i+8,0);
				}
				else{
					pinWrite(i+8,1);
				}
			}
		}
		else if(portNr==2){
			for(i=0;i<8;i++){
				if(portValue & (0x01<<i)){
					pinWrite(i+16,0);
				}
				else{
					pinWrite(i+16,1);
				}
			}
		}
		else if(portNr==3){
			for(i=0;i<8;i++){
				if(portValue & (0x01<<i)){
					pinWrite(i+24,0);
				}
				else{
					pinWrite(i+24,1);
				}
			}
		}
		else{}
	}
	else{
		if(portNr == 12){
			for(i=0;i<8;i++){
				if(portValue & (0x01<<i)){
					pinWrite(i+116,0);
				}
				else{
					pinWrite(i+116,1);
				}
			}
		}
		else if(portValue == 13){
			for(i=0;i<8;i++){
				if(portValue & (0x01<<i)){
					pinWrite(i+124,0);
				}
				else{
					pinWrite(i+124,1);
				}
			}
		}
		else{}
	}
}

int pinRead(int pinNr){
	unsigned int mydata;
	if(pinNr<100){
		IODIR0 &= (~(0x01<<pinNr));
		mydata = IOPIN0;
		return mydata & (0x01<<pinNr);
	}
	else{
		pinNr -= 100;
		IODIR1 &= (~(0x01<<pinNr));
		mydata = IOPIN1;
		return mydata & (0x01<<pinNr);
	}
}

int portRead(int portNr){
	int mydata;
	if(portNr<10){
		if(portNr==0){
			IODIR0 &= (0xFFFFFF00);
			mydata = IOPIN0;
			return mydata & (0x000000FF);
		}
		else if(portNr==1){
			IODIR0 &= (0xFFFF00FF);
			mydata = IOPIN0;
			return (mydata & (0x0000FF00))>>8;
		}
		else if(portNr==2){
			IODIR0 &= (0xFF00FFFF);
			mydata = IOPIN0;
			return (mydata & (0x0000FF00))>>16;
		}
		else if(portNr==3){
			IODIR0 &= (0x00FFFFFF);
			mydata = IOPIN0;
			return (mydata & (0x0000FF00))>>24;
		}
		else if(portNr==9){
			IODIR0 &= (0x00000000);
			mydata = IOPIN0;
			return (mydata);
		}
		else{}
	}
	else{
		if(portNr==12){
			IODIR1 &= (0xFF00FFFF);
			mydata = IOPIN1;
			return (mydata & (0x0000FF00))>>16;
		}
		
		else if(portNr==13){
			IODIR1 &= (0x00FFFFFF);
			mydata = IOPIN1;
			return (mydata & (0x0000FF00))>>24;
		}
		else if(portNr==19){
			IODIR1 &= (0x00000000);
			mydata = IOPIN1;
			return mydata;
		}
		else{}
	}
}

void pinSelect(int pinNr, int spFunction) {
    int bit0, bit1;

    if (spFunction == 0)      { bit1 = 0; bit0 = 0; }
    else if (spFunction == 1) { bit1 = 0; bit0 = 1; }
    else if (spFunction == 2) { bit1 = 1; bit0 = 0; }
    else if (spFunction == 3) { bit1 = 1; bit0 = 1; }
    else return;

    if (pinNr >= 0 && pinNr <= 15) {
        if (bit0) PINSEL0 |=  (1 << (pinNr * 2));
        else      PINSEL0 &= ~(1 << (pinNr * 2));

        if (bit1) PINSEL0 |=  (1 << ((pinNr * 2) + 1));
        else      PINSEL0 &= ~(1 << ((pinNr * 2) + 1));
    }
    else if (pinNr >= 16 && pinNr <= 31) {
        pinNr -= 16;
        if (bit0) PINSEL1 |=  (1 << (pinNr * 2));
        else      PINSEL1 &= ~(1 << (pinNr * 2));

        if (bit1) PINSEL1 |=  (1 << ((pinNr * 2) + 1));
        else      PINSEL1 &= ~(1 << ((pinNr * 2) + 1));
    }
    else if (pinNr >= 116 && pinNr <= 131) {
        pinNr -= 116;
        if (bit0) PINSEL2 |=  (1 << (pinNr * 2));
        else      PINSEL2 &= ~(1 << (pinNr * 2));

        if (bit1) PINSEL2 |=  (1 << ((pinNr * 2) + 1));
        else      PINSEL2 &= ~(1 << ((pinNr * 2) + 1));
    }
}

	
void delay(){
	unsigned int i;
	for(i=0;i<20000;i++);
}


 