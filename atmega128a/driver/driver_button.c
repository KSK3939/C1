#include "button.h"

void buttonInit(BUTTON *btn, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pinNum)
{
    btn->ddr = ddr;
    btn->pin = pin;
    btn->btnPin = pinNum;
    btn->prevState = RELEASED; //초기화 상태를 의미, 아무것도 안누른 상태
    *btn->ddr &= ~(1<<btn->btnPin); //버튼핀을 입력으로 설정
}

uint8_t buttonGetState(BUTTON *btn)
{
    uint8_t currState = *btn->pin & (1<<btn->btnPin); //현재 버튼의 상태를 읽어옴

    if((currState == PUSHED) && (btn->prevState == RELEASED)) //안누른 상태에서 누르면
    {
        _delay_ms(50); //debounce code
        btn->prevState = PUSHED; //버튼을 누른 상태로 변경
        return ACT_PUSH; //버튼이 눌렸음을 반환
    }
    else if((currState != PUSHED) && (btn->prevState == PUSHED)) //버튼을 누른 상태에서 떼면
    {
        _delay_ms(50); //debounce code
        btn->prevState = RELEASED; //버튼을 뗀 상태로 변경
        return ACT_RELEASE; //버튼이 떼졌음을 반환
    }
    return NO_ACT; //아무것도 안함
}
