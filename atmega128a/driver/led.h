// include 와 함수의 원형을 분리
#include "common/def.h"

typedef struct
{
    volatile uint8_t    *port;
    uint8_t             pinNumber;
}LED;


void ledInint(LED *led);
void ledOn(LED *led);
void ledOff(LED *led);