#include "src/ap/ap.h" // <avr.io.h>, <util/delay.h>
#include "src/driver/led.h" // led와 연관된 헤더와 소스파일의 정보를 가져옴
#include "src/driver/button.h"
// int main()
// {
//     apInit();
//     apMain();
// }

BUTTON btnCount;
BUTTON btnStop;
BUTTON btnReset;


int main()
{
    uint8_t FND_Number[] = 
    {
        0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x67
    };
    DDRF = 0xff;
    int count = 0; // int(2Byte)이기 때문에 65,536까지 셀 수 있음
    int FLAG = 0;
    buttonInit(&btnCount, &BUTTON_DDR, &BUTTON_PIN, BUTTON_ON);
    buttonInit(&btnStop, &BUTTON_DDR, &BUTTON_PIN, BUTTON_OFF);
    buttonInit(&btnReset, &BUTTON_DDR, &BUTTON_PIN, BUTTON_TOGGLE);
    while(1)
    {
        PORTF = FND_Number[count];

        if(buttonGetState(&btnCount) == ACT_RELEASE)
        {
            while(1)
            {
                PORTF = FND_Number[count];
                count = (count+1) % 10;
                _delay_ms(300);
                if(FLAG == 0) // FLAG를 이용하여 정지 여부 판별
                {
                    if(buttonGetState(&btnStop) == ACT_RELEASE)
                    {
                        FLAG = 1; // 정지
                    }
                    else if(buttonGetState(&btnReset) == ACT_RELEASE)
                    {
                        count = 0; // 리셋 포함
                        FLAG = 1;
                    }
                    else
                    {
                        FLAG = 0;
                    }
                }

                if(FLAG == 1)
                {
                    FLAG = 0;
                    break; // 정지
                }
            }
 
        }
        if(buttonGetState(&btnReset) == ACT_RELEASE)
        {
            count = 0; // 그냥 리셋
        }
    }
}
