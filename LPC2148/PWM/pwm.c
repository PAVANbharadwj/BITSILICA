#include <lpc214x.h>

void delay(void);

int main(void)
{
    int duty;

    PINSEL0 |= 0x00000002;        // Enable PWM1.1 function on P0.0
    PWMPR = 15000 - 1;            // Prescaler: 1ms tick (assuming 15MHz PCLK)
    PWMMR0 = 20;                  // Period = 20ms (typical for servo, can change)
    PWMMCR = (1 << 1);            // Reset on MR0
    PWMLER = (1 << 0);            // Latch enable for MR0
    PWMPCR = (1 << 9);            // Enable PWM1 output
    PWMTCR = (1 << 1);            // Reset counter and prescaler
    PWMTCR = (1 << 0) | (1 << 3); // Enable counter and PWM mode

    while (1)
    {
        for (duty = 2; duty < 18; duty++)  // Sweep duty 10% to 90%
        {
            PWMMR1 = duty;        // Duty cycle value
            PWMLER = (1 << 1);    // Update MR1
            delay();
        }
    }
}

void delay(void)
{
    unsigned long i;
    for (i = 0; i < 50000; i++);
}
