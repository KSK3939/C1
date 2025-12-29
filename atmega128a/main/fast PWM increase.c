#include "./src/ap/ap.h"        // <avr.io.h> , <util/delay.h>
#include "./driver/fnd.h"

// #include "./src/driver/led.h"   // led와 연관된 헤더와 소스파일의 정보를 가져옴
// #include "./src/driver/button.h"


int main()
{
    DDRB |= (1<<PB4);

    TCCR0 |= (1<<WGM00) | (1<<COM01) | (1<<WGM01) | (1<<CS02); // fast PWM, Non inverting mode, PSC = 64
    // 16M / (256*64) = 976.56Hz
    //OCR0 = 64; // 64까지 세고 Low로 전환
    while(1)
    {
        for(uint8_t i = 0; i <= 255; i++)
        {
            OCR0 = i; // OCR0가 0에서 255까지 증가. High의 범위가 달라짐.
            _delay_ms(10);
        }
    }
}
