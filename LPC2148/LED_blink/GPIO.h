#include <LPC214x.h>

void delay(void);
void pinWrite(int pinNr, int pinValue);
int pinRead(int pinNr);
void portWrite(int portNr, int portValue);
int portRead(int portNr);

void pinWrite(int pinNr, int pinValue) {
    if (pinNr < 100) {
        IODIR0 |= (1 << pinNr);  // make P0.x output
        if (pinValue)
            IOSET0 = (1 << pinNr);  
        else
            IOCLR0 = (1 << pinNr);
    } 
    else {
        pinNr -= 100;
        IODIR1 |= (1 << pinNr);  // make P1.x output
        if (pinValue)
            IOSET1 = (1 << pinNr);  
        else
            IOCLR1 = (1 << pinNr);
    }
}

int pinRead(int pinNr) {
    if (pinNr < 100) {
        IODIR0 &= ~(1 << pinNr);  // make P0.x input
        return (IOPIN0 & (1 << pinNr)) ? 1 : 0;
    } 
    else {
        pinNr -= 100;
        IODIR1 &= ~(1 << pinNr);  // make P1.x input
        return (IOPIN1 & (1 << pinNr)) ? 1 : 0;
    }
}

void portWrite(int portNr, int portValue) {
    unsigned int basePin = 0;
    switch (portNr) {
        case 0: basePin = 0; break;
        case 1: basePin = 8; break;
        case 2: basePin = 16; break;
        case 3: basePin = 24; break;
        case 12: basePin = 100 + 16; break;
        case 13: basePin = 100 + 24; break;
        default: return;
    }

    for (int i = 0; i < 8; i++) {
        int value = (portValue >> i) & 1;
        pinWrite(basePin + i, value);
    }
}

int portRead(int portNr) {
    unsigned int basePin = 0;
    switch (portNr) {
        case 0: basePin = 0; break;
        case 1: basePin = 8; break;
        case 2: basePin = 16; break;
        case 3: basePin = 24; break;
        case 12: basePin = 100 + 16; break;
        case 13: basePin = 100 + 24; break;
        default: return 0;
    }

    int result = 0;
    for (int i = 0; i < 8; i++) {
        result |= pinRead(basePin + i) << i;
    }
    return result;
}

void delay(void) {
    for (volatile unsigned int i = 0; i < 200000; i++);
}
