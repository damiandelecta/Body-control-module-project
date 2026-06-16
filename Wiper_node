#include<lpc21xx.h>
#include"can_header.h"
#define wiper 1<<11
int main(){
can_msg m1;
IODIR0=wiper;
IOCLR0=wiper;
can_init();
while(1){
can_rx(&m1);
if(m1.id==0x350){
if(m1.byte==0){
IOSET0=wiper;
}
else{
IOCLR0=wiper;
}
}
}
}
