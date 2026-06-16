#include "lcd_data2.h"
#include "can_header.h"
#define sw1 14
#define sw2 15
#define sw3 16
int flag1=0;
int flag2=0;
int flag3=0;
int main(){
can_msg m1;
init();
string(" BODY CONTROL   MODULE");
delay(1);
command(0x01);
command(0x80);
string("LED");
command(0x84);
string("BUZZER");
command(0x8B);
string("WIPER");

can_init();
while(1){
//lednode
if(((IOPIN0>>sw1)&1)==0){ //if switch one pressed
milliseconds(300);//to avoid switch bounce
m1.id=0x150; //message id
m1.rtr=0; //data frame
m1.dlc=1; //one byte data
m1.byte=flag1;
can_tx(m1);//to transmit
if(flag1==0)
{
command(0xc0);
string("ON ");
}
else{
command(0xc0);
string("OFF");
}
flag1=!flag1;
}
//buzzer node
if(((IOPIN0>>sw2)&1)==0){
milliseconds(300);//to avoid switch bounce
m1.id=0x250;
m1.rtr=0;
m1.dlc=1;
m1.byte=flag2;
can_tx(m1);
if(flag2==0){
command(0xc6);
string("ON ");
}
else{
command(0xc6);
string("OFF");
}
flag2=!flag2;
}
//wiper node
if(((IOPIN0>>sw3)&1)==0){
milliseconds(300); //to avoid switch bounce
m1.id=0x350;
m1.rtr=0;
m1.dlc=1;
m1.byte=flag3;
can_tx(m1);
if(flag3==0){
command(0xca);
string("ON ");
}
else{
command(0xca);
string("OFF");
}
flag3=!flag3;
}
}
}
