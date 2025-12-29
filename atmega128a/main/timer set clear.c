#include "./src/ap/ap.h"        // <avr.io.h> , <util/delay.h>
#include "./driver/fnd.h"

// #include "./src/driver/led.h"   // led와 연관된 헤더와 소스파일의 정보를 가져옴
// #include "./src/driver/button.h"


int main()
{
    DDRB = 0x10; // DDRB |= (1<<4); 포트B의 4번핀만 출력 설정
    PORTB &= ~(1<<4); // Low -> 포트 B의 4번핀만 출력을 Low
    //PORTB |= (1<<5); // High -> 포트 B의 4번핀만 출력을 High
    // TCCR0 = 0x1c;
    //TCCR0 |= (1<<COM00) | (1<<COM01) | (1<<WGM01) | (1<<CS02); // Low -> High
    //TCCR0 |= (1<<COM01) | (1<<WGM01) | (1<<CS02); // High -> Low

    OCR0 = 124; // 구한 값


    while(1)
    {
        TCCR0 = 0x2c;
        _delay_ms(500);
        while((TIFR&0x02)==0); // 컴페어 매치가 걸렸는지 여부, 0인지
        if((TIFR&0x02))
        {
            TCCR0 = 0x3c;
            TIFR = 0x02;
        }

        _delay_ms(500);
        
    }
}
