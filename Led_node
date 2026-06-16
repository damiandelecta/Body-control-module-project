#include<lpc21xx.h>
#include"can_header.h"
#define led 1<<13
int main(){
can_msg m1;
IODIR0=led;
IOSET0=led;
can_init();
while(1){
can_rx(&m1);
if(m1.id==0x150){
if(m1.byte==0){
IOCLR0=led;
}
else{
IOSET0=led;
}
}
}
}
