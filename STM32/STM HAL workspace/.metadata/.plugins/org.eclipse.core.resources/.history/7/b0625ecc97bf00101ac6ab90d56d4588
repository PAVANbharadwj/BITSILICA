#include "adc.h"

ADC_HandleTypeDef hadc1;

/**
  * @brief  Initialize ADC1 in continuous conversion mode.
  *         Channel 0 (PA0) is used by default.
  */
void ADC1_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_ADC1_CLK_ENABLE();

    // === Configure PA0 (ADC1_IN0) ===
    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // === Configure ADC1 ===
    hadc1.Instance = ADC1;
    hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
    hadc1.Init.Resolution = ADC_RESOLUTION_12B;
    hadc1.Init.ScanConvMode = DISABLE;
    hadc1.Init.ContinuousConvMode = ENABLE;        // Continuous mode enabled
    hadc1.Init.DiscontinuousConvMode = DISABLE;
    hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
    hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
    hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
    hadc1.Init.NbrOfConversion = 1;
    hadc1.Init.DMAContinuousRequests = DISABLE;
    hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
    HAL_ADC_Init(&hadc1);

    // === Configure ADC channel (PA0 → ADC_CHANNEL_0) ===
    ADC_ChannelConfTypeDef sConfig = {0};
    sConfig.Channel = ADC_CHANNEL_0;
    sConfig.Rank = 1;
    sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
    HAL_ADC_ConfigChannel(&hadc1, &sConfig);
}

/**
  * @brief  Start continuous ADC conversions.
  */
void ADC1_Start(void)
{
    HAL_ADC_Start(&hadc1);
}

/**
  * @brief  Read the latest ADC converted value.
  * @retval 12-bit ADC result (0–4095)
  */
uint32_t ADC1_ReadValue(void)
{
    // Wait for conversion to complete
    HAL_ADC_PollForConversion(&hadc1, 10);

    // Return latest converted value
    return HAL_ADC_GetValue(&hadc1);
}
