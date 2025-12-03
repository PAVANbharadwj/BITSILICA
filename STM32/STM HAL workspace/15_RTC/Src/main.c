#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <string.h>

#define RTC_ASYNCH_PREDIV   0x7F
#define RTC_SYNCH_PREDIV    0xF9
#define BK_FLAG             0x8888

RTC_HandleTypeDef RtcHandle;

uint8_t time[15] = {0};  // Buffer for time string: "HH:MM:SS"
uint8_t date[15] = {0};  // Buffer for date string: "DD/MM/YYYY"

// Function prototypes
void rtc_init(void);
void rtc_calendar_show(void);
void rtc_calendar_config(void);

int main(void)
{
    HAL_Init();
    rtc_init();

    if (HAL_RTCEx_BKUPRead(&RtcHandle, RTC_BKP_DR0) != BK_FLAG)
    {
        rtc_calendar_config();
    }

    while (1)
    {
        rtc_calendar_show();
        HAL_Delay(1000); // 1-second delay for live update
    }
}

void rtc_calendar_config(void)
{
    RTC_DateTypeDef sdatestructure = {0};
    RTC_TimeTypeDef stimestructure = {0};

    // --- Set initial Date ---
    sdatestructure.Year = 0x25;                // 2025
    sdatestructure.Month = RTC_MONTH_NOVEMBER;
    sdatestructure.Date = 0x13;
    sdatestructure.WeekDay = RTC_WEEKDAY_THURSDAY;

    HAL_RTC_SetDate(&RtcHandle, &sdatestructure, RTC_FORMAT_BCD);

    // --- Set initial Time ---
    stimestructure.Hours = 0x10;               // 16:00:00
    stimestructure.Minutes = 0x00;
    stimestructure.Seconds = 0x00;
    stimestructure.TimeFormat = RTC_HOURFORMAT12_AM;
    stimestructure.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
    stimestructure.StoreOperation = RTC_STOREOPERATION_RESET;

    HAL_RTC_SetTime(&RtcHandle, &stimestructure, RTC_FORMAT_BCD);

    // Mark configuration complete
    HAL_RTCEx_BKUPWrite(&RtcHandle, RTC_BKP_DR0, BK_FLAG);
}

void rtc_calendar_show(void)
{
    RTC_DateTypeDef sdatestructure = {0};
    RTC_TimeTypeDef stimestructure = {0};

    HAL_RTC_GetTime(&RtcHandle, &stimestructure, RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&RtcHandle, &sdatestructure, RTC_FORMAT_BIN);

    // Format and store in buffers (for Live Expressions)
    sprintf((char *)time, "%02d:%02d:%02d",
            stimestructure.Hours, stimestructure.Minutes, stimestructure.Seconds);

    sprintf((char *)date, "%02d/%02d/%04d",
            sdatestructure.Date, sdatestructure.Month, 2000 + sdatestructure.Year);
    printf("Time: %s  Date: %s\n",time,date);
}

void rtc_init(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

    // Enable backup domain access
    __HAL_RCC_PWR_CLK_ENABLE();
    HAL_PWR_EnableBkUpAccess();

    // --- RTC Clock Source Configuration ---
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI;
    RCC_OscInitStruct.LSEState = RCC_LSE_OFF;
    RCC_OscInitStruct.LSIState = RCC_LSI_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
    HAL_RCC_OscConfig(&RCC_OscInitStruct);

    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
    PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
    HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct);

    __HAL_RCC_RTC_ENABLE();

    // --- RTC Configuration ---
    RtcHandle.Instance = RTC;
    RtcHandle.Init.HourFormat = RTC_HOURFORMAT_24;
    RtcHandle.Init.AsynchPrediv = RTC_ASYNCH_PREDIV;
    RtcHandle.Init.SynchPrediv = RTC_SYNCH_PREDIV;
    RtcHandle.Init.OutPut = RTC_OUTPUT_DISABLE;

    HAL_RTC_Init(&RtcHandle);
}

void SysTick_Handler(void)
{
    HAL_IncTick();
}
