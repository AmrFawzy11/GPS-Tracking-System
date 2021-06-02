// function turns on the LED when the distance exceeds 100 meters.
void led_out(unsigned char data)
{
if( data>=0x64) // checking if distance covered exceeded 100 meter
{GPIO_PORTF_DATA_R |= 0x02} // turn on red led
	
	}
