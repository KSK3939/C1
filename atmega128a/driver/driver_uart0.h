#include "../src/common/def.h"

void UART_Init();
void UART0_Transmit(char data);
uint8_t UART0_Receive();
int UART0_PutChar(char data, FILE *stream);

extern FILE OUTPUT;
volatile extern char rxBuff[100];
volatile extern uint8_t rxFlag;
