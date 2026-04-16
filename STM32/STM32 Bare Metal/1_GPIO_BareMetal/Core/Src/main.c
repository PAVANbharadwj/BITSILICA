
#include "main.h"

void delay_ms(volatile uint32_t t)
{
    while(t--);
}

int main(void)
{

	    RCC->AHB2ENR |= (1 << 0);
	    RCC->AHB2ENR |= (1 << 2);


	    GPIOA->MODER &= ~(3 << (5 * 2));
	    GPIOA->MODER |=  (1 << (5 * 2));

	    GPIOC->MODER &= ~(3 << (13 * 2));

	    GPIOC->PUPDR &= ~(3 << (13 * 2));
	    GPIOC->PUPDR |=  (1 << (13 * 2));

	    while(1)
	    {
	        if ((GPIOC->IDR & (1 << 13)) == 0)
	        {
	            delay_ms(200000);

	            GPIOA->ODR ^= (1 << 5);

	            while ((GPIOC->IDR & (1 << 13)) == 0);
	            delay_ms(200000);
	        }
	    }
}




