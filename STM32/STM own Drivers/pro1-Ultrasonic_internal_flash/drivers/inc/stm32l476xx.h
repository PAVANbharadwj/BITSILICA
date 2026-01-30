#ifndef STM32L476XX_H
#define STM32L476XX_H

#include <stdint.h>

#define __IO volatile

/* ----------------------------------------------------------
   BASE ADDRESSES
   ---------------------------------------------------------- */
#define FLASH_BASEADDR                0x08000000U
#define PERIPH_BASEADDR               0x40000000U
#define AHB2_BASEADDR                 0x48000000U
#define APB1_BASEADDR                 0x40000000U
#define APB2_BASEADDR                 0x40010000U

/* AHB2 peripherals */
#define GPIOA_BASEADDR                (AHB2_BASEADDR + 0x0000)
#define GPIOB_BASEADDR                (AHB2_BASEADDR + 0x0400)
#define GPIOC_BASEADDR                (AHB2_BASEADDR + 0x0800)
#define GPIOD_BASEADDR                (AHB2_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR                (AHB2_BASEADDR + 0x1000)
#define GPIOF_BASEADDR                (AHB2_BASEADDR + 0x1400)
#define GPIOG_BASEADDR                (AHB2_BASEADDR + 0x1800)
#define GPIOH_BASEADDR                (AHB2_BASEADDR + 0x1C00)

/* RCC / SYSCFG / EXTI */
#define RCC_BASEADDR                  (0x40021000U)
#define SYSCFG_BASEADDR               (APB2_BASEADDR + 0x0000)
#define EXTI_BASEADDR                 (APB2_BASEADDR + 0x0400)

/* USART base addresses */
#define USART1_BASEADDR               (APB2_BASEADDR + 0x3800)
#define USART2_BASEADDR               (APB1_BASEADDR + 0x4400)
#define USART3_BASEADDR               (APB1_BASEADDR + 0x4800)
#define UART4_BASEADDR                (APB1_BASEADDR + 0x4C00)
#define UART5_BASEADDR                (APB1_BASEADDR + 0x5000)

/* TIM */
#define TIM1_BASEADDR                 (APB2_BASEADDR + 0x2C00)

/* ----------------------------------------------------------
   REGISTER STRUCTURES
   ---------------------------------------------------------- */
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
    __IO uint32_t PLLSAI1CFGR;
    __IO uint32_t PLLSAI2CFGR;
    __IO uint32_t CIER;
    __IO uint32_t CIFR;
    __IO uint32_t CICR;
    uint32_t RESERVED0;
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
    uint32_t RESERVED4;
    __IO uint32_t AHB1SMENR;
    __IO uint32_t AHB2SMENR;
    __IO uint32_t AHB3SMENR;
    uint32_t RESERVED5;
    __IO uint32_t APB1SMENR1;
    __IO uint32_t APB1SMENR2;
    __IO uint32_t APB2SMENR;
    uint32_t RESERVED6;
    __IO uint32_t CCIPR;
    uint32_t RESERVED7;
    __IO uint32_t BDCR;
    __IO uint32_t CSR;
    __IO uint32_t CRRCR;
    __IO uint32_t CCIPR2;
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
    __IO uint32_t IMR1;
    __IO uint32_t EMR1;
    __IO uint32_t RTSR1;
    __IO uint32_t FTSR1;
    __IO uint32_t SWIER1;
    __IO uint32_t PR1;
    uint32_t RESERVED1[2];
    __IO uint32_t IMR2;
    __IO uint32_t EMR2;
    __IO uint32_t RTSR2;
    __IO uint32_t FTSR2;
    __IO uint32_t SWIER2;
    __IO uint32_t PR2;
} EXTI_RegDef_t;

typedef struct {
    __IO uint32_t MEMRMP;
    __IO uint32_t CFGR1;
    __IO uint32_t EXTICR[4];
    __IO uint32_t SCSR;
    __IO uint32_t CFGR2;
    __IO uint32_t SWPR;
    __IO uint32_t SKR;
} SYSCFG_RegDef_t;

/* TIM1 */
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
    __IO uint32_t BDTR;
} TIM_RegDef_t;

/* SysTick */
typedef struct {
    __IO uint32_t CTRL;
    __IO uint32_t LOAD;
    __IO uint32_t VAL;
    __IO uint32_t CALIB;
} SysTick_RegDef_t;

/* FLASH */
typedef struct {
    __IO uint32_t ACR;
    __IO uint32_t KEYR;
    __IO uint32_t OPTKEYR;
    __IO uint32_t SR;
    __IO uint32_t CR;
    __IO uint32_t ECCR;
} FLASH_RegDef_t;

/* ----------------------------------------------------------
   PERIPHERAL INSTANCES
   ---------------------------------------------------------- */
#define GPIOA   ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB   ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC   ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD   ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE   ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF   ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG   ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH   ((GPIO_RegDef_t*)GPIOH_BASEADDR)

#define RCC     ((RCC_RegDef_t*)RCC_BASEADDR)
#define SYSCFG  ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)
#define EXTI    ((EXTI_RegDef_t*)EXTI_BASEADDR)

#define USART1  ((USART_TypeDef*)USART1_BASEADDR)
#define USART2  ((USART_TypeDef*)USART2_BASEADDR)
#define USART3  ((USART_TypeDef*)USART3_BASEADDR)
#define UART4   ((USART_TypeDef*)UART4_BASEADDR)
#define UART5   ((USART_TypeDef*)UART5_BASEADDR)

#define TIM1    ((TIM_RegDef_t*)TIM1_BASEADDR)
#define FLASH   ((FLASH_RegDef_t*)(FLASH_BASEADDR + 0x400))
#define SysTick ((SysTick_RegDef_t*)0xE000E010U)

/* ----------------------------------------------------------
   RCC CLOCK MACROS
   ---------------------------------------------------------- */
#define GPIOA_PCLK_EN() (RCC->AHB2ENR |= (1<<0))
#define GPIOB_PCLK_EN() (RCC->AHB2ENR |= (1<<1))
#define GPIOC_PCLK_EN() (RCC->AHB2ENR |= (1<<2))
#define GPIOD_PCLK_EN() (RCC->AHB2ENR |= (1<<3))
#define GPIOE_PCLK_EN() (RCC->AHB2ENR |= (1<<4))
#define GPIOF_PCLK_EN() (RCC->AHB2ENR |= (1<<5))
#define GPIOG_PCLK_EN() (RCC->AHB2ENR |= (1<<6))
#define GPIOH_PCLK_EN() (RCC->AHB2ENR |= (1<<7))

#define GPIOA_PCLK_DI() (RCC->AHB2ENR &= ~(1<<0))
#define GPIOB_PCLK_DI() (RCC->AHB2ENR &= ~(1<<1))
#define GPIOC_PCLK_DI() (RCC->AHB2ENR &= ~(1<<2))
#define GPIOD_PCLK_DI() (RCC->AHB2ENR &= ~(1<<3))
#define GPIOE_PCLK_DI() (RCC->AHB2ENR &= ~(1<<4))
#define GPIOF_PCLK_DI() (RCC->AHB2ENR &= ~(1<<5))
#define GPIOG_PCLK_DI() (RCC->AHB2ENR &= ~(1<<6))
#define GPIOH_PCLK_DI() (RCC->AHB2ENR &= ~(1<<7))

#define GPIOA_REG_RESET() do{ RCC->AHB2RSTR |= (1<<0); RCC->AHB2RSTR &= ~(1<<0);}while(0)
#define GPIOB_REG_RESET() do{ RCC->AHB2RSTR |= (1<<1); RCC->AHB2RSTR &= ~(1<<1);}while(0)
#define GPIOC_REG_RESET() do{ RCC->AHB2RSTR |= (1<<2); RCC->AHB2RSTR &= ~(1<<2);}while(0)
#define GPIOD_REG_RESET() do{ RCC->AHB2RSTR |= (1<<3); RCC->AHB2RSTR &= ~(1<<3);}while(0)
#define GPIOE_REG_RESET() do{ RCC->AHB2RSTR |= (1<<4); RCC->AHB2RSTR &= ~(1<<4);}while(0)
#define GPIOF_REG_RESET() do{ RCC->AHB2RSTR |= (1<<5); RCC->AHB2RSTR &= ~(1<<5);}while(0)
#define GPIOG_REG_RESET() do{ RCC->AHB2RSTR |= (1<<6); RCC->AHB2RSTR &= ~(1<<6);}while(0)
#define GPIOH_REG_RESET() do{ RCC->AHB2RSTR |= (1<<7); RCC->AHB2RSTR &= ~(1<<7);}while(0)

/* ----------------------------------------------------------
   USART DEFINITIONS
   ---------------------------------------------------------- */
#define USART_CR1_UE     (1<<0)
#define USART_CR1_RE     (1<<2)
#define USART_CR1_TE     (1<<3)
#define USART_CR1_RXNEIE (1<<5)
#define USART_CR1_TXEIE  (1<<7)

/* STOP BITS */
#define USART_CR2_STOP_Pos 12
#define USART_CR2_STOP     (3U << USART_CR2_STOP_Pos)

/* FLOW CONTROL */
#define USART_CR3_CTSE   (1<<9)
#define USART_CR3_RTSE   (1<<8)

/* FLAGS */
#define USART_ISR_RXNE   (1<<5)
#define USART_ISR_TC     (1<<6)
#define USART_ISR_TXE    (1<<7)

/* ----------------------------------------------------------
   NVIC REGISTERS
   ---------------------------------------------------------- */
#define NVIC_ISER0 ((volatile uint32_t*)0xE000E100)
#define NVIC_ISER1 ((volatile uint32_t*)0xE000E104)
#define NVIC_ISER2 ((volatile uint32_t*)0xE000E108)

#define NVIC_ICER0 ((volatile uint32_t*)0xE000E180)
#define NVIC_ICER1 ((volatile uint32_t*)0xE000E184)
#define NVIC_ICER2 ((volatile uint32_t*)0xE000E188)

#define NVIC_PR_BASE_ADDR ((volatile uint32_t*)0xE000E400)
#define NO_PR_BITS_IMPLEMENTED 4

/* ----------------------------------------------------------
   GENERIC DEFINES
   ---------------------------------------------------------- */
#define ENABLE 1
#define DISABLE 0
#define SET 1
#define RESET 0
#define GPIO_PIN_SET   SET
#define GPIO_PIN_RESET RESET

#define GPIO_BASEADDR_TO_CODE(x) \
   ((x==GPIOA)?0: (x==GPIOB)?1: (x==GPIOC)?2: (x==GPIOD)?3: \
    (x==GPIOE)?4: (x==GPIOF)?5: (x==GPIOG)?6: (x==GPIOH)?7:0)

#endif
