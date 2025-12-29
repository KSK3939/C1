#include "./src/ap/ap.h"        // <avr.io.h> , <util/delay.h>
#include "./driver/fnd.h"

// #include "./src/driver/led.h"   // led와 연관된 헤더와 소스파일의 정보를 가져옴
// #include "./src/driver/button.h"


int main()
{
    DDRD = 0x01; // 1번 포트만 활성화
    PORTD = 0x00; // Low
    TCCR0 |= (1<<CS02) | (1<<CS00); // normal mode, toggle, PSC = 128
    TCNT0 = 256-250;

    while(1)
    {
        while((TIFR&0x01)==0); // 컴페어 매치가 걸렸는지 여부, 0인지
        PORTD = ~PORTD; // "토글" 실행 ("~"를 이용하여 반전을 줌)
        TCNT0 = 6;
        TIFR = 0x01; // TIFR의 TOV0를 clear
    }
}
