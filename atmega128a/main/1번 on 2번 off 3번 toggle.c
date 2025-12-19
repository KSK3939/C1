//1번 on, 2번 off, 3번 toggle
#include "src/ap/ap.h"

#define LED_DDR DDRD
#define LED_PORT PORTD //출력 할 때는 PORT
#define BUTTON_DDR DDRG
#define BUTTON_PIN PING    //입력 할 때는 PIN
#define BUTTON_ON 0
#define BUTTON_OFF 1
#define BUTTON_TOGGLE 2

enum {PUSHED, RELEASED};    //열거형
enum
{
    NO_ACT,
    ACT_PUSH,
    ACT_RELEASE,
};

/* =========================
 * BUTTON 구조체
 * =========================
 * 버튼 1개를 추상화한 구조체
 * - 어떤 포트의
 * - 어떤 핀을
 * - 이전 상태가 무엇이었는지를 저장
 */
 
typedef struct
{
    volatile uint8_t *ddr; //DDR의 주소이므로 포인터
    volatile uint8_t *pin; //PORT처럼 PIN의 주소값을 가져오기 때문에 포인터
    uint8_t btnPin; //핀 번호
    uint8_t prevState; //핀의 상태
}BUTTON;

/* =========================
 * buttonInit()
 * =========================
 * 버튼 구조체 초기화 함수
 * - 구조체에 레지스터 주소 저장
 * - 해당 핀을 입력 모드로 설정
 */

void buttonInit(BUTTON *btn, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pinNum)
{
    /* 구조체에 하드웨어 정보 저장 */
    btn->ddr = ddr;
    btn->pin = pin;
    btn->btnPin = pinNum;
    btn->prevState = RELEASED; //초기화 상태를 의미, 아무것도 안 누른 상태
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



int main()
{
    LED_DDR = 0xff;
    /* 버튼 구조체 3개 선언
     * 각각 독립적인 메모리 공간을 가짐
     */
    BUTTON btnOn; 
    BUTTON btnOff;
    BUTTON btnTog;
    
    /* 각 버튼 구조체에
     *  - DDRG, PING의 주소
     *  - 사용할 핀 번호를 저장
     */
    buttonInit(&btnOn, &BUTTON_DDR, &BUTTON_PIN, BUTTON_ON);
    buttonInit(&btnOff, &BUTTON_DDR, &BUTTON_PIN, BUTTON_OFF);
    buttonInit(&btnTog, &BUTTON_DDR, &BUTTON_PIN, BUTTON_TOGGLE);
    
    //버튼을 뗄 때 행동 수행
    while(1)
    {
        if(buttonGetState(&btnOn) == ACT_RELEASE) 
        {
            LED_PORT = 0xff; //on
        }
        if(buttonGetState(&btnOff) == ACT_RELEASE)
        {
            LED_PORT = 0x00; //off
        }
        if(buttonGetState(&btnTog) == ACT_RELEASE)
        {
            LED_PORT ^= 0xff; //toggle
        }
    }
}
