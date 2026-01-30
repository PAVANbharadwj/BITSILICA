#ifndef STM32L476XX_H
#define STM32L476XX_H

#include <stdint.h>

#define __IO volatile

/* ============================================================
   BASE ADDRESSES
   ============================================================ */

#define PERIPH_BASEADDR        0x40000000U
#define APB1_BASEADDR          PERIPH_BASEADDR
#define APB2_BASEADDR          (PERIPH_BASEADDR + 0x00010000U)
#define AHB2_BASEADDR          0x48000000U

/* GPIO */
#define GPIOA_BASEADDR         (AHB2_BASEADDR + 0x0000)
#define GPIOB_BASEADDR         (AHB2_BASEADDR + 0x0400)
#define GPIOC_BASEADDR         (AHB2_BASEADDR + 0x0800)

/* RCC */
#define RCC_BASEADDR           0x40021000U

/* USART2 */
#define USART2_BASEADDR        (APB1_BASEADDR + 0x4400)

/* TIM3 */
#define TIM3_BASEADDR          (APB1_BASEADDR + 0x0400)

/* SysTick */
#define SYSTICK_BASE           0xE000E010U

/* SCB */
#define SCB_BASE               0xE000ED00U

/* NVIC */
#define NVIC_ISER_BASE         0xE000E100U
#define NVIC_IPR_BASE          0xE000E400U


/* ============================================================
   STRUCT DEFINITIONS
   ============================================================ */

typedef struct {
    __IO uint32_t MODER;
    __IO uint32_t OTYPER;
    __IO uint32_t OSPEEDR;
    __IO uint32_t PUPDR;
    __IO uint32_t IDR;
    __IO uint32_t ODR;
    __IO uint32_t BSRR;
    __IO uint32_t LCKR;
    __IO uint32_t AFR[2];
    __IO uint32_t BRR;
    __IO uint32_t ASCR;
} GPIO_RegDef_t;


typedef struct {
    __IO uint32_t CR;
    __IO uint32_t ICSCR;
    __IO uint32_t CFGR;
    __IO uint32_t PLLCFGR;
    uint32_t RESERVED0[5];
    __IO uint32_t AHB1RSTR;
    __IO uint32_t AHB2RSTR;
    __IO uint32_t AHB3RSTR;
    uint32_t RESERVED1;
    __IO uint32_t APB1RSTR1;
    __IO uint32_t APB1RSTR2;
    __IO uint32_t APB2RSTR;
    uint32_t RESERVED2;
    __IO uint32_t AHB1ENR;
    __IO uint32_t AHB2ENR;
    __IO uint32_t AHB3ENR;
    uint32_t RESERVED3;
    __IO uint32_t APB1ENR1;
    __IO uint32_t APB1ENR2;
    __IO uint32_t APB2ENR;
} RCC_RegDef_t;


typedef struct {
    __IO uint32_t CR1;
    __IO uint32_t CR2;
    __IO uint32_t CR3;
    __IO uint32_t BRR;
    __IO uint32_t GTPR;
    __IO uint32_t RTOR;
    __IO uint32_t RQR;
    __IO uint32_t ISR;
    __IO uint32_t ICR;
    __IO uint32_t RDR;
    __IO uint32_t TDR;
} USART_TypeDef;


typedef struct {
    __IO uint32_t CR1;
    __IO uint32_t CR2;
    __IO uint32_t SMCR;
    __IO uint32_t DIER;
    __IO uint32_t SR;
    __IO uint32_t EGR;
    __IO uint32_t CCMR1;
    __IO uint32_t CCMR2;
    __IO uint32_t CCER;
    __IO uint32_t CNT;
    __IO uint32_t PSC;
    __IO uint32_t ARR;
    __IO uint32_t RCR;
    __IO uint32_t CCR1;
    __IO uint32_t CCR2;
    __IO uint32_t CCR3;
    __IO uint32_t CCR4;
} TIM_RegDef_t;


typedef struct {
    __IO uint32_t CTRL;
    __IO uint32_t LOAD;
    __IO uint32_t VAL;
    __IO uint32_t CALIB;
} SysTick_Type;


typedef struct {
    __IO uint32_t CPUID;
    __IO uint32_t ICSR;
    __IO uint32_t VTOR;
    __IO uint32_t AIRCR;
    __IO uint32_t SCR;
    __IO uint32_t CCR;
    __IO uint32_t SHPR[3];
    __IO uint32_t SHCSR;
    __IO uint32_t CFSR;
    __IO uint32_t HFSR;
    __IO uint32_t DFSR;
    __IO uint32_t MMFAR;
    __IO uint32_t BFAR;
    __IO uint32_t AFSR;
    __IO uint32_t CPACR;
} SCB_Type;


/* ============================================================
   PERIPHERAL DEFINES
   ============================================================ */

#define GPIOA       ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB       ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC       ((GPIO_RegDef_t*)GPIOC_BASEADDR)

#define RCC         ((RCC_RegDef_t*)RCC_BASEADDR)

#define USART2      ((USART_TypeDef*)USART2_BASEADDR)

#define TIM3        ((TIM_RegDef_t*)TIM3_BASEADDR)

#define SysTick     ((SysTick_Type*)SYSTICK_BASE)

#define SCB         ((SCB_Type*)SCB_BASE)

#define GPIOA_PCLK_EN()  (RCC->AHB2ENR |= (1 << 0))


/* ============================================================
   RCC CLOCK BITS
   ============================================================ */

#define RCC_AHB2ENR_GPIOAEN     (1 << 0)
#define RCC_AHB2ENR_GPIOBEN     (1 << 1)
#define RCC_AHB2ENR_GPIOCEN     (1 << 2)

#define RCC_APB1ENR1_TIM3EN     (1 << 1)
#define RCC_APB1ENR1_USART2EN   (1 << 17)


/* ============================================================
   USART BITS (ALL MISSING ONES)
   ============================================================ */

#define USART_CR1_UE            (1U << 0)
#define USART_CR1_RE            (1U << 2)
#define USART_CR1_TE            (1U << 3)
#define USART_CR1_RXNEIE        (1U << 5)

#define USART_ISR_RXNE          (1U << 5)
#define USART_ISR_TXE           (1U << 7)


/* ============================================================
   TIM3 BIT DEFINES
   ============================================================ */

#define TIM_CCMR1_CC1S          (3U << 0)
#define TIM_CCER_CC1E           (1U << 0)
#define TIM_CCER_CC1P           (1U << 1)
#define TIM_CCER_CC1NP          (1U << 3)
#define TIM_CR1_CEN             (1U << 0)
#define TIM_SR_CC1IF            (1U << 1)


/* ============================================================
   SYSTICK BIT DEFINES
   ============================================================ */

#define SysTick_CTRL_ENABLE_Msk      (1U << 0)
#define SysTick_CTRL_TICKINT_Msk     (1U << 1)
#define SysTick_CTRL_CLKSOURCE_Msk   (1U << 2)


/* ============================================================
   IRQ NUMBERS
   ============================================================ */

#define USART2_IRQn     38
#define SysTick_IRQn    -1


/* ============================================================
   NVIC FUNCTIONS
   ============================================================ */

static inline void NVIC_SetPriority(int IRQn, uint32_t priority)
{
    volatile uint32_t *ipr = (uint32_t*)(NVIC_IPR_BASE);
    ipr[IRQn] = priority << 4;
}

static inline void NVIC_EnableIRQ(int IRQn)
{
    volatile uint32_t *iser = (uint32_t*)(NVIC_ISER_BASE + (IRQn/32)*4);
    *iser = (1 << (IRQn % 32));
}


/* ============================================================
   CPU INTRINSICS
   ============================================================ */

#define __DSB() __asm volatile ("dsb")
#define __WFI() __asm volatile ("wfi")


#endif /* STM32L476XX_H */
