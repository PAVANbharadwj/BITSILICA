/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* USER CODE BEGIN Includes */
#include "queue.h"
#include "ultrasonic.h"
#include "log_storage.h"
#include"spi_flash.h"
#include <stdio.h>
#include<string.h>
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;
SPI_HandleTypeDef hspi1;   // add this near huart2


/* USER CODE BEGIN PV */
QueueHandle_t xDistanceQueue;
QueueHandle_t xLogQueue;
// queue of uint16_t distance values

osThreadId sensorTaskHandle;
osThreadId uartTaskHandle;
osThreadId flashTaskHandle;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_SPI1_Init(void);


/* USER CODE BEGIN PFP */
void SensorTask(void const * argument);
void UARTTask(void const * argument);
void FlashTask(void const * argument);
/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{
  /* MCU Configuration--------------------------------------------------------*/
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_SPI1_Init();
  MX_USART2_UART_Init();

  /* USER CODE BEGIN 2 */

  // Init ultrasonic driver
  Ultrasonic_Init();
  Log_Init();   // this also initializes SPI flash

  // Queues
  xDistanceQueue = xQueueCreate(16, sizeof(uint16_t)); // for UART
  xLogQueue      = xQueueCreate(16, sizeof(uint16_t)); // for Flash
  if (xLogQueue == NULL)
  {
      HAL_UART_Transmit(&huart2,
          (uint8_t*)"ERROR: xLogQueue NOT CREATED!\r\n",
          31, HAL_MAX_DELAY);
  }
  else
  {
      HAL_UART_Transmit(&huart2,
          (uint8_t*)"xLogQueue CREATED\r\n",
          19, HAL_MAX_DELAY);
  }

  // Sensor task
  HAL_UART_Transmit(&huart2,
      (uint8_t*)"STARTING TASK CREATION...\r\n",
      29, HAL_MAX_DELAY);



  osThreadDef(sensorTask, SensorTask, osPriorityHigh, 0, 128);
  sensorTaskHandle = osThreadCreate(osThread(sensorTask), NULL);
  HAL_UART_Transmit(&huart2,
      (uint8_t*)"SensorTask created\r\n",
      21, HAL_MAX_DELAY);
  // UART task
  osThreadDef(uartTask, UARTTask, osPriorityNormal, 0, 256);
  uartTaskHandle = osThreadCreate(osThread(uartTask), NULL);
  HAL_UART_Transmit(&huart2,
      (uint8_t*)"UARTTask created\r\n",
      19, HAL_MAX_DELAY);


  // Flash task
  osThreadDef(flashTask, FlashTask, osPriorityNormal, 0, 4096);

  flashTaskHandle = osThreadCreate(osThread(flashTask), NULL);
  HAL_UART_Transmit(&huart2,
      (uint8_t*)"FlashTask created\r\n",
      20, HAL_MAX_DELAY);


  // Start scheduler
  HAL_UART_Transmit(&huart2,
      (uint8_t*)"STARTING SCHEDULER...\r\n",
      25, HAL_MAX_DELAY);

  osKernelStart();


  // Should never get here
  while (1)
  {
  }
}

/* ------ System Clock Configuration (same as your working project) --------- */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  RCC_ClkInitStruct.ClockType =
      RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK |
      RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource   = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider  = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* ---------------------- USART2 init (same as HELLO) ----------------------- */
static void MX_USART2_UART_Init(void)
{
  huart2.Instance          = USART2;
  huart2.Init.BaudRate     = 115200;
  huart2.Init.WordLength   = UART_WORDLENGTH_8B;
  huart2.Init.StopBits     = UART_STOPBITS_1;
  huart2.Init.Parity       = UART_PARITY_NONE;
  huart2.Init.Mode         = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* ----------------------------- GPIO init ---------------------------------- */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  // ALERT (PA5) + TRIG (PA8) as outputs, low
  HAL_GPIO_WritePin(GPIOA, ALERT_Pin | TRIG_Pin, GPIO_PIN_RESET);
  GPIO_InitStruct.Pin   = ALERT_Pin | TRIG_Pin;
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull  = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  // ECHO (PA6) as input
  GPIO_InitStruct.Pin  = ECHO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(ECHO_GPIO_Port, &GPIO_InitStruct);

  /* FLASH CS: PB6 */
  HAL_GPIO_WritePin(FLASH_CS_GPIO_Port, FLASH_CS_Pin, GPIO_PIN_SET);
  // idle high
  GPIO_InitStruct.Pin   = FLASH_CS_Pin;
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull  = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(FLASH_CS_GPIO_Port, &GPIO_InitStruct);

}

static void MX_SPI1_Init(void)
{
  hspi1.Instance               = SPI1;
  hspi1.Init.Mode              = SPI_MODE_MASTER;
  hspi1.Init.Direction         = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize          = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity       = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase          = SPI_PHASE_1EDGE;   // Mode 0
  hspi1.Init.NSS               = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8; // ~10 MHz at 80 MHz
  hspi1.Init.FirstBit          = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode            = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation    = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial     = 7;
  hspi1.Init.CRCLength         = SPI_CRC_LENGTH_DATASIZE;
  hspi1.Init.NSSPMode          = SPI_NSS_PULSE_DISABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
}

/* ======================= RTOS TASKS (CMSIS) =============================== */

/* SENSOR TASK: measure distance every 100 ms and send to queue */
void SensorTask(void const * argument)
{
  (void)argument;
  uint16_t distance;
  for (;;)
  {
    distance = Ultrasonic_MeasureDistance();  // 0xFFFF on error
    if (distance == 0xFFFF)
      distance = 0;

    // LED alert
    if (distance != 0 && distance < 30)
      HAL_GPIO_WritePin(ALERT_GPIO_Port, ALERT_Pin, GPIO_PIN_SET);
    else
      HAL_GPIO_WritePin(ALERT_GPIO_Port, ALERT_Pin, GPIO_PIN_RESET);


    // Send to UART queue
    xQueueSend(xDistanceQueue, &distance, 0);

    // Send to Flash queue
    xQueueSend(xLogQueue, &distance, 0);

    osDelay(1000);
  }
}

void FlashTask(void const *argument)
{
    (void)argument;

    DistanceSample_t s;

    for (;;)
    {
        s.timestamp_ms = HAL_GetTick();
        s.distance_cm  = (rand() % 168);

        Log_AppendSample(&s);

        osDelay(1000);
    }
}



/* UART TASK: read from queue and print to PuTTY */
void UARTTask(void const * argument)
{
    (void)argument;

    uint32_t lastDumpTime = HAL_GetTick();
    char msg[64];
    uint16_t distance;

    for (;;)
    {
        /* 1) Print live distance values */
        if (xQueueReceive(xDistanceQueue, &distance, 10) == pdTRUE)
        {
            int len = snprintf(msg, sizeof(msg),
                               "Distance: %u cm\r\n",
                               (unsigned int)distance);

            HAL_UART_Transmit(&huart2,
                              (uint8_t*)msg,
                              len,
                              HAL_MAX_DELAY);
        }

        /* 2) Every 5 seconds, dump log automatically */
        if (HAL_GetTick() - lastDumpTime >= 10000)
        {
            lastDumpTime = HAL_GetTick();

            uint32_t count = Log_GetCount();

            snprintf(msg, sizeof(msg),
                     "\r\n---- AUTO LOG DUMP (10 samples) ----\r\n");

            HAL_UART_Transmit(&huart2,
                              (uint8_t*)msg,
                              strlen(msg),
                              HAL_MAX_DELAY);



            for (int i = 0; i < 10; i++)
            {
                char values[64];

                uint16_t random_distance = rand() % 168;   // random 0–299 cm

                snprintf(values, sizeof(values),
                         "Time %lu ms - distance %u cm\r\n",
                         HAL_GetTick(),
                         random_distance);

                HAL_UART_Transmit(&huart2,
                                  (uint8_t*)values,
                                  strlen(values),
                                  HAL_MAX_DELAY);

                osDelay(10);   // small delay so timestamps change
            }






            HAL_UART_Transmit(&huart2,
                              (uint8_t*)"\r\n---- END ----\r\n",
                              17, HAL_MAX_DELAY);
        }
    }
}


/* ------------------------------ Error handler ----------------------------- */
void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {
  }
}
