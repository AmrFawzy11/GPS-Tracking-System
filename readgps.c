#include "C:/Keil/ARM/INC/ARM/tm4c123gh6pm.h"
#include "stdint.h"
#include "string.h"
#include <stdlib.h>

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
//longitude calculation
degrees=longitude/100;
minutes=longitude-(double)(degrees*100);
seconds=minutes/60.00;
longitude_result=degrees+seconds;
}
}
}}}}}}}