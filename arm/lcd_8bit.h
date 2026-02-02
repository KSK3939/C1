#ifndef INC_LCD_8BIT_H_
#define INC_LCD_8BIT_H_

#include "stm32f4xx_hal.h"

/**
 * LCD 제어핀 설정 : RS 핀
 * 0 : command
 * 1 : data
 */
#define LCD_RS_GPIO GPIOC
#define LCD_RS_PIN  GPIO_PIN_9

/**
 * E (Enable)
 * 데이터/명령을 LCD에 래치시키기 위한 Enable
 * High -> Low 엣지에서 데이터가 LCD에 전달됨
 */
#define LCD_E_GPIO GPIOB
#define LCD_E_PIN  GPIO_PIN_8

/**
 * D0 ~ D7 까지의 데이터핀
 */
#define LCD_D0_GPIO GPIOC
#define LCD_D0_PIN  GPIO_PIN_8

#define LCD_D1_GPIO GPIOC
#define LCD_D1_PIN  GPIO_PIN_6

#define LCD_D2_GPIO GPIOC
#define LCD_D2_PIN  GPIO_PIN_5

#define LCD_D3_GPIO GPIOA
#define LCD_D3_PIN  GPIO_PIN_12

#define LCD_D4_GPIO GPIOA
#define LCD_D4_PIN  GPIO_PIN_11

#define LCD_D5_GPIO GPIOB
#define LCD_D5_PIN  GPIO_PIN_12

#define LCD_D6_GPIO GPIOB
#define LCD_D6_PIN  GPIO_PIN_2

#define LCD_D7_GPIO GPIOB
#define LCD_D7_PIN  GPIO_PIN_1

/* 함수의 원형 선언 */
// 8비트 데이터를(D0~D7) LCD핀에 출력
void LCD_Data(uint8_t data);

// Enable핀에 펄스를 주는 함수
// 데이터/명령을 LCD 내부로 확정(latch)시키는 역할
void LCD_EnablePin(void);

// 명령어 전송
void LCD_WriteCommand(uint8_t commandData);

// 문자(데이터) 전송
void LCD_WriteData(uint8_t charData);

// 커서 이동 함수
void LCD_GotoXY(uint8_t row, uint8_t col);

// 문자열 출력 함수
void LCD_WriteString(char *string);

// 좌표 이동 후에 문자열 출력
void LCD_WriteStringXY(uint8_t row, uint8_t col, char *string);

// 초기화 함수
void LCD_Init(void);


#endif /* INC_LCD_8BIT_H_ */
