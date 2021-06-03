// print distance covered on port B
void LCD_OUT(unsigned char distance){
	GPIO_PORTB_DATA_R = distance;  // write output distance on port B
}