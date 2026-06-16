#include<lpc21xx.h>
void can_init(void);
typedef struct can
{
unsigned int id;
unsigned int rtr;
unsigned int dlc;
unsigned int byte;
}can_msg;
void can_tx(can_msg);
void can_rx(can_msg*);
void can_init(void)
{
PINSEL1|=0x00014000;
VPBDIV=1;
C2MOD=0x1;
AFMR=0x2;
C2BTR=0x001C001D;
C2MOD=0x0;
}
void can_tx(can_msg m1)
{
C2TID1=m1.id;
C2TFI1=(m1.dlc<<16);
C2TFI1&=~(1<<30);
C2TDA1=m1.byte;
C2CMR=(1<<0)|(1<<5);
while((C2GSR&(1<<3))==0);
}
void can_rx(can_msg*m1){
while((C2GSR&0x1)==0);
m1->id=C2RID;
m1->dlc=(C2RFS>>16)&0xF;
m1->rtr=(C2RFS>>30)&0x1;
m1->byte=C2RDA;
C2CMR=(1<<2);
}
