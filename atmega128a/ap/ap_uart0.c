#include "ap2.h"
#include "../driver/uart0.h"

void apUART_Init()
{
    UART_Init(); 
}

void ap2Main(){
    sei();
    UART_Init();
    

    stdout = &OUTPUT;   // 출력 스트림을 지정
    while (1)
    {
        if(rxFlag == 1) // 문자열 수신이 완료되면
        { 
            rxFlag = 0;
            // printf(rxBuff);
            printf("%s\n", rxBuff);
        }
    }
    
}


