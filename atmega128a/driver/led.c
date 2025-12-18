#include "led.h"


// LED 초기화 함수 구현
void ledInint(LED *led){
    //(led->port - 1) = *(led->port -1) | (1 << led->pinNumber);
                        //  ㄴDDR           ㄴ 1만큼 led 민다
    // DDR레지스터는 PORT레지스터보다 주소가 1낮게 위치하므로
    // (led->port - 1)를 이용해서 PORT에서 DDR로 접근
    // (1 << led->pinNumber)와 OR연산을 통해서 지정된 포트를 출력

    *(led->port - 1) |= (1 << led->pinNumber);
}


// LED On 함수
void ledOn(LED *led){
    *(led->port) |= (1 << led-> pinNumber);

}

// LED Off 함수
void ledOff(LED *led){
    *(led->port) &= ~(1 << led->pinNumber);
}