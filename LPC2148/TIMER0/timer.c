#include <lpc214x.h>

void delay(void);

void TIMER0_IRQHandler(void) __irq {
    IO0PIN ^= (1 << 10);           // Toggle LED on P0.10
    T0IR = 1;                      // Clear interrupt flag
    VICVectAddr = 0;               // Acknowledge interrupt
}

int main(void) {
    IO0DIR |= (1 << 10);           // Set P0.10 as output

    T0PR = 15000 - 1;              // Prescale for 1 ms (PCLK=15MHz)
    T0MR0 = 1000;                  // 1000 ms = 1 second
    T0MCR = 3;                     // Interrupt and reset on MR0

    VICVectAddr0 = (unsigned long)TIMER0_IRQHandler;  // ISR address
    VICVectCntl0 = 0x20 | 4;       // Enable slot0 for Timer0
    VICIntEnable = (1 << 4);       // Enable Timer0 interrupt

    T0TCR = 1;                     // Start Timer0

    while (1);
}
