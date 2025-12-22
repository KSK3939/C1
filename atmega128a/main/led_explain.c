#include "src/ap/ap.h"

// int main()
// {
//     apInit();
//     apMain();
// }

#define LED_DDR DDRD // LED의 입축력을 설정하는 DDR을 매크로 상수로 정의하여 사용
#define LED_PORT PORTD // DDR의 방향 설정 이후 PORT의 제어를 위해 매크로 상수로 정의하여 사용

// LED 포트 (PORTD) 에 데이터를 출력하기 위해 함수를 정의
void GPIO_Output(uint8_t data) // data라는 인자값을 받아 GPIO_Output 함수에서 지역변수로 사용
{
    LED_PORT = data; // GPIO_Output 함수 호출 시 인자값을 넘겨준 data를 LED_PORT에 대입
}

// LED포트를 출력 모드로 사용하기 위해 초기 설정을 하는 함수
void ledInit() // 포트 설정만 하면 되기 때문에 인자값 없이 함수를 정의
{
    LED_DDR = 0xff; //출력으로 사용하기 위해 DDRDdp 2진수로 0b11111111를 넣어줌
}

// LED 데이터를 이용하여 좌측으로 이동시키는 함수 정의
void ledLeftShift(uint8_t *data) // data라는 포인터 변수를 함수의 인자로 사용
{
    // 역참조(*)를 사용하여 포인터 data가 가리키는 곳의 값을 사용함
    *data = (*data >> 7) | (*data << 1); // 인자로 받은 곳의 값을 이용하여 좌측으로 1비트 이동
    GPIO_Output(*data); // GPIO_Output 함수를 호출하면서 역참조연산자(*)를 이용하여 포인터가 가리키는 곳의 값을 넘겨줌
}

// LED 데이터를 이용하여 우측으로 이동시키는 함수 정의
void ledRightShift(uint8_t *data)
{
    *data = (*data << 7) | (*data >> 1);
    GPIO_Output(*data);
}



int main()
{
    ledInit(); // LED에 연결된 포트를 출력 설정하기 위한 초기값 설정 함수를 호출

    uint8_t ledData = 0x01; // LED출력을 위해 데이터 값을 00000001로 설정
    while(1) // 무한 반복
    {
        for(uint8_t i = 0; i < 7; i++)
        {
            ledLeftShift(&ledData); // ledLeftShift 함수를 호출하면서 인자값 ledData의 주소값을 주소연산자(&)를 이용하여 넘겨줌
            _delay_ms(300); // 200밀리초 지연
        }
        for(uint8_t i = 0; i < 7; i++)
        {
            ledRightShift(&ledData);
            _delay_ms(300);
        }
    }
}
