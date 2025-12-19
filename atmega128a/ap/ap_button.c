#include "ap.h"
#include "../driver/led.h"
#include "../driver/button.h"

BUTTON btnOn;
BUTTON btnOff;
BUTTON btnTog;

void apInit()
{
    buttonInit(&btnOn, &BUTTON_DDR, &BUTTON_PIN, BUTTON_ON);
    buttonInit(&btnOff, &BUTTON_DDR, &BUTTON_PIN, BUTTON_OFF);
    buttonInit(&btnTog, &BUTTON_DDR, &BUTTON_PIN, BUTTON_TOGGLE);
}


void apMain()
{
    LED_DDR = 0xff;
    while(1)
    {
        if(buttonGetState(&btnOn) == ACT_RELEASE)
        {
            LED_PORT = 0xff;
        }
        if(buttonGetState(&btnOff) == ACT_RELEASE)
        {
            LED_PORT = 0x00;
        }
        if(buttonGetState(&btnTog) == ACT_RELEASE)
        {
            LED_PORT ^= 0xff;
        }
    }
}
