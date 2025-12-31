#include "src/ap/ap.h"
#include "./driver/uart0.h"
#include "src/ap/ap2.h"
#include "./driver/led.h"


char rxData;
int i = 0;

int main()
{
    UART_Init();
    LED led;
    led.port = &PORTD;
    led.pinNumber = 0;
    ledInit(&led);
    //DDRD = 0xff;
    while (1)
    {
        rxData = UART0_Receive();
        switch(rxData)
        {
        case 'a':
            // while(i<8)
            // {
            //     PORTD = (1<<i);
            //     _delay_ms(500);
            //     i++;
            // }
            ledOn(&led);
            i = 0;
            break;
        case 'b':
            //PORTD = 0x00;
            ledOff(&led);
            break;
        default:
            break;    
        }
    }
}



