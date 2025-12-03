#include "tim.h"

TIM_HandleTypeDef TimHandle;

void tim_timebase_init(void)
{
    // Enable Timer Clock
    TIMx_CLK_ENABLE();

    // Configure Timer Base
    TimHandle.Instance = TIMx;
    TimHandle.Init.Prescaler = 1600 - 1;                // 84MHz / 1600 = 52.5kHz
    TimHandle.Init.Period = 10000 - 1;                  // 52.5kHz / 10000 = 5.25Hz (~190ms)
    TimHandle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    TimHandle.Init.CounterMode = TIM_COUNTERMODE_UP;
    TimHandle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

    HAL_TIM_Base_Init(&TimHandle);

    HAL_NVIC_SetPriority(TIMx_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIMx_IRQn);

    HAL_TIM_Base_Start_IT(&TimHandle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}

void TIMx_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&TimHandle);
}
