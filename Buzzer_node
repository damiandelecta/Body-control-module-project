#include<lpc21xx.h>
#include"can_header.h"
#define buzzer 1<<12
int main(){
can_msg m1;
IODIR0=buzzer;
IOCLR0=buzzer;
can_init();
while(1){
can_rx(&m1);
if(m1.id==0x250){
if(m1.byte==0){
IOSET0=buzzer;
}
else{
IOCLR0=buzzer;
}
}
}
}
