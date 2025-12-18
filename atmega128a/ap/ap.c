#include "ap.h"
#include "../driver/led.h"

void apInit()
{

}


void apMain()
{
    LED led;
    led.port = &PORTD; // 포트D로 호출
    led.pinNumber = 0;

    for (uint8_t i = 0; i<8; i++){
        ledInint(&led); // 핀 전부 활성화 시키기
        led.pinNumber++;
    }


    while (1)
    {
            ledOn(&led);
            _delay_ms(500);
            ledOff(&led);
            _delay_ms(500);

            led.pinNumber++; // 핀 넘버 증가시키면서 켜기

            if(led.pinNumber > 7){
                led.pinNumber =0;
            }
    }
}