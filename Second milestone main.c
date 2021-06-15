#include "C:/Keil/ARM/INC/ARM/tm4c123gh6pm.h"
#include "stdint.h"
#include "string.h"
#include <stdlib.h>
#include <math.h>
#define pi 3.14159265358979323846
double distance(double lat1, double lat2, double lon1, double lon2);
double toRadians(double deg);


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
	GPIO_PORTA_DIR_R=0xFE; //PA0 INPUT , PA1-7 OUTPUT
	GPIO_PORTA_AFSEL_R=0x03; //ENABLE alternate functions for PA0, PA1
	GPIO_PORTA_DEN_R = 0xFF; //enable digital I/O on PA 0-7
//PORT B
	GPIO_PORTB_CR_R=0xFF; //allow changes to PB 0-7
	GPIO_PORTB_AMSEL_R=0x00; //disable analog for port B
	GPIO_PORTB_PCTL_R=0x00000000; // PCTL on PB 0-7
	GPIO_PORTB_DIR_R=0xFF; //PB0-7 OUTPUT
	GPIO_PORTB_AFSEL_R=0x00; //disable alternate functions on pB 0-7
	GPIO_PORTB_DEN_R = 0xFF; //enable digital I/O on PB 0-7
}
	



double distance(double lat1, double lat2, double lon1, double lon2) {
  double dlat, dlon, dist, a, c, r;

// convert the latitudes and the longitudes from decimal degree to radian degree.
        lat1 = toRadians(lat1);
        lat2 = toRadians(lat2);
        lon1 = toRadians(lon1);
        lon2 = toRadians(lon2);

// if the starting and the ending points are the same return zero
  if ((lat1 == lat2) && (lon1 == lon2)) {
    return 0;
  }
else {
    // Haversine formula
    dlat = lat2 - lat1;
    dlon = lon2 - lon1;
    a = sin(dlat/2) * sin(dlat/2) + cos(lat1) * cos(lat2) * sin(dlon/2) * sin(dlon/2);
    c = 2 * asin(sqrt(a));
    r = 6371;                       // r is the Radius of earth in kilometers.
    dist = c * r * 1000;

    return (dist);
  }
}
// the function converts the decimal degree to radian degree.
 double toRadians(double deg) {

  return (deg * pi / 180);
 }
 
void UART_Init(){
  SYSCTL_RCGCUART_R |=0x02;
  SYSCTL_RCGCGPIO_R |=0x04;
	UART1_CTL_R &= ~0x01;
	UART1_IBRD_R = 104;
	UART1_FBRD_R = 11;
	UART1_LCRH_R = 0x07;
	UART1_CTL_R |= (UART_CTL_UARTEN | UART_CTL_RXE | UART_CTL_TXE);
	GPIO_PORTC_AFSEL_R |= 0x30;
	GPIO_PORTC_DEN_R |= 0x30;
	GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R&0xFF00FFFF) | (GPIO_PCTL_PC4_U1RX | GPIO_PCTL_PC5_U1TX);
	GPIO_PORTC_AMSEL_R &= ~0x30;
}
 
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
			GPIO_PORTB_DATA_R = 0xDE;	//to display 0 on 7 segment 
			break;
		case 1 :
			GPIO_PORTB_DATA_R = 0x50;	//to display 1 on 7 segment 
			break;		
		case 2 :
			GPIO_PORTB_DATA_R = 0xE6;	//to display 2 on 7 segment
			  break;				
		case 3 :
			GPIO_PORTB_DATA_R = 0x76;	//to display 3 on 7 segment
			  break;						
		case 4 :
			GPIO_PORTB_DATA_R = 0x78;	// to display 4 on 7 segment
			break;			
		case 5 :
			GPIO_PORTB_DATA_R = 0x3E;	//to display 5 on 7 segment
			break;	
		case 6 :
			GPIO_PORTB_DATA_R = 0xBE;	// to display 6 on 7 segment
			break;
		case 7 :
			GPIO_PORTB_DATA_R = 0x52;	//to display 7 on 7 segment
			break;
		case 8 :
			GPIO_PORTB_DATA_R = 0xFE;	//to display 8 on 7 segment
			break;
		case 9 :
			GPIO_PORTB_DATA_R = 0x7E;	// to display 9 on 7 segment
			break;
	}
}

// print distance covered on port B
void LCD_OUT(int distance){
	
	int mod1, mod2, mod3;
	
	mod1 = distance %10;                 // to extract the least significant number of the distance
	distance /=10;
	
	mod2 = distance %10;                 // to extract the 2nd number of the distance
	distance /=10;
	
	mod3 = distance %10;                //  to extract the most significant number of the distance
	distance /=10;
	
	 
		
	GPIO_PORTA_DATA_R = ~0x08;          //  send the 1st number to the function to enable the 1st 7 segment
	print(mod1);
	delay(1000);
		
	GPIO_PORTA_DATA_R = ~ 0x04;         //  send the 2nd number to the function to enable the 2nd 7 segment
	print(mod2);
	delay(1000);
		
	GPIO_PORTA_DATA_R = ~ 0x80;         //  send the 3rd number to the function to enable the 3rd 7 segment
	print(mod3);
	delay(1000);	
}







void ReadGpsModule(){
char x ,GPS_values[100],latitudeResult[10],longitudeResult[10],*token,protocol_values[12][20];
char x0,x1,x2,x3,x4,x5,x6;
const char comma[2] = ",";
double latitude_result=0.0;
double longitude_result=0.0;
double lat1=30.09925427155651;
double lon1=30.09925427155651;	
double latitude=0.0,longitude=0.0,seconds=0.0,minutes=0.0;
int index=0,degrees;
while((UART1_FR_R&0x0010) !=0){}
x = UART1_DR_R&0xFF;
if(x =='$'){
while((UART1_FR_R&0x0010) !=0){;}// the fifo is not empty
x0 = UART1_DR_R &0xFF;
if(x0 == 'G'){
while((UART1_FR_R&0x0010) !=0){;}
x1 = UART1_DR_R&0xFF;
if(x1 == 'P'){
while((UART1_FR_R&0x0010) !=0){;}
x2 = UART1_DR_R&0xFF;
if(x2 == 'R'){
while((UART1_FR_R&0x0010) !=0){;}
x3 = UART1_DR_R&0xFF;
if(x3 == 'M'){
while((UART1_FR_R&0x0010) !=0){;}
x4 = UART1_DR_R&0xFF;
if(x4 == 'C'){
//   printf("%c%c%c%c%c%c \n",x,x0,x1,x2,x3,x4);
while((UART1_FR_R&0x0010) !=0){;}
x5 = UART1_DR_R&0xFF;
if(x5 == ','){
while((UART1_FR_R&0x0010) !=0){;}
x6 = UART1_DR_R&0xFF;
while(x6 !='*'){
GPS_values[index] = x6;//20
while((UART1_FR_R&0x0010) !=0){;}
x6 = UART1_DR_R&0xFF;
index++;
}
// to convert the char to string holds the values of lat. and long.
index = 0;
token = strtok(GPS_values,comma);
while( token != NULL ) {
strcpy(protocol_values[index], token);
token = strtok(NULL,comma);
index++;}
// check if A -> activ so, valid data
// V -> invalid data

//printf("\n");
if(strcmp(protocol_values[1],"A")==0){
latitude=atof(protocol_values[2]);
longitude=atof(protocol_values[4]);
//latitude calculation
degrees=latitude/100;
minutes=latitude-(double)(degrees*100);
seconds=minutes/60.00;
latitude_result=degrees+seconds;
sprintf(latitudeResult,"%f", latitude_result);
//longitude calculation
degrees=longitude/100;
minutes=longitude-(double)(degrees*100);
seconds=minutes/60.00;
longitude_result=degrees+seconds;

LCD_OUT((int) distance( lat1,  latitude_result,  lon1,  longitude_result));
}
}
}}}}}}}


int main (){
initialization();
UART_Init();
	
while (1){
ReadGpsModule();
led_out((int) distance( lat1,  latitude_result,  lon1,  longitude_result))
return 0;
}
	
}
