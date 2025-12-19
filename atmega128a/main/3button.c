#include "src/ap/ap.h"

int main()
{
    DDRG = 0x00; //G포트 입력(버튼 연결 포트)으로 설정
    DDRD = 0xff; //D포트 출력(LED 연결 포트)으로 설정

    uint8_t ledData = 0x01;
    uint8_t buttonData; //버튼 입력 변수 설정
    
    int Flag = 0; //atmega에서 int형은 2byte

    PORTD = 0x00; //LED는 꺼진 상태에서 시작

    while (1)
    {
        buttonData = PING; //PING의 값을 읽어서 변수에 저장 (0.1)

        if((buttonData & (1<<0)) == 0)
        {
            PORTD = ledData;
            ledData = (ledData >> 7) | (ledData << 1);
            _delay_ms(300);
        }
        if((buttonData & (1<<1)) == 0)
        {
            PORTD = ledData;
            ledData = (ledData >> 1) | (ledData << 7);
            _delay_ms(300);
        }
        if(Flag == 0)
        {
            if((buttonData & (1<<2)) == 0)
            {
                Flag = 1;
            }
            else
            {
                Flag = 0;
            }
        }
        if(Flag == 1)
        {
            for(uint8_t i =0; i < 3; i++)
            {
                PORTD = 0xff;
                _delay_ms(500);
                PORTD = 0x00;
                _delay_ms(500);
            }
            Flag = 0;
        }
    }
}
