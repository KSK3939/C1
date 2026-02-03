#include "lcd_4bit.h"

// 상위 4비트 데이터를(D4~D7) LCD핀에 출력
void LCD_Data4bit(uint8_t data)
{
  HAL_GPIO_WritePin(LCD_D4_GPIO, LCD_D4_PIN, (data & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(LCD_D5_GPIO, LCD_D5_PIN, (data & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(LCD_D6_GPIO, LCD_D6_PIN, (data & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(LCD_D7_GPIO, LCD_D7_PIN, (data & 0x80) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

// Enable핀에 펄스를 주는 함수
// 데이터/명령을 LCD 내부로 확정(latch)시키는 역할
void LCD_EnablePin(void)
{
  HAL_GPIO_WritePin(LCD_E_GPIO, LCD_E_PIN, GPIO_PIN_RESET);
  HAL_Delay(1);
  HAL_GPIO_WritePin(LCD_E_GPIO, LCD_E_PIN, GPIO_PIN_SET);
  HAL_Delay(1);
  // LOW로 떨어질 때 데이터가 전달됨
  HAL_GPIO_WritePin(LCD_E_GPIO, LCD_E_PIN, GPIO_PIN_RESET);
  HAL_Delay(2);
}

// 1바이트를 상/하위 4비트로 나눠서 전송
void LCD_SendByte(uint8_t data)
{
  // 상위 4비트 전송
  LCD_Data4bit(data & 0xF0); // and 연산으로 상위 4비트만 보냄
  LCD_EnablePin();

  // 하위 4비트 전송
  LCD_Data4bit((data << 4) & 0xF0); // 4칸 밀어서 하위 4비트를 상위로 보내고 and 연산
  LCD_EnablePin();
}

// 명령어 전송
void LCD_WriteCommand(uint8_t commandData)
{
  // 명령어 모드일 때는 RS -> 0
  HAL_GPIO_WritePin(LCD_RS_GPIO, LCD_RS_PIN, GPIO_PIN_RESET);

  LCD_SendByte(commandData);
}

// 문자(데이터) 전송
void LCD_WriteData(uint8_t charData)
{
  // 데이터 모드일 때는 RS -> 1
  HAL_GPIO_WritePin(LCD_RS_GPIO, LCD_RS_PIN, GPIO_PIN_SET);

  LCD_SendByte(charData);
}

// 커서 이동 함수
void LCD_GotoXY(uint8_t row, uint8_t col)
{
  // row 범위 제한 (0,1)
  if(row > 1) row = 1;
  // col 제한 (0 ~ 15)
  if(col > 15) col = 15;

  // LCD DRAM 주소
  // 1행 : 0x00 ~ 0x0F
  // 2행 : 0x40 ~ 0x4F
  uint8_t addr = (row == 0) ? col : (0x40 + col);

  // 커서 이동 명령. 0x80은 이동 명령, addr은 이동할 주소.
  // D7은 무조건 1이 되고 뒤 주소에 따라 나머지 D가 결정됨
  LCD_WriteCommand(0x80 | addr);
}

// 문자열 출력 함수
void LCD_WriteString(char *string)
{
  while(*string)
  {
    // 주소를 하나 씩 옮겨가며 문자열을 읽음
    LCD_WriteData(*string++);
  }
}

// 좌표 이동 후에 문자열 출력
void LCD_WriteStringXY(uint8_t row, uint8_t col, char *string)
{
  LCD_GotoXY(row, col);
  LCD_WriteString(string);
}

// 초기화 함수
void LCD_Init(void)
{
  HAL_Delay(50); // 안정화를 위해서 충분히 시간을 줌
  LCD_Data4bit(0x30);
  LCD_EnablePin();
  HAL_Delay(5);

  LCD_Data4bit(0x30);
  LCD_EnablePin();
  HAL_Delay(1);

  LCD_Data4bit(0x30);
  LCD_EnablePin();

  LCD_Data4bit(0x20);
  LCD_EnablePin();

  LCD_WriteCommand(0x28); // Function set. 4bit, 화면 2행, 5x8 font
  LCD_WriteCommand(0x0C); // 화면 on, 커서 off, 점멸 off
  LCD_WriteCommand(0x01); // LCD clear
  HAL_Delay(5);

  LCD_WriteCommand(0x06); // Entry mode set. 커서는 오른쪽 이동, 화면 이동 없음
}
