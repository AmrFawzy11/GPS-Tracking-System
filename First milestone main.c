#include "stdint.h"
#include "C:/Keil/ARM/INC/ARM/tm4c123gh6pm.h"

unsigned char SW_Input(void){
return GPIO_PORTF_DATA_R & 0x11;
}

void LED(unsigned char data){
GPIO_PORTF_DATA_R = data;
}


int main(){

unsigned char LED_OUT;
unsigned char OUT_DIST;
unsigned char button;

initialization();

while (1){

	button = SW_Input();

    switch(button){
		    
     case 0x11 :                    // if no switch is pressed
                LED_OUT  = 0x02;    // turn on red, blue, green leds together so it will appear white
                OUT_DIST = 123;    // put distance equal 123 meter
                break;    

     case 0x01 :                    // if switch 1 is pressed
                LED_OUT  = 0x02;    // turn on red led
                OUT_DIST = 0x01;    // put distance equal 1 meter
                break;
     case 0x10 :                    // if switch 2 is pressed
                LED_OUT  = 0x04;    // turn on blue led
                OUT_DIST = 0x0A;    // put distance equal 10 meter
                break;
     case 0x00 :                    // if switch 1 and 2 are pressed
                LED_OUT  = 0x08;    // turn on green led
                OUT_DIST = 0x64;    // put distance equal 100 meter
                break;

    }

    LCD_OUT(OUT_DIST);
    LED(LED_OUT);

}

return 0;
}
