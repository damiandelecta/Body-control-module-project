#include<lpc21xx.h>
void delay(unsigned int n){
T0PR=15000000-1;
T0TCR=0x01;
while(T0TC<n);
T0TCR=0x03;
T0TCR=0x00;
}
void milliseconds(unsigned int n){
T0PR=15000-1;
T0TCR=0x01;
while(T0TC<n);
T0TCR=0x03;
T0TCR=0x00;
}
void microseconds(unsigned int n){
T0PR=15-1;
T0TCR=0x01;
while(T0TC<n);
T0TCR=0x03;
T0TCR=0x00;
}
