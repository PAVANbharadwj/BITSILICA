#include "stm32l476xx.h"
#include "systick.h"

volatile uint32_t echo_state = 0;   // <-- WATCH THIS VARIABLE
volatile uint32_t trig_pulse = 0;   // OPTIONAL for debugging

int main(void)
{
    Systick_Init();

    // Enable GPIOA clock
    RCC->AHB2ENR |= (1 << 0);

    // PA5 = TRIG (output)
    GPIOA->MODER &= ~(3 << (5*2));
    GPIOA->MODER |=  (1 << (5*2));

    // PA6 = ECHO (input)
    GPIOA->MODER &= ~(3 << (6*2));  // input mode

    while(1)
    {
        // 1) Send TRIG pulse
        GPIOA->ODR &= ~(1 << 5);
        delay_us(2);
        GPIOA->ODR |=  (1 << 5);
        delay_us(10);
        GPIOA->ODR &= ~(1 << 5);

        trig_pulse++;  // just to see activity

        // 2) Read ECHO pin into variable
        echo_state = (GPIOA->IDR & (1 << 6)) ? 1 : 0;

        delay_ms(5);  // avoid too fast running
    }
}
