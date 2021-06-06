void initialization (void)
{
SYSCTL_RCGCGPIO_R|=0x23; //initializing clock for ports A,B,F
while((SYSCTL_PRGPIO_R&0x23)==0){}; //delay 
//PORT F
  GPIO_PORTF_LOCK_R=0x4C4F434B; //UNLOCK GPIO FOR PORT F
  GPIO_PORTF_CR_R=0x1F; //allow changes to PF 0-4
  GPIO_PORTF_AMSEL_R=0x00; //disable analog for port F
  GPIO_PORTF_PCTL_R=0x00000000; //PCTL GPIO ON PF 0-4
  GPIO_PORTF_DIR_R=0x0E;   //PF0,PF4 INPUT , PF1-3 OUTPUT
  GPIO_PORTF_AFSEL_R=0x00; //disable alternate functions on pf 0-4
  GPIO_PORTF_DEN_R =0x1F;  //enable digital I/O on PF 0-4
  GPIO_PORTF_PUR_R=0x11;   //enable pull up resistor on pf0 and pf4 for switch	
//port A
	GPIO_PORTA_CR_R=0xFF; //allow changes to PA 0-7
	GPIO_PORTA_AMSEL_R=0x00; //disable analog for port A
	GPIO_PORTA_PCTL_R=0x00000011; //PA0 IS UART reseiver , PA1 IS UART transmitter
	GPIO_PORTA_DIR_R=0xFF; //PA 0-7 OUTPUT
	GPIO_PORTA_AFSEL_R=0x00; //Disable the alternating function (use all pins as GPIO)
	GPIO_PORTA_DEN_R = 0xFF; //enable digital I/O on PA 0-7
//PORT B
	GPIO_PORTB_CR_R=0xFF; //allow changes to PB 0-7
	GPIO_PORTB_AMSEL_R=0x00; //disable analog for port B
	GPIO_PORTB_PCTL_R=0x00000000; // PCTL on PB 0-7
	GPIO_PORTB_DIR_R=0xFF; //PB0-7 OUTPUT
	GPIO_PORTB_AFSEL_R=0x00; //disable alternate functions on pB 0-7
	GPIO_PORTB_DEN_R = 0xFF; //enable digital I/O on PB 0-7
}
	
	
	
	
	
	
	
	
	
	


	
	
	
