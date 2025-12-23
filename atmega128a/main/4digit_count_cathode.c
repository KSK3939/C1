#include "./src/ap/ap.h"        // <avr.io.h> , <util/delay.h>

// #include "./src/driver/led.h"   // led와 연관된 헤더와 소스파일의 정보를 가져옴
// #include "./src/driver/button.h"


// int main()
// {
//     apInit();
//     apMain();
// }


#define FND_DATA_DDR        DDRA        // DATA 포트 설정
#define FND_SELECT_DDR      DDRB        // DDRB 포트 설정
#define FND_DATA_PORT       PORTA       // 데이터 레지스터 설정
#define FND_SELECT_PORT     PORTB       // 셀렉스 레지스터 설정

void fndDisplay(uint16_t data);


int main()
{
    FND_DATA_DDR = 0xff;
    FND_SELECT_DDR = 0xff;
    FND_SELECT_PORT = 0xff; // 초기값을  출력으로 설정

    uint16_t count = 0;
    uint32_t timeTick = 0;
    uint32_t prevTime = 0;

    while (1)
    {
        fndDisplay(count);
        if(timeTick - prevTime > 300)   // 100밀리초가 지날때 마다 count값을 증가
        {
            prevTime = timeTick;        // 현재의 시간을 prevTime에 저장
            count++;
        }
        _delay_ms(1);       // 1밀리의 지연시간을 줌
        timeTick++;         // 타임틱이라는 변수는 1밀리초마다 증가
    }
}

void fndDisplay(uint16_t data)
{
    static uint8_t position = 0;        // 디지트의 위치를 관리하기 위해서, 포지션의 값을 기억하기 위해서 정적변수로 선언

    uint8_t fndData[10] =
    {
        0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x27,0x7f,0x67
    };

    switch (position)       // 디지트를 선택하기 위해서
    {
    case 0:
        // 첫번째 자리를 출력하기 위해서는, 0번핀 LOW, 1번핀 , 2번핀, 3번핀 HIGH 설정
        FND_SELECT_PORT &= ~(1<<0); // digit 0  ON
        FND_SELECT_PORT |= (1<<1) | (1<<2) | (1<<3);    // digit 1, 2, 3 OFF
        // 입력된 데이터를 천의 자리를 구해서 해당 디지트에 값을 출력
        FND_DATA_PORT = fndData[data/1000];
        break;
    case 1:
        // 두번째 자리를 출력하기 위해서는, 1번핀 LOW, 0번핀 , 2번핀, 3번핀 HIGH 설정
        FND_SELECT_PORT &= ~(1<<1); // digit 1  ON
        FND_SELECT_PORT |= (1<<0) | (1<<2) | (1<<3);    // digit 0, 2, 3 OFF
        // 입력된 데이터를 백의 자리를 구해서 해당 디지트에 값을 출력
        FND_DATA_PORT = fndData[data/100%10];
        break;
    case 2:
        // 세번째 자리를 출력하기 위해서는, 2번핀 LOW, 0번핀 , 1번핀, 3번핀 HIGH 설정
        FND_SELECT_PORT &= ~(1<<2); // digit 2  ON
        FND_SELECT_PORT |= (1<<0) | (1<<1) | (1<<3);    // digit 0, 1, 3 OFF
        // 입력된 데이터를 십의 자리를 구해서 해당 디지트에 값을 출력
        FND_DATA_PORT = fndData[data/10%10];
        break;
    case 3:
        // 네번째 자리를 출력하기 위해서는, 3번핀 LOW, 0번핀 , 1번핀, 2번핀 HIGH 설정
        FND_SELECT_PORT &= ~(1<<3); // digit 3  ON
        FND_SELECT_PORT |= (1<<0) | (1<<1) | (1<<2);    // digit 0, 1, 2 OFF
        // 입력된 데이터를 일의 자리를 구해서 해당 디지트에 값을 출력
        FND_DATA_PORT = fndData[data%10];
        break;
    }
    position++;     // 다음 자리로 이동하기 위해서 포지션값을 증가
    position = position % 4;    // 4자리를 출력한후에 다시 첫번째로 돌아가야 해서 4로 나눈 나머지를 이용함
}
