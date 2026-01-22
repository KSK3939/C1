/*
 * led.c
 *
 *  Created on: Jan 22, 2026
 *      Author: user18
 */


#include "led.h"

LED_CONTROL led[8]=
{
    {GPIOC, GPIO_PIN_8, GPIO_PIN_SET, GPIO_PIN_RESET},
    {GPIOC, GPIO_PIN_6, GPIO_PIN_SET, GPIO_PIN_RESET},
    {GPIOC, GPIO_PIN_5, GPIO_PIN_SET, GPIO_PIN_RESET},
    {GPIOA, GPIO_PIN_12, GPIO_PIN_SET, GPIO_PIN_RESET},
    {GPIOA, GPIO_PIN_11, GPIO_PIN_SET, GPIO_PIN_RESET},
    {GPIOB, GPIO_PIN_12, GPIO_PIN_SET, GPIO_PIN_RESET},
    {GPIOB, GPIO_PIN_2, GPIO_PIN_SET, GPIO_PIN_RESET},
    {GPIOB, GPIO_PIN_1, GPIO_PIN_SET, GPIO_PIN_RESET},
};
// 각 핀마다 선언

void ledOn(uint8_t num)
{
  for(uint8_t i = 0; i < num; i++) // led를 num개 만큼 켜기
  {
    HAL_GPIO_WritePin(led[i].port, led[i].number, led[i].onState);
  }
}

void ledOff(uint8_t num)
{
  for(uint8_t i = 0; i < num; i++) // led를 num개 만큼 끄기
  {
    HAL_GPIO_WritePin(led[i].port, led[i].number, led[i].offState);
  }
}

void ledToggle(uint8_t num) // 지정된 핀만 토글
{
  HAL_GPIO_TogglePin(led[num].port, led[num].number);
}

void ledLeftShift(uint8_t num) // 왼쪽으로 하나씩 켜지고 왼쪽으로 하나씩 꺼짐
{
  for(uint8_t i = 0; i <= num; i++)
  {
    ledOn(i);
    HAL_Delay(100);
  }
  HAL_Delay(500);
  for(uint8_t i = 0; i <= num; i++)
  {
    ledOff(i);
    HAL_Delay(100);
  }
  HAL_Delay(500);
}

void ledLeftRight(uint8_t num) // 왼쪽으로 하나씩 켜지고 오른쪽으로 하나씩 꺼짐
{
  for(uint8_t i = 0; i <= num; i++)
  {
    ledOn(i);
    HAL_Delay(100);
  }
  HAL_Delay(500);
  for(uint8_t j = num; j > 0; j--) // 여기서 변수를 빼던 중 음수가 되지 않도록 주의
  {
    HAL_GPIO_WritePin(led[j-1].port, led[j-1].number, led[j-1].offState); // 오류를 막기 위하여 j-1로 선언
    HAL_Delay(100);
  }
  HAL_Delay(500);
}

void ledCentertoSide(uint8_t num) // 중앙에서 하나씩 켜지고 사이드에서 하나씩 꺼짐
{
  for(uint8_t i = num; i > 0; i--) // i가 음수가 되지 않도록 주의
  {
    HAL_GPIO_WritePin(led[7-(i-1)].port, led[7-(i-1)].number, led[7-(i-1)].onState); // 이를 위해 i-1로 선언
    HAL_GPIO_WritePin(led[i-1].port, led[i-1].number, led[i-1].onState);
    HAL_Delay(100);
  }
  HAL_Delay(500);
  for(uint8_t i = 0; i <= num; i++) // 하니씩 끔
  {
    HAL_GPIO_WritePin(led[7-i].port, led[7-i].number, led[7-i].offState);
    HAL_GPIO_WritePin(led[i].port, led[i].number, led[i].offState);
    HAL_Delay(100);
  }
  HAL_Delay(500);
}
// (3,4), (2,5), (1,6), (0,7) 순서로 켜지고 그 역순으로 꺼지기에 7과 i를 연산하는 것으로 구현
