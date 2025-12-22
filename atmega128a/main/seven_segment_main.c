#include "src/ap/ap.h" // <avr.io.h>, <util/delay.h>
#include "src/driver/led.h" // led와 연관된 헤더와 소스파일의 정보를 가져옴
// int main()
// {
//     apInit();
//     apMain();
// }


int main()
{
    uint8_t FND_Number[] = 
    {
        0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x67
    };
    DDRF = 0xff;
    int count = 0; // int(2Byte)이기 때문에 65,536까지 셀 수 있음

    while(1)
    {
        PORTF = FND_Number[count];
        count = (count + 1) % 10;

        _delay_ms(500);
    }
}
