#include "stm32l476xx.h"
#include "stm32l476xx_gpio_driver.h"
#include "stm32l476xx_usart_driver.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>

/* logging flash area (choose safe zone in your map) */
#define LOG_FLASH_ADDR   0x08080000U
#define LOG_FLASH_SECTOR 7U

static uint32_t flash_write_ptr = LOG_FLASH_ADDR;

/* Pins via driver defines */
#define TRIG_PIN_NO    GPIO_PIN_NO_9   /* PA9 */
#define ECHO_PIN_NO    GPIO_PIN_NO_8   /* PA8 TIM1_CH1 */
#define BUTTON_PIN_NO  GPIO_PIN_NO_13  /* PC13 */

/* USART handle */
static USART_Handle_t huart2;

/* SysTick microsecond delay (assumes 80MHz) */
void delay_us(uint32_t us)
{
    SysTick->LOAD = (80U * us);
    SysTick->VAL  = 0;
    SysTick->CTRL = 5;
    while(!(SysTick->CTRL & (1U << 16)));
    SysTick->CTRL = 0;
}
void delay_ms(uint32_t ms) { while(ms--) delay_us(1000); }

/* UART init using driver + GPIO driver */
void UART2_Init_using_driver(void)
{
    GPIO_Handle_t gpio;

    GPIO_PeriClockControl(GPIOA, ENABLE);

    gpio.pGPIOx = GPIOA;
    gpio.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
    gpio.GPIO_PinConfig.GPIO_PinAltFunMode = 7;
    gpio.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    gpio.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    gpio.GPIO_PinConfig.GPIO_PinSpeed = GPIO_HIGH_SPEED;

    gpio.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_2; GPIO_Init(&gpio); /* PA2 TX */
    gpio.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_3; GPIO_Init(&gpio); /* PA3 RX */

    huart2.pUSARTx = USART2;
    huart2.USART_Config.USART_Mode = USART_MODE_TXRX;
    huart2.USART_Config.USART_Baud = USART_STD_BAUD_9600;
    huart2.USART_Config.USART_NoOfStopBits = USART_STOPBITS_1;
    huart2.USART_Config.USART_WordLength = USART_WORDLEN_8BITS;
    huart2.USART_Config.USART_ParityControl = USART_PARITY_DISABLE;
    huart2.USART_Config.USART_HWFlowControl = USART_HW_FLOW_CTRL_NONE;

    USART_Init(&huart2);
}

/* helper send */
void UART2_SendString(const char *s)
{
    size_t len = strlen(s);
    if(len) USART_SendData(&huart2, (uint8_t*)s, (uint32_t)len);
}

/* App GPIO init (TRIG, ECHO, BUTTON) */
void App_GPIO_Init(void)
{
    GPIO_Handle_t h;
    GPIO_PeriClockControl(GPIOA, ENABLE);
    GPIO_PeriClockControl(GPIOC, ENABLE);
    /* TRIG PA9 output */
    h.pGPIOx = GPIOA;
    h.GPIO_PinConfig.GPIO_PinNumber = TRIG_PIN_NO;
    h.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    h.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    h.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    h.GPIO_PinConfig.GPIO_PinSpeed = GPIO_HIGH_SPEED;
    GPIO_Init(&h);

    /* ECHO PA8 AF1 (TIM1) */
    h.pGPIOx = GPIOA;
    h.GPIO_PinConfig.GPIO_PinNumber = ECHO_PIN_NO;
    h.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
    h.GPIO_PinConfig.GPIO_PinAltFunMode = 1; /* AF1 */
    h.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    h.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    h.GPIO_PinConfig.GPIO_PinSpeed = GPIO_HIGH_SPEED;
    GPIO_Init(&h);

    /* BUTTON PC13 input pull-up */
    h.pGPIOx = GPIOC;
    h.GPIO_PinConfig.GPIO_PinNumber = BUTTON_PIN_NO;
    h.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
    h.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
    GPIO_Init(&h);
}

/* TIM1 Input-capture init */
void TIM1_InputCapture_Init(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
    TIM1->PSC = 80U - 1U; /* 1 MHz */
    TIM1->ARR = 0xFFFFU;
    TIM1->CCMR1 &= ~0xFFU;
    TIM1->CCMR1 |= 1U; /* CC1 mapped to TI1 */
    TIM1->CCER &= ~(1U << 1); /* rising */
    TIM1->CCER |= (1U << 0);  /* enable */
    TIM1->CR1 |= 1U;
}

/* Flash helpers: assumes FLASH wrapper in header */
void Flash_Unlock(void)
{
    if(FLASH->CR & (1U << 31)) /* FLASH_CR_LOCK bit ID may vary; if not available ignore */
    {
        FLASH->KEYR = 0x45670123U;
        FLASH->KEYR = 0xCDEF89ABU;
    }
}
void Flash_Lock(void) { FLASH->CR |= (1U<<31); }
void Flash_EraseSector(uint8_t sec)
{
    Flash_Unlock();
    FLASH->CR &= ~(0xFFU);
    FLASH->CR |= ((uint32_t)sec << 3); /* PNB pos in your header variant */
    FLASH->CR |= (1U<<1); /* PER */
    FLASH->CR |= (1U<<16); /* START - adjust if different */
    while (FLASH->SR & (1U<<16)); /* BSY */
    FLASH->CR &= ~(1U<<1);
    Flash_Lock();
}
void Flash_Write64(uint32_t addr, uint64_t data)
{
    Flash_Unlock();
    FLASH->CR |= (1U<<0); /* PG */
    *(volatile uint64_t*)addr = data;
    while (FLASH->SR & (1U<<16));
    FLASH->CR &= ~(1U<<0);
    Flash_Lock();
}
uint32_t Flash_Read32(uint32_t addr) { return *(volatile uint32_t*)addr; }

/* Ultrasonic measure (us -> cm) */
uint32_t Ultrasonic_Measure(void)
{
    uint32_t start = 0, end = 0;
    GPIO_WriteToOutputPin(GPIOA, TRIG_PIN_NO, GPIO_PIN_RESET);
    delay_us(2);
    GPIO_WriteToOutputPin(GPIOA, TRIG_PIN_NO, GPIO_PIN_SET);
    delay_us(10);
    GPIO_WriteToOutputPin(GPIOA, TRIG_PIN_NO, GPIO_PIN_RESET);

    TIM1->CNT = 0;
    TIM1->CCER &= ~(1U << 1);
    TIM1->SR &= ~(1U << 1);
    while(!(TIM1->SR & (1U << 1)));
    start = TIM1->CCR1;
    TIM1->SR &= ~(1U << 1);

    TIM1->CCER |= (1U << 1);
    while(!(TIM1->SR & (1U << 1)));
    end = TIM1->CCR1;
    TIM1->SR &= ~(1U << 1);

    uint32_t width = (end >= start) ? (end - start) : ((0xFFFFU - start) + end);
    uint32_t distance = width / 58U;
    return distance;
}

/* Print logged flash */
void Print_Logged_Data(void)
{
    UART2_SendString("\r\n--- Stored Distances ---\r\n");
    for(uint32_t addr = LOG_FLASH_ADDR; addr < flash_write_ptr; addr += 8)
    {
        uint32_t d = Flash_Read32(addr);
        char buf[48];
        int n = sprintf(buf, "%lu cm\r\n", (unsigned long)d);
        if(n>0) USART_SendData(&huart2, (uint8_t*)buf, (uint32_t)n);
    }
}

/* main */

uint32_t dist;
int main(void)
{
    App_GPIO_Init();
    TIM1_InputCapture_Init();
    UART2_Init_using_driver();

    //delay_ms(1500); /* allow VCP up */

    Flash_EraseSector(LOG_FLASH_SECTOR);
    flash_write_ptr = LOG_FLASH_ADDR;

    UART2_SendString("System started (driver-based UART)\r\n");

    while(1)
    {
        dist = Ultrasonic_Measure();
        uint64_t data = ((uint64_t)dist << 32) | dist;
        Flash_Write64(flash_write_ptr, data);
        flash_write_ptr += 8;

        char out[64];
        int n = sprintf(out, "Distance = %lu cm\r\n", (unsigned long)dist);
        if(n>0) USART_SendData(&huart2, (uint8_t*)out, (uint32_t)n);

        delay_ms(10);

        if(GPIO_ReadFromInputPin(GPIOC, BUTTON_PIN_NO) == 0) /* pressed */
        {
            delay_ms(200);
            Print_Logged_Data();
            while(GPIO_ReadFromInputPin(GPIOC, BUTTON_PIN_NO) == 0) delay_ms(10);
        }
    }
}
