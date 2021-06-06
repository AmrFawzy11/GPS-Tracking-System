#include "C:/Keil/ARM/INC/ARM/tm4c123gh6pm.h"
#include "stdint.h"
void print(int mod);
void delay(int x);

// print distance covered on port B
void LCD_OUT(unsigned char distance){
	
	 int mod1, mod2, mod3;
	
    mod1 = distance %10;
	  distance /=10;
	
	  mod2 = distance %10;
	  distance /=10;
	
	  mod3 = distance %10;
	  distance /=10;
	
	 
		
		GPIO_PORTA_DATA_R = ~0x08;
		print(mod1);
	  delay(1000);
		
		GPIO_PORTA_DATA_R = ~ 0x04;
		print(mod2);
	  delay(1000);
		GPIO_PORTA_DATA_R = ~ 0x80;

		print(mod3);
	  delay(1000);
	
	
	
	
}
