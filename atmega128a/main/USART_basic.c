#include "src/ap/ap.h"

void UART_Init();
void UART0_Transmit(char data);
uint8_t UART0_Receive();


int main()
{
    // apInit
    // apMain();

    UART_Init();    

    while (1)
    {
        UART0_Transmit(UART0_Receive());
    }    
}

void UART_Init()
{
    UBRR0H = 0x00;
    UBRR0L = 207;       // 9600bps 설정
    // 비동기, 8비트데이터, 패리티비트 없음, 스톱비트 1비트
    UCSR0A |= (1<<U2X0);
    UCSR0B |= (1<<RXEN0) | (1<<TXEN0);      // 수신가능, 송신가능
    UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00);    // 8비트 사용
}

void UART0_Transmit(char data)
{
    while(!(UCSR0A & (1<<UDRE0)));      // 송신 가능할때까지 대기, UDR이 비어 있는지?
    UDR0 = data;
}

uint8_t UART0_Receive()
{
    while(!(UCSR0A & (1<<RXC0)));       // 데이터 수신 대기
    return UDR0;
}
