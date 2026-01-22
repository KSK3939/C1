/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

typedef enum // state 구조체
{
  LED_OFF, // value = 0
  LED_ON   // value = 1
}LED_STATE;

typedef struct // 필요한 요소들 구조체 선언
{
  GPIO_TypeDef *port;
  uint16_t      number;
  uint32_t      interval;  // Change Time (ms)
  LED_STATE     state;
  uint32_t      lastTick;  // LED change (ON/OFF)
}LED_CONTROL;

// LED_CONTROL led1 = {GPIOC, GPIO_PIN_8, 200, 0}; // 실사용 예
void updateLed(LED_CONTROL *led)
{
  uint32_t currentTick = HAL_GetTick(); // 현재 시스템의 틱(카운트)를 가져옴

  if(currentTick - led->lastTick >= led->interval) // 인터벌만큼의 시간이 흘렀는가
  {
    led->lastTick = currentTick; // lastTick 저장

    if(led->state == LED_OFF) // 꺼져 있다면
    {
      HAL_GPIO_WritePin(led->port, led->number, 1); // LED를 켬
      led->state = LED_ON; // 바뀐 state 저장
    }
    else // 켜져 있다면
    {
      HAL_GPIO_WritePin(led->port, led->number, 0); // LED를 끔
      led->state = LED_OFF; // 바뀐 state 저장
    }
  }
}

/* USER CODE END PTD */

int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  LED_CONTROL led1 = {GPIOC, GPIO_PIN_8, 200, 0}; // 포트(PC8), 인터벌(200ms), 초기상태(OFF) 선언

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

    updateLed(&led1); // 함수 하나로 LED toggle 구현

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}
