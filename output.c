#include "C:/Keil/ARM/INC/ARM/tm4c123gh6pm.h"
#include "stdint.h"


// delay between every digit to make the 3 digits turn on at the same time
void delay(int x)
{
    int i = 0;
    int j = 0;
    for (i; i < x; i++){
    	for (j; j < x; j++)
        {}
    }
}

void print (int mod){

	switch (mod){
		case 0 :
			GPIO_PORTB_DATA_R = 0xDE;	//to print 0 on 7 segment 
			break;
		case 1 :
			GPIO_PORTB_DATA_R = 0x50;	//to print 1 on 7 segment 
			break;		
		case 2 :
			GPIO_PORTB_DATA_R = 0xE6;	//to print 2 on 7 segment
			  break;				
		case 3 :
			GPIO_PORTB_DATA_R = 0x76;	//to print 3 on 7 segment
			  break;						
		case 4 :
			GPIO_PORTB_DATA_R = 0x78;	// to print 4 on 7 segment
			break;			
		case 5 :
			GPIO_PORTB_DATA_R = 0x3E;	//to print 5 on 7 segment
			break;	
		case 6 :
			GPIO_PORTB_DATA_R = 0xBE;	// to print 6 on 7 segment
			break;
		case 7 :
			GPIO_PORTB_DATA_R = 0x52;	//to print 7 on 7 segment
			break;
		case 8 :
			GPIO_PORTB_DATA_R = 0xFE;	//to print 8 on 7 segment
			break;
		case 9 :
			GPIO_PORTB_DATA_R = 0x7E;	// to print 9 on 7 segment
			break;
	}
}

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
