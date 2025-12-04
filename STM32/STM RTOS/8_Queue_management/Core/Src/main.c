/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

osThreadId defaultTaskHandle;
/* USER CODE BEGIN PV */

TaskHandle_t xTaskHandler1 = NULL;
TaskHandle_t xTaskHandler2 = NULL;
TaskHandle_t xTaskHandler3 = NULL;
TaskHandle_t xTaskHandler4 = NULL;

QueueHandle_t command_Queue = NULL;
QueueHandle_t uart_write_queue = NULL;

typedef struct APP_CMD
{
  uint8_t COMMAND_NUM;
  uint8_t COMMAND_ARGS[10];
} APP_CMD_t;

uint8_t rx_data;
uint8_t command_buffer[20];
uint8_t command_len = 0;

/* Response messages */
char msg_invalid_cmd[]   = "\r\nInvalid option. Try again.\r\n";
char msg_led_on[]        = "\r\nLED ON\r\n";
char msg_led_off[]       = "\r\nLED OFF\r\n";
char msg_led_toggle[]    = "\r\nLED TOGGLED\r\n";
char msg_led_read_on[]   = "\r\nLED STATUS: ON\r\n";
char msg_led_read_off[]  = "\r\nLED STATUS: OFF\r\n";
char msg_rtc_not_impl[]  = "\r\nRTC not implemented\r\n";
char msg_exit_not_impl[] = "\r\nEXIT not implemented in RTOS\r\n";

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
void StartDefaultTask(void const * argument);

/* USER CODE BEGIN PFP */
void vTask1_menu_display(void *params);
void vTask2_cmd_handling(void *params);
void vTask3_cmd_processing(void *params);
void vTask4_uart_write(void *params);
void vApplicationIdleHook(void);

/* UART print function */
void debug_printf(const char *fmt, ...)
{
    char buffer[256];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    HAL_UART_Transmit(&huart2, (uint8_t*)buffer, strlen(buffer), HAL_MAX_DELAY);
}

/* Menu string */
char menu[] =
"\r\n"
" LEd_ON              --->1\r\n"
" LEd_OFF             --->2\r\n"
" LED_TOGGLE          --->3\r\n"
" LED_TOGGLE_OFF      --->4\r\n"
" LED_READ_STATUS     --->5\r\n"
" RTC_PRINT_DATETIME  --->6\r\n"
" EXITAPP             --->0\r\n"
" Type your option : ";

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART2_UART_Init();

  debug_printf("This Queue command processing Demo\r\n");

  command_Queue     = xQueueCreate(10, sizeof(APP_CMD_t *));
  uart_write_queue  = xQueueCreate(10, sizeof(char *));

  HAL_UART_Receive_IT(&huart2, &rx_data, 1);

  if (command_Queue && uart_write_queue)
  {
    xTaskCreate(vTask1_menu_display, "MENU", 200, NULL, 1, &xTaskHandler1);
    xTaskCreate(vTask2_cmd_handling, "CMD_HANDLE", 200, NULL, 2, &xTaskHandler2);
    xTaskCreate(vTask3_cmd_processing,"CMD_PROC", 200, NULL, 2, &xTaskHandler3);
    xTaskCreate(vTask4_uart_write,    "UART_WRITE",200, NULL, 1, &xTaskHandler4);
  }
  else
  {
    debug_printf("Queue creation failed\r\n");
  }

  osKernelStart();

  while (1);
}

/* ------------------- SYSTEM INIT ------------------------- */

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 10;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;

  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                              | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;

  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4);
}

/* ---------------- UART2 INIT ------------------------- */

static void MX_USART2_UART_Init(void)
{
    huart2.Instance        = USART2;
    huart2.Init.BaudRate   = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits   = UART_STOPBITS_1;
    huart2.Init.Parity     = UART_PARITY_NONE;
    huart2.Init.Mode       = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;

    HAL_UART_Init(&huart2);

    /* Enable IRQ for USART2 */
    HAL_NVIC_SetPriority(USART2_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(USART2_IRQn);
}

/* ---------------- GPIO INIT ------------------------- */

static void MX_GPIO_Init(void)
{
  __HAL_RCC_GPIOA_CLK_ENABLE();
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* LED2 */
  GPIO_InitStruct.Pin   = LD2_Pin;
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull  = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);
}

/* ---------------- FreeRTOS TASKS ------------------------- */

/* Task1 : Print menu and wait for command */
void vTask1_menu_display(void *params)
{
  char *pData = menu;
  while (1)
  {
    xQueueSend(uart_write_queue, &pData, portMAX_DELAY);
    xTaskNotifyWait(0,0,NULL,portMAX_DELAY);
  }
}

/* Task2 : Parse command from UART input */
void vTask2_cmd_handling(void *params)
{
  char rcv_buf[20];

  while (1)
  {
    xTaskNotifyWait(0,0,NULL,portMAX_DELAY);

    memcpy(rcv_buf, command_buffer, command_len);
    rcv_buf[command_len] = '\0';
    command_len = 0;

    APP_CMD_t *new_cmd = pvPortMalloc(sizeof(APP_CMD_t));
    new_cmd->COMMAND_NUM = rcv_buf[0] - '0';

    memset(new_cmd->COMMAND_ARGS, 0, sizeof(new_cmd->COMMAND_ARGS));
    strncpy((char*)new_cmd->COMMAND_ARGS, &rcv_buf[1], 9);

    xQueueSend(command_Queue, &new_cmd, portMAX_DELAY);

    xTaskNotify(xTaskHandler1, 0, eNoAction);
  }
}

/* Task3 : Execute command */
void vTask3_cmd_processing(void *params)
{
  APP_CMD_t *cmd;
  char *pData;

  while (1)
  {
    xQueueReceive(command_Queue, &cmd, portMAX_DELAY);

    switch(cmd->COMMAND_NUM)
    {
      case 1: HAL_GPIO_WritePin(LD2_GPIO_Port,LD2_Pin,GPIO_PIN_SET); pData=msg_led_on; break;
      case 2: HAL_GPIO_WritePin(LD2_GPIO_Port,LD2_Pin,GPIO_PIN_RESET); pData=msg_led_off; break;
      case 3: HAL_GPIO_TogglePin(LD2_GPIO_Port,LD2_Pin); pData=msg_led_toggle; break;
      case 5:
        if(HAL_GPIO_ReadPin(LD2_GPIO_Port,LD2_Pin))
            pData = msg_led_read_on;
        else
            pData = msg_led_read_off;
        break;
      case 6: pData = msg_rtc_not_impl; break;
      case 0: pData = msg_exit_not_impl; break;
      default: pData = msg_invalid_cmd; break;
    }

    xQueueSend(uart_write_queue, &pData, portMAX_DELAY);
    vPortFree(cmd);
  }
}

/* Task4 : UART Write */
void vTask4_uart_write(void *params)
{
  char *pData;
  while (1)
  {
    xQueueReceive(uart_write_queue, &pData, portMAX_DELAY);
    debug_printf("%s", pData);
  }
}

/* UART RX interrupt callback */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART2)
  {
    command_buffer[command_len++] = rx_data;

    if (rx_data == '\r')
      xTaskNotifyFromISR(xTaskHandler2, 0, eNoAction, NULL);

    if (command_len >= sizeof(command_buffer))
      command_len = 0;

    HAL_UART_Receive_IT(&huart2, &rx_data, 1);
  }
}

void vApplicationIdleHook(void)
{
    /* Optional: __WFI(); */
}

/* Error Handler */
void Error_Handler(void)
{
  __disable_irq();
  while (1) {}
}
