#include "src/ap/ap.h"

int main()
{
    // apInit();
    // apMain()

    DDRG = 0x00; //G포트 입력으로 설정
    DDRD = 0xff; //D포트 출력으로 설정



    while (1)
    {
        if(PING & (1<<0)) // PORTG의 0번핀이 High라면

        {
            PORTD = 0x00; //LED OFF
        }
        else // PORTG의 0번핀이 Low라면
        {
            PORTD = 0xff; //LED ON
        }
    }
}