/*
 * button.h
 *
 *  Created on: Jan 23, 2026
 *      Author: user18
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

// #include "main.h"
#include "stm32f4xx_hal.h"
#include <stdbool.h>

typedef struct
{
  GPIO_TypeDef  *port;
  uint16_t      number;
  GPIO_PinState onState;
}BUTTON_CONTROL;

bool buttonGetPressed(uint8_t num);

#endif /* INC_BUTTON_H_ */
