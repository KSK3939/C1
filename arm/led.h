/*
 * led.h
 *
 *  Created on: Jan 22, 2026
 *      Author: user18
 */

#ifndef INC_LED_H_
#define INC_LED_H_
// 위의 define은 기본으로 들어감

// #include "main.h"
#include "stm32f4xx_hal.h"
// 헤더파일에는 main.h 혹은 stm32f4xx_hal.h(사용 stm기기에 따라 달라짐)가 필수적으로 들어감

typedef struct
{
  GPIO_TypeDef *port;
  uint16_t number;
  GPIO_PinState onState;
  GPIO_PinState offState;
}LED_CONTROL;

void ledOn(uint8_t num);
void ledOff(uint8_t num);
void ledToggle(uint8_t num);

void ledLeftShift(uint8_t num);
void ledLeftRight(uint8_t num);
void ledCentertoSide(uint8_t num);
void ledRightShift(uint8_t num);
void ledLeftShiftOne(uint8_t *i);
void ledRightShiftOne(uint8_t *i);
#endif /* INC_LED_H_ */

