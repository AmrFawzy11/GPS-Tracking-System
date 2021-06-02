void led_out(unsigned char data)
{
if( data>=0x64)
{GPIO_PORTF_DATA_R |= 0x02}
	
	}