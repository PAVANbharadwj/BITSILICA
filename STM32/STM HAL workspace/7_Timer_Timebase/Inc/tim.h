#ifndef __TIM_H
#define __TIM_H

#include "stm32f4xx_hal.h"

// === Configuration Macros ===
#define TIMx                 TIM3
#define TIMx_CLK_ENABLE()    __HAL_RCC_TIM3_CLK_ENABLE()
#define TIMx_IRQn            TIM3_IRQn
#define TIMx_IRQHandler      TIM3_IRQHandler

// === Function Prototypes ===
void tim_timebase_init(void);

#endif
