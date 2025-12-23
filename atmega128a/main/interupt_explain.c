#include "./src/ap/ap.h"        // <avr.io.h> , <util/delay.h>
#include "./driver/fnd.h"

// #include "./src/driver/led.h"   // led와 연관된 헤더와 소스파일의 정보를 가져옴
// #include "./src/driver/button.h"

ISR(INT7_vect)
{
    PORTD ^= 0xff;
}

int main()
{
    sei(); // 전역 인터럽트 인에이블
    EICRB = 0xc0; // Rising edge에서 인터럽트 발생
    // EICRB = 0x80; // Falling edge
    // EICRB = 0x40; // Any Logical Change
    // EICRB = 0x00; // LOW
    EIMSK = 0x80; // INT7 인에이블
    DDRE &= ~(1<<7);

    DDRD = 0xff;

    while(1)
    {

    }
}
